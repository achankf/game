#ifndef _renderer_ncurses_h_
#define _renderer_ncurses_h_

#include "../../base/view/renderer.h"
#include "../../base/view/renderable.h"
#include "../../type.h"

namespace Base {
namespace Model {
class Map;
}
}

namespace NCurses {
namespace View {

enum RenderableType {MAP,GAME,NUM_RANDERABLES};

class Renderer : public ::Base::View::Renderer {
public:
	enum Colour {GREEN = 1, BLUE, RED, CYAN, WHITE, YELLOW};
	Renderer();
	virtual ~Renderer();
	void render_terrain(::Base::Model::Map &map, int i, int j, scalar_t x, scalar_t y);
};

}
}
#endif
