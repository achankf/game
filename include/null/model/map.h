#ifndef _map_null_h_
#define _map_null_h_

#include "../../base/model/map.h"
#include "../../base/view/renderable.h"

namespace Rendering {
//namespace Null {
//namespace View {

class MapNull : public ::Base::Model::Map, public ::Base::View::Renderable {
public:
	MapNull(::Base::View::Renderer &renderer, int seed);
	void render() {}
};

//}
}
#endif
