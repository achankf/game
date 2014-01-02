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

void Game::addView(::Base::View::Renderable &view) {
	view_lst.push_back(&view);
}

void Game::updateAllViews(::Base::View::Renderer &renderer) {
	for (auto &view_ptr : this->view_lst)
		view_ptr->render(*this, renderer);
}
