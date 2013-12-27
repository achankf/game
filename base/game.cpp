#include "base/model/game.h"
#include "base/model/map.h"
#include "gamedb.h"
using namespace Base::Model;

Game::Game()
	: rando(), db("save.db"), map(rando.next()) {
	this->add_view(map);
}

id_type Game::get_userid(const char *uid) {
	return this->db.get_userid(uid);
}
