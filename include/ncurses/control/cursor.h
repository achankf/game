#ifndef _cursor_ncurses_h_
#define _cursor_ncurses_h_

#include "../../base/view/renderable.h"

namespace Base{
	namespace View{
	class Renderer;
	}
}

namespace NCurses{

namespace Control{

class Cursor : public coor_t, public ::Base::View::Renderable {
public:
	Cursor(scalar_t x, scalar_t y, scalar_t z);
	void render(::Base::Model::Game &game, ::Base::View::Renderer &renderer);
};

}
}

#endif
