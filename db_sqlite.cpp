#include <iostream>
#include <cassert>
#include "db_sqlite.h"

SQLite3Transaction::SQLite3Transaction(SQLite3Database &db) : db(db) {

	sqlite3 *handle = (sqlite3*) this->db.get_handle();

	if (sqlite3_exec(handle, "begin", nullptr, nullptr, nullptr)) {
#ifndef NDEBUG
		std::cerr << "Cannot begin transaction" << std::endl;
#endif
		throw std::bad_alloc();
	}
}

int SQLite3Transaction::commit() {

	sqlite3 *handle = (sqlite3*) this->db.get_handle();

	int rv = sqlite3_exec(handle, "commit", nullptr, nullptr, nullptr);
	if (rv) {
#ifndef NDEBUG
		std::cerr << "Cannot commit transaction" << std::endl;
#endif
	}
	return rv;
}

int SQLite3Transaction::rollback() {

	sqlite3 *handle = (sqlite3*) this->db.get_handle();

	int rv = sqlite3_exec(handle, "commit", nullptr, nullptr, nullptr);
	if (rv) {
#ifndef NDEBUG
		std::cerr << "Cannot rollback transaction" << std::endl;
#endif
	}

	aborted = true;
	return rv;
}

bool SQLite3Transaction::hasAborted() {
	return !aborted;
}

SQLite3Transaction::~SQLite3Transaction() {
	if (hasAborted()) rollback();
	else commit();
}

SQLite3Database::SQLite3Database(const char *file) {
	int rv = sqlite3_open(file, &this->db);
	if (rv) {
		std::cerr << "Cannot open database file (reason:" << rv << ')' << std::endl;
		throw std::bad_alloc();
	}
}

SQLite3Database::~SQLite3Database() {
	sqlite3_close(this->db);
}

sqlite3 *SQLite3Database::get_handle() {
	return db;
}
