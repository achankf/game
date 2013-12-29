#include "base/view/renderer.h"
#include "ncurses/control/cursor.h"
using namespace NCurses::Control;

Cursor::Cursor(scalar_t x, scalar_t y, scalar_t z)
	: coor_t(x,y,z) {
}

void Cursor::render(::Base::Model::Game &game, ::Base::View::Renderer &renderer) {
	(void)renderer;
	(void)game;
}
