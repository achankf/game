#include "base/model/game.hpp"
#include "base/view/renderer.hpp"
#include "base/control/cursor.hpp"
#include "base/control/controller.hpp"
using namespace Base::Control;

Cursor::Cursor() : HexCoordinate(0,0,0) {}

Cursor::Cursor(scalar_t x, scalar_t y, scalar_t z)
	: HexCoordinate(x,y,z) {
}

void Cursor::render(
    ::Base::Model::Game &game,
    ::Base::View::Renderer &renderer,
    ::Base::Control::Controller &controller) {
	(void) controller;
	renderer.renderCursor(game, *this);
}
