#include <cstring>
#include <iostream>
#include <cassert>
#include "gamedb.h"
#include "invalid_arg.h"

namespace SQL {
//const char *player_exists = "select exists (select * from player where uid = ?)";
const char *new_player = "insert into player (uid) values (?)";
//const char *new_creature = "insert into creature (type) values (?)";
const char *uid_to_pid = "select pid from player where uid = ?";
}

static void finalizeAll(sqlite3_stmt **stmts) {
	for (int i = 0; i < SQL::NUM_QUERIES; i++)
		sqlite3_finalize(stmts[i]);
}

void GameDB::setupMappings() {
	using namespace SQL;
	//this->mapping[PLAYER_EXISTS] = player_exists;
	this->mapping[NEW_PLAYER] = new_player;
	//this->mapping[NEW_CREATURE] = new_creature;
	this->mapping[UID_TO_PID] = uid_to_pid;
}

GameDB::GameDB(const char *file)
	: SQLite3Database(file) {

	this->setupMappings();

	for (int i = 0; i < SQL::NUM_QUERIES; i++) {
		size_t length = strlen(this->mapping[i]) + 1;
		int rv = sqlite3_prepare_v2(this->get_handle(), this->mapping[i], length, &this->stmts[i], nullptr);

		/* cannot initialize one of the statements */
		if (rv) {
			finalizeAll(this->stmts);
			std::cerr << "Cannot initialize queries" << std::endl;
			throw std::exception();
		}
	}
}

GameDB::~GameDB() {
	finalizeAll(this->stmts);
}

int GameDB::reset(SQL::Query id) {
	return sqlite3_reset(stmts[id]);
}

int GameDB::clearBindings(SQL::Query id) {
	return sqlite3_clear_bindings(stmts[id]);
}

int GameDB::reprepare(SQL::Query id) {
	int rv = this->reset(id);
	if (rv) return rv;
	return this->clearBindings(id);
}

id_type GameDB::getUserID(const char *uid) {

	if (uid == NULL) {
		std::cout << "Empty user name" << std::endl;
		throw InvalidArg();
	}

	size_t len = strlen(uid);

	if (len > 10) {
		std::cout << "User name longer than 10 characters" << std::endl;
		throw InvalidArg();
	}

	int rv = this->reprepare(SQL::UID_TO_PID);
	if (rv) throw std::exception();

	SQLite3Transaction trans(*this);

	sqlite3_stmt *stmt = this->stmts[SQL::UID_TO_PID];
	rv = sqlite3_bind_text(stmt, 1, uid, len, SQLITE_TRANSIENT);
	if (rv) throw std::exception();

	rv = sqlite3_step(stmt);

	if (rv == SQLITE_ROW) return sqlite3_column_int(stmt, 0);

	this->reprepare(SQL::NEW_PLAYER);
	stmt = this->stmts[SQL::NEW_PLAYER];
	sqlite3_bind_text(stmt, 1, uid, len, SQLITE_TRANSIENT);
	rv = sqlite3_step(stmt);

	assert(rv == SQLITE_DONE);

	return sqlite3_last_insert_rowid(this->db);
}
