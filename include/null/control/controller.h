#ifndef _controller_null_h_
#define _controller_null_h_

#include "../../base/control/controller.h"

namespace Null {

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
};

}
}
#endif
