#ifndef _map_ncurses_h_
#define _map_ncurses_h_

#include "../../base/model/map.h"
#include "../../base/view/renderable.h"

namespace Rendering {

class MapNCurses : public Base::Model::Map, public Renderable {
public:
	MapNCurses(Renderer &renderer, int seed);
	void render();
};

}
#endif
