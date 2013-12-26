#ifndef _map_ncurses_h_
#define _map_ncurses_h_

#include "../view/renderer.h"
#include "../../base/model/map.h"
#include "../../base/view/renderable.h"

namespace NCurses{
namespace Model {

class Map : public ::Base::Model::Map, public ::Base::View::Renderable {
public:
	Map(::NCurses::View::Renderer &renderer, int seed);
	void render();
};

}
}
#endif
