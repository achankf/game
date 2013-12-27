#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "base/model/game.h"
#include "base/model/map.h"
#include "base/view/renderer.h"
#include "gamedb.h"
using namespace Base::Model;

Game::Game(int argc, char **argv)
	: rando(), db("save.db"), map(rando.next()) {
}

id_type Game::get_userid(const char *uid) {
	return this->db.get_userid(uid);
}

void Game::render(::Base::View::Renderer &renderer) {
	map.render(renderer);
}
