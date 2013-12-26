#ifndef _game_null_h_
#define _game_null_h_

#include "../../base/model/game.h"
#include "../../base/view/renderable.h"

class Map;

namespace Null {

namespace View {
class Renderer;
}

namespace Model {

class Map;

class Game : public ::Base::Model::Game {

public:
	Game (int argc, char **argv, RandGen<int> &rando, ::Null::View::Renderer &renderer, ::Null::Model::Map &map);

	void render() {}
};

}
}
#endif
