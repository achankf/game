#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "game.h"
#include "map.h"
#include "gamedb.h"

Game::Game(int argc, char **argv, RandGen<int> &rando, Map &map)
	: rando(rando), db("save.db") {
}

id_type Game::get_userid(const char *uid) {
	return this->db.get_userid(uid);
}
