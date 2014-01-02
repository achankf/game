#ifndef _base_controller_h_
#define _base_controller_h_

#include "base/view/renderable.h"
#include "cursor.h"

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
	virtual void event_loop(
	    ::Base::Model::Player &player
	) = 0;
};

}
}
#endif
