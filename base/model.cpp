#include "base/view/renderer.h"
#include "base/model/model.h"
using namespace Base::Model;

void Model::add_view(::Base::View::Renderable &view) {
	view_lst.push_back(&view);
}

void Model::update_all_views(::Base::View::Renderer &renderer) {
	for (auto &view_ptr : this->view_lst)
		view_ptr->render(renderer);
}
