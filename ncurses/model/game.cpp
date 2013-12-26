#include "ncurses/model/game.h"
#include "base/view/renderer.h"
using namespace NCurses::Model;

GameNCurses::GameNCurses(int argc, char **argv, RandGen<int> &rando, ::Base::View::Renderer &renderer, ::Base::Model::Map &map) :
	::Base::Model::Game(argc, argv, rando, map), ::Base::View::Renderable(renderer) {
}

void GameNCurses::render() {
}
