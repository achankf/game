#include "base/view/renderer.h"
#include "base/view/renderable.h"
#include "cassert"
using namespace Base::View;

void Renderer::render_all() {
#ifndef NDEBUG
	for (int i = 0; i < NUM_RANDERABLES; i++) {
		assert(render_lst[i] != nullptr);
	}
#endif

	for (int i = 0; i < NUM_RANDERABLES; i++) {
		this->render_lst[i]->render();
	}
}

void Renderer::set(RenderableType type, Renderable &renderable) {
	this->render_lst[type] = &renderable;
}
