#ifndef _controller_ncurses_h_
#define _controller_ncurses_h_

#include "controller.h"
#include "game.h"
#include "map.h"
#include "renderer.h"

namespace Control {

class NCurses : public Controller {

public:
	NCurses(Game &game, Map &map, Rendering::Renderer &renderer);
	void event_loop();
};

}
#endif
