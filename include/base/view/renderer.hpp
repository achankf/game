#ifndef _base_renderer_hpp_
#define _base_renderer_hpp_

#include "type.hpp"
#include "base/model/hex.hpp"

constexpr int edge_half = 8;
constexpr int edge = edge_half * 2;
constexpr int edge_twice = edge * 2;
constexpr int edge_with_half = edge + edge_half;

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
	::Base::Model::HexCoordinate &getFocus();
};

}
}
#endif
