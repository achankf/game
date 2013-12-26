#ifndef _game_null_h_
#define _game_null_h_

#include "../../base/model/game.h"
#include "../../base/view/renderable.h"

class Map;

namespace Null {
namespace Model {

class GameNull : public ::Base::Model::Game, public ::Base::View::Renderable {

public:
	GameNull(int argc, char **argv, RandGen<int> &rando, ::Base::View::Renderer &renderer, ::Base::Model::Map &map) :
		Game(argc, argv, rando, map), ::Base::View::Renderable(renderer) {
	}

	void render() {}
};

}
}
#endif
