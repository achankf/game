#ifndef _cursor_ncurses_h_
#define _cursor_ncurses_h_

#include "../../base/view/renderable.h"

namespace Base {

namespace Control {

class Cursor : public coor_t, public ::Base::View::Renderable {
protected:
	scalar_t &get_x();
	scalar_t &get_y();
	scalar_t &get_z();
	void north();
	void south();
public:
	Cursor();
	Cursor(scalar_t x, scalar_t y, scalar_t z);
	void render(::Base::Model::Game &game, ::Base::View::Renderer &renderer);
	void east();
	void west();
	void north_east();
	void north_west();
	void south_east();
	void south_west();
};

}
}

#endif
