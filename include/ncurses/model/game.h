#ifndef _game_ncurses_h_
#define _game_ncurses_h_

#include "../../base/model/game.h"
#include "../../base/view/renderable.h"
#include "../../randgen.h"

class Map;

namespace Rendering {

class GameNCurses : public Game, public Renderable {

public:
	GameNCurses(int argc, char **argv, RandGen<int> &rando, Renderer &renderer, Map &map);

	void render();
};

}

#endif
