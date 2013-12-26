#include "null/view/renderer.h"
#include "null/model/game.h"
#include "null/model/map.h"
using namespace Null::Model;

Game::Game(int argc, char **argv, RandGen<int> &rando,
	::Null::View::Renderer &renderer,
	::Null::Model::Map &map) :

	::Base::Model::Game(argc, argv, rando, map),
	::Base::View::Renderable(renderer) {
}
