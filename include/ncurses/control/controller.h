#ifndef _controller_ncurses_h_
#define _controller_ncurses_h_

#include "../../base/control/controller.h"
#include "../../base/control/cursor.h"
#include "type.h"

namespace NCurses {

namespace Control {

class Controller : public ::Base::Control::Controller {
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
