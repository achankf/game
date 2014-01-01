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
protected:
	virtual void render_terrain(::Base::Model::Game &game, int i, int j) = 0;
public:
	virtual ~Renderer() {}
	virtual void render_map(::Base::Model::Game &game) = 0;
	virtual void render_cursor(::Base::Model::Game &game, ::Base::Control::Cursor &cursor) = 0;
};

}
}
#endif
