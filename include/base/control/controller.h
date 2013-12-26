#ifndef _base_controller_h_
#define _base_controller_h_

class Game;
class Map;
namespace Rendering {
class Renderer;
}

namespace Base{
namespace Control {

class Controller {
protected:
	Game &game;
	Map &map;
	Rendering::Renderer &renderer;

public:
	Controller(Game &game, Map &map, Rendering::Renderer &renderer)
		: game(game), map(map), renderer(renderer) {}
	virtual ~Controller() {}
	virtual void event_loop() = 0;
};

}
}
#endif
