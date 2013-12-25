#ifndef _map_null_h_
#define _map_null_h_

#include "map.h"
#include "renderable.h"

namespace Rendering {

class MapNull : public Map, public Renderable {
public:
	MapNull(Renderer &renderer, int seed) : Map(seed), Renderable(renderer) {}
	void render() {}
};

}
#endif
