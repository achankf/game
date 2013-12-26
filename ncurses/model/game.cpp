#include "ncurses/model/game.h"
#include "base/view/renderer.h"
using namespace Rendering;

GameNCurses::GameNCurses(int argc, char **argv, RandGen<int> &rando, ::Rendering::Renderer &renderer, ::Base::Model::Map &map) :
	Game(argc, argv, rando, map), Renderable(renderer) {
}

void GameNCurses::render() {
}
