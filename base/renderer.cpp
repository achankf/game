#include "model/game.h"
#include "model/map.h"
#include "view/renderer.h"
#include "view/renderable.h"
#include "cassert"
using namespace Rendering;

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
