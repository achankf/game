#include "base/model/game.h"
#include "base/view/renderable.h"
#include "base/view/renderer.h"
#include "base/control/controller.h"
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
