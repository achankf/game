#ifndef _base_controller_h_
#define _base_controller_h_

namespace Rendering {
class Renderer;
}

namespace Base {

namespace Model {
class Game;
class Map;
class Player;
}

namespace Control {

class Controller {
protected:
	::Base::Model::Game &game;
	::Base::View::Renderer &renderer;

public:
	Controller(
	    ::Base::Model::Game &game,
	    ::Base::View::Renderer &renderer)
		: game(game), renderer(renderer) {}
	virtual ~Controller() {}
	virtual void event_loop(
	    ::Base::Model::Player &player
	) = 0;
};

}
}
#endif
