#ifndef _renderer_null_h_
#define _renderer_null_h_

#include "../../type.h"
#include "../../base/view/renderer.h"

namespace Base {
namespace Model {
class Game;
}
}

namespace Null {
namespace View {

class Renderer : public ::Base::View::Renderer {

public:
	Renderer () {}
	virtual ~Renderer() {}
	void render_terrain(::Base::Model::Game &game, int i, int j, scalar_t x, scalar_t y);
	void render_cursor(::Base::Model::Game &game, scalar_t x, scalar_t y);
};

}
}
#endif
