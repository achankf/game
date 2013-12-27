#ifndef _renderer_null_h_
#define _renderer_null_h_

#include "../../type.h"
#include "../../base/view/renderer.h"

namespace Base {
namespace Model {
class Map;
}
}

namespace Null {
namespace View {

class Renderer : public ::Base::View::Renderer {

public:
	Renderer () {}
	virtual ~Renderer() {}
	void render_all() {}
	void render_terrain(::Base::Model::Map &map, int i, int j, scalar_t x, scalar_t y);
};

}
}
#endif
