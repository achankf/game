#ifndef _game_null_h_
#define _game_null_h_

#include "../../base/model/game.h"
#include "../../base/view/renderable.h"

class Map;

namespace Rendering {

class GameNull : public Game, public Renderable {

public:
	GameNull(int argc, char **argv, RandGen<int> &rando, Renderer &renderer, Map &map) :
		Game(argc, argv, rando, map), Renderable(renderer) {
	}

	void render() {}
};

}

#endif
