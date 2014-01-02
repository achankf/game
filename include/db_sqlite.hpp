#ifndef _db_sqlite_hpp_
#define _db_sqlite_hpp_

#include <sqlite3.h>
#include "database.hpp"

class SQLite3Database {
protected:
	sqlite3 *db;
public:
	SQLite3Database(const char *file);
	virtual ~SQLite3Database();
	sqlite3 *get_handle();
};

class SQLite3Transaction : public Transaction {
	SQLite3Database &db;
	int commit();
public:
	SQLite3Transaction(SQLite3Database &db);
	~SQLite3Transaction();
	int rollback();
	bool hasAborted();
};
#endif
