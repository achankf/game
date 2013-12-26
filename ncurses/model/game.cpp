#include "ncurses/model/game.h"
#include "ncurses/model/map.h"
#include "base/view/renderer.h"
using namespace NCurses::Model;

Game::Game(int argc, char **argv, RandGen<int> &rando,
           ::NCurses::View::Renderer &renderer,
           ::NCurses::Model::Map &map) :

	::Base::Model::Game(argc, argv, rando, renderer, map) {
}

void Game::render() {
}
