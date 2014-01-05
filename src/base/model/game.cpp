#include "base/model/game.hpp"
#include "base/model/map.hpp"
#include "base/view/renderer.hpp"
#include "gamedb.hpp"
using namespace Base::Model;

enum Config {MAP_LENGTH = 700, MAP_WIDTH = 700};
//enum Config {MAP_LENGTH = 20, MAP_WIDTH = 20};

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
