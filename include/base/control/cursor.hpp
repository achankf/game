#ifndef _base_cursor_hpp_
#define _base_cursor_hpp_

#include "base/model/hex.hpp"
#include "base/view/renderable.hpp"

namespace Base {

namespace Control {

class Cursor : public ::Base::Model::HexCoordinate, public ::Base::View::Renderable {
public:
	Cursor();
	Cursor(scalar_t x, scalar_t y, scalar_t z);
	void render(
	    ::Base::Model::Game &game,
	    ::Base::View::Renderer &renderer,
	    ::Base::Control::Controller &controller);
};

}
}

#endif
