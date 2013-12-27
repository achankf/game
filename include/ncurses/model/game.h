#ifndef _game_ncurses_h_
#define _game_ncurses_h_

#include "../view/renderer.h"
#include "../../base/model/game.h"
#include "../../base/view/renderable.h"
#include "../../randgen.h"

namespace NCurses {

namespace Model {

class Map;

class Game : public Base::Model::Game, 
	public Base::View::Renderable<NCurses::View::Renderer> {

public:
	Game(int argc, char **argv, RandGen<int> &rando, ::NCurses::Model::Map &map);

	void render(NCurses::View::Renderer &renderer);
};

}
}

#endif
