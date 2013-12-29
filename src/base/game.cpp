#include "base/model/game.h"
#include "base/model/map.h"
#include "base/view/renderer.h"
#include "gamedb.h"
using namespace Base::Model;

Game::Game()
	: rando(), db("save.db"), map(rando.next()) {
	this->add_view(map);
}

id_type Game::get_userid(const char *uid) {
	return this->db.get_userid(uid);
}

const Map &Game::get_map() const {
	return this->map;
}

void Game::add_view(::Base::View::Renderable &view) {
	view_lst.push_back(&view);
}

void Game::update_all_views(::Base::View::Renderer &renderer) {
	for (auto &view_ptr : this->view_lst)
		view_ptr->render(*this, renderer);
}
