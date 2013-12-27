#ifndef _controller_ncurses_h_
#define _controller_ncurses_h_

#include "../../base/control/controller.h"

namespace Base {
namespace Model {
class Player;
class Map;
class Game;
}
}

namespace NCurses {

namespace View {
class Renderer;
}

namespace Control {

class Controller : public ::Base::Control::Controller {

public:
	Controller(
	    ::Base::Model::Game &game,
	    ::NCurses::View::Renderer &renderer
	);
	void event_loop(
	    ::Base::Model::Player &player
	);
};

}
}
#endif
