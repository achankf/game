#ifndef _gamedb_hpp_
#define _gamedb_hpp_

#include "db_sqlite.hpp"
#include "type.hpp"

namespace SQL {
enum Query {
	//PLAYER_EXISTS,
	NEW_PLAYER,
	//NEW_CREATURE,
	UID_TO_PID,
	NUM_QUERIES
};
}

class GameDB : public SQLite3Database {
	const char *mapping[SQL::NUM_QUERIES] = {nullptr};
	sqlite3_stmt *stmts[SQL::NUM_QUERIES] = {nullptr};

	void setupMappings();
protected:
	int reset(SQL::Query id);
	int reprepare(SQL::Query id);
	int clearBindings(SQL::Query id);
public:
	GameDB(const char *file);
	virtual ~GameDB();

	id_type getUserID(const char *uid);
};

#endif
