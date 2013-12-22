#ifndef _map_ncurses_h_
#define _map_ncurses_h_

#include "map.h"

namespace Rendering {

class MapNCurses : public Map {
public:
	MapNCurses(Renderer &renderer, int seed) : Map(renderer, seed) {}
	void render();
};

}
#endif
