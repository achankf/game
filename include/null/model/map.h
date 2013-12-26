#ifndef _map_null_h_
#define _map_null_h_

#include "../../model/map.h"
#include "../../view/renderable.h"

namespace Rendering {

class MapNull : public Map, public Renderable {
public:
	MapNull(Renderer &renderer, int seed);
	void render() {}
};

}
#endif
