#ifndef _controller_ncurses_h_
#define _controller_ncurses_h_

#include "../../base/control/controller.h"
#include "type.h"

namespace Base {
namespace Model {
class Player;
class Map;
class Game;
}

namespace View {
class Renderer;
}

}

namespace NCurses {

namespace Control {

class Controller : public ::Base::Control::Controller {
protected:

public:
	Controller(
	    ::Base::Model::Game &game,
	    ::Base::View::Renderer &renderer
	);
	void event_loop(
	    ::Base::Model::Player &player
	);
	virtual ~Controller() {}
};

}
}
#endif
