#ifndef _controller_ncurses_h_
#define _controller_ncurses_h_

#include "../../control/controller.h"
#include "../../model/game.h"
#include "../model/map.h"
#include "../view/renderer.h"

namespace Control {

class NCurses : public Controller {

public:
	NCurses(Game &game, Map &map, Rendering::Renderer &renderer);
	void event_loop();
};

}
#endif
