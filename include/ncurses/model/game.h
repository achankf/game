#ifndef _game_ncurses_h_
#define _game_ncurses_h_

#include "../../base/model/game.h"
#include "../../base/view/renderable.h"
#include "../../randgen.h"

namespace NCurses {

namespace View {
class Renderer;
}

namespace Model {

class Map;

class Game : public Base::Model::Game {

public:
	Game(int argc, char **argv, RandGen<int> &rando, ::NCurses::View::Renderer &renderer, ::NCurses::Model::Map &map);

	void render();
};

}
}

#endif
