#ifndef _game_ncurses_h_
#define _game_ncurses_h_

#include "../../base/model/game.h"
#include "../../base/view/renderable.h"
#include "../../randgen.h"

namespace NCurses {
namespace Model {

class GameNCurses : public Base::Model::Game, public ::Base::View::Renderable {

public:
	GameNCurses(int argc, char **argv, RandGen<int> &rando, ::Base::View::Renderer &renderer, ::Base::Model::Map &map);

	void render();
};

}
}

#endif
