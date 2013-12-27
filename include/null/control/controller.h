#ifndef _controller_null_h_
#define _controller_null_h_

#include "../../base/control/controller.h"

namespace Base {
namespace Model {
class Player;
}
}

namespace Null {

namespace View {
class Renderer;
}

namespace Model {
class Map;
class Game;
}

namespace Control {

class Controller : public ::Base::Control::Controller {

public:
	Controller(
	    ::Null::Model::Game &game,
	    ::Null::Model::Map &map,
	    ::Null::View::Renderer &renderer
	);
	void event_loop(
	    ::Base::Model::Player &player
	);
};

}
}
#endif
