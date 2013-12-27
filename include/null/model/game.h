#ifndef _game_null_h_
#define _game_null_h_

#include "../../base/model/game.h"
#include "../../base/view/renderable.h"

class Map;

namespace Null {

namespace Model {

class Map;

class Game : public ::Base::Model::Game {

public:
	Game (int argc, char **argv, RandGen<int> &rando, Map &map);

	void render() {}
};

}
}
#endif
