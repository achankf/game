#ifndef _renderer_h_
#define _renderer_h_

#include "../../type.h"

namespace Base {
namespace Model {
class Game;
}

namespace Control {
class Cursor;
}

namespace View {

class Renderer {
public:
	virtual ~Renderer() {}
	virtual void render_terrain(::Base::Model::Game &game, int i, int j, scalar_t x, scalar_t y) = 0;
	virtual void render_cursor(::Base::Model::Game &game, ::Base::Control::Cursor &cursor) = 0;
};

}
}
#endif
