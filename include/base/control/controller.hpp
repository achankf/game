#ifndef _base_controller_hpp_
#define _base_controller_hpp_

#include "base/view/renderable.hpp"
#include "cursor.hpp"

namespace Base {

namespace Model {
class Map;
class Player;
}

namespace Control {

class Controller : public ::Base::View::RenderableList {
protected:
	::Base::Model::Game &game;
	::Base::View::Renderer &renderer;
	::Base::Control::Cursor cursor;

public:
	Controller(
	    ::Base::Model::Game &game,
	    ::Base::View::Renderer &renderer)
		: game(game), renderer(renderer) {}
	virtual ~Controller() {}
	virtual void eventLoop(::Base::Model::Player &player) = 0;
};

}
}
#endif
