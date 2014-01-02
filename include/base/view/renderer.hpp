#ifndef _base_renderer_hpp_
#define _base_renderer_hpp_

#include "type.hpp"

namespace Base {
namespace Model {
class Game;
}

namespace Control {
class Controller;
class Cursor;
}

namespace View {

class Renderer {
protected:
	virtual void renderTerrain(::Base::Model::Game &game, int i, int j) = 0;
public:
	virtual ~Renderer();
	virtual void renderMap(::Base::Model::Game &game) = 0;
	virtual void renderCursor(
	    ::Base::Model::Game &game,
	    ::Base::Control::Cursor &cursor) = 0;
	virtual void renderAll(
	    ::Base::Model::Game &game,
	    ::Base::Control::Controller &controller);
};

}
}
#endif
