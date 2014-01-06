#include "base/model/game.hpp"
#include "base/view/renderer.hpp"
#include "base/control/controller.hpp"
using namespace Base::View;

Renderer::Renderer() : focus(0,0,0) {
}

Renderer::~Renderer() {
}

void Renderer::renderAll(
    ::Base::Model::Game &game,
    ::Base::Control::Controller &controller) {
	game.updateAllViews(game, *this, controller);
	controller.updateAllViews(game, *this, controller);
}

::Base::Model::HexCoordinate &Renderer::getFocus() {
	return this->focus;
}

coor_t Renderer::normalize(scalar_t x, scalar_t y, scalar_t z) {
	scalar_t focusx, focusy ,focusz;
	std::tie(focusx, focusy, focusz) = this->focus;

	x -= focusx;
	y -= focusy;
	z -= focusz;
	return coor_t(x,y,z);
}

coor_t Renderer::normalize(::Base::Model::HexCoordinate &coor) {
	return this->normalize(coor.get_x(), coor.get_y(), coor.get_z());
}
