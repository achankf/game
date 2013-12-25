#include <cstring>
#include <iostream>
#include <cassert>
#include "gamedb.h"
#include "invalid_arg.h"

namespace SQL {
const char *player_exists = "select exists (select * from player where uid = ?)";
const char *new_player = "insert into player (uid) values (?)";
const char *new_creature = "insert into creature (type) values (?)";
const char *uid_to_pid = "select pid from player where uid = ?";
}

static void finalize_all(sqlite3_stmt **stmts) {
	for (int i = 0; i < SQL::NUM_QUERIES; i++)
		sqlite3_finalize(stmts[i]);
}

void GameDB::setup_mappings() {
	using namespace SQL;
	this->mapping[PLAYER_EXISTS] = player_exists;
	this->mapping[NEW_PLAYER] = new_player;
	this->mapping[NEW_CREATURE] = new_creature;
	this->mapping[UID_TO_PID] = uid_to_pid;
}

GameDB::GameDB(const char *file)
	: SQLite3Database(file) {

	this->setup_mappings();

	for (int i = 0; i < SQL::NUM_QUERIES; i++) {
		size_t length = strlen(this->mapping[i]) + 1;
		int rv = sqlite3_prepare_v2(this->get_handle(), this->mapping[i], length, &this->stmts[i], nullptr);

		/* cannot initialize one of the statements */
		if (rv) finalize_all(this->stmts);
	}
}

GameDB::~GameDB() {
	finalize_all(this->stmts);
}

int GameDB::reset(SQL::Query id) {
	return sqlite3_reset(stmts[id]);
}

int GameDB::clear_bindings(SQL::Query id) {
	return sqlite3_clear_bindings(stmts[id]);
}

int GameDB::reprepare(SQL::Query id) {
	int rv = this->reset(id);
	if (rv) return rv;
	return this->clear_bindings(id);
}

id_type GameDB::get_userid(const char *uid) {

	if (uid == NULL) {
		std::cout << "Empty user name" << std::endl;
		throw InvalidArg();
	}

	size_t len = strlen(uid);

	if (len > 10) {
		std::cout << "User name longer than 10 characters" << std::endl;
		throw InvalidArg();
	}

	len++; // position of null character

	this->reprepare(SQL::UID_TO_PID);

	SQLite3Transaction trans(*this);

	sqlite3_stmt *stmt = this->stmts[SQL::UID_TO_PID];
	sqlite3_bind_text(stmt, 1, uid, len, SQLITE_TRANSIENT);

	int rv = sqlite3_step(stmt);

	if (rv == SQLITE_ROW) return sqlite3_column_int(stmt, 0);

	this->reprepare(SQL::NEW_PLAYER);
	stmt = this->stmts[SQL::NEW_PLAYER];
	sqlite3_bind_text(stmt, 1, uid, len, SQLITE_TRANSIENT);
	rv = sqlite3_step(stmt);

	assert(rv == SQLITE_DONE);

	return sqlite3_last_insert_rowid(this->db);
}
