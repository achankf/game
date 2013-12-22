#ifndef _game_ncurses_h_
#define _game_ncurses_h_

#include "game.h"

namespace Rendering {

class GameNCurses : public Game {

public:
	GameNCurses(int argc, char **argv, Renderer &renderer) :
		Game(argc, argv, renderer) {
	}

	void render();
};

}

#endif
