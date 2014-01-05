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
