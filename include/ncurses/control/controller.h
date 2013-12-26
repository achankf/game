#ifndef _controller_ncurses_h_
#define _controller_ncurses_h_

#include "../../base/control/controller.h"

namespace NCurses {

namespace View{
	class Renderer;
}

namespace Model{
	class Map;
	class Game;
}

namespace Control {

class Controller : public ::Base::Control::Controller {

public:
	Controller(::NCurses::Model::Game &game, ::NCurses::Model::Map &map, ::NCurses::View::Renderer &renderer);
	void event_loop();
};

}
}
#endif
