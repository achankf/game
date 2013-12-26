#include "renderer.h"
#include "game.h"
#include "map.h"
#include "renderable.h"
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
