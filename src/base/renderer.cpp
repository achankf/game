#include "base/model/game.h"
#include "base/view/renderer.h"
#include "base/view/renderable.h"
#include "base/control/controller.h"
using namespace Base::View;

Renderer::~Renderer() {
}

void Renderer::renderAll(
    ::Base::Model::Game &game,
    ::Base::Control::Controller &controller) {
	game.updateAllViews(game, *this, controller);
	controller.updateAllViews(game, *this, controller);
}
