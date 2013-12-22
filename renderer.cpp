#include "renderer.h"
#include "game.h"
#include "map.h"
#include "renderable.h"
#include "cassert"
using namespace Rendering;

void Renderer::render_all() {
	for (int i = 0; i < NUM_RANDERABLES; i++) {
		render_lst[i]->render();
	}
}
