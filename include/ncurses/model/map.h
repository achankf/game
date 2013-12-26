#ifndef _map_ncurses_h_
#define _map_ncurses_h_

#include "../../base/model/map.h"
#include "../../base/view/renderable.h"

namespace NCurses{
namespace Model {

class MapNCurses : public ::Base::Model::Map, public ::Base::View::Renderable {
public:
	MapNCurses(::Base::View::Renderer &renderer, int seed);
	void render();
};

}
}
#endif
