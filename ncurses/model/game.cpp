#include "ncurses/model/game.h"
#include "view/renderer.h"
using namespace Rendering;

GameNCurses::GameNCurses(int argc, char **argv, RandGen<int> &rando, Renderer &renderer, Map &map) :
	Game(argc, argv, rando, map), Renderable(renderer) {
}

void GameNCurses::render() {
}
