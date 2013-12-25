#ifndef _map_ncurses_h_
#define _map_ncurses_h_

#include "map.h"
#include "renderable.h"

namespace Rendering {

class MapNCurses : public Map, public Renderable {
public:
	MapNCurses(Renderer &renderer, int seed)
		: Map(seed), Renderable(renderer) {}
	void render();
};

}
#endif
