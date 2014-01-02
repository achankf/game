#include "base/model/game.h"
#include "base/model/map.h"
#include "base/view/renderer.h"
#include "gamedb.h"
using namespace Base::Model;

enum Config {MAP_LENGTH = 700, MAP_WIDTH = 700};

Game::Game()
	: rando(), db("save.db"), map(rando.next(), MAP_LENGTH, MAP_WIDTH) {
	this->addView(map);
}

id_type Game::getUserID(const char *uid) {
	return this->db.getUserID(uid);
}

const Map &Game::getMap() const {
	return this->map;
}
