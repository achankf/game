#include "null/map.h"
#include "renderer.h"
using namespace Rendering;

MapNull::MapNull(Renderer &renderer, int seed)
	: Map(seed), Renderable(renderer) {
	renderer.set(MAP, *this);
}
