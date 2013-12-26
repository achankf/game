#ifndef _base_controller_h_
#define _base_controller_h_

namespace Rendering {
class Renderer;
}

namespace Base{

namespace Model {
class Game;
class Map;
}

namespace Control {

class Controller {
protected:
	::Base::Model::Game &game;
	::Base::Model::Map &map;
	::Base::View::Renderer &renderer;

public:
	Controller(::Base::Model::Game &game, ::Base::Model::Map &map, ::Base::View::Renderer &renderer)
		: game(game), map(map), renderer(renderer) {}
	virtual ~Controller() {}
	virtual void event_loop() = 0;
};

}
}
#endif
