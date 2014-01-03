#ifndef _base_renderer_hpp_
#define _base_renderer_hpp_

#include "type.hpp"
#include "base/model/hex.hpp"

namespace Base {

namespace Control {
class Controller;
class Cursor;
}

namespace View {

class Renderer {
protected:
	::Base::Model::HexCoordinate focus;

	virtual void renderTerrain(::Base::Model::Game &game, int i, int j) = 0;
public:
	Renderer();
	virtual ~Renderer();
	virtual void renderMap(::Base::Model::Game &game) = 0;
	virtual void renderCursor(
	    ::Base::Model::Game &game,
	    ::Base::Control::Cursor &cursor) = 0;
	virtual void renderAll(
	    ::Base::Model::Game &game,
	    ::Base::Control::Controller &controller);
	bool inBound(scalar_t x, scalar_t y, scalar_t z) const;
	::Base::Model::HexCoordinate &getFocus();
};

}
}
#endif