#include "null/model/game.h"
using namespace Null::Model;

	Game::Game (int argc, char **argv, RandGen<int> &rando, ::Null::View::Renderer &renderer, ::Null::Model::Map &map) :
		Game(argc, argv, rando, map), ::Base::View::Renderable(renderer) {
	}
