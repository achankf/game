#ifndef _map_null_h_
#define _map_null_h_

#include "../../base/model/map.h"
#include "../../base/view/renderable.h"

namespace Null {

namespace View{
	class Renderer;
}

namespace Model {

class Map : public ::Base::Model::Map, public ::Base::View::Renderable {
public:
	Map(::Null::View::Renderer &renderer, int seed);
	void render();
};

}
}
#endif
