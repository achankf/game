#ifndef _controller_ncurses_h_
#define _controller_ncurses_h_

#include "../../base/control/controller.h"
#include "../../base/model/game.h"
#include "../model/map.h"
#include "../view/renderer.h"

namespace NCurses {
namespace Control {

class Controller : public ::Base::Control::Controller {

public:
	Controller(Game &game, Map &map, Rendering::Renderer &renderer);
	void event_loop();
};

}
}
#endif
