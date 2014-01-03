#include "base/model/game.hpp"
#include "base/view/renderable.hpp"
#include "base/view/renderer.hpp"
#include "base/control/controller.hpp"
using namespace Base::View;

void RenderableList::addView(::Base::View::Renderable &view) {
	view_lst.push_back(&view);
}

void RenderableList::updateAllViews(
    ::Base::Model::Game &game,
    ::Base::View::Renderer &renderer,
    ::Base::Control::Controller &controller) {
	for (auto &view_ptr : this->view_lst)
		view_ptr->render(game, renderer, controller);
}

RenderableList::~RenderableList() {
}

::Base::Model::HexCoordinate &Renderer::getFocus() {
	return this->focus;
}

bool Renderer::inBound(scalar_t x, scalar_t y, scalar_t z) const {
	(void) x;
	(void) y;
	(void) z;
	return true;
}
