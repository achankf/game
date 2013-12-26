#include "null/model/map.h"
#include "view/renderer.h"
using namespace Rendering;

MapNull::MapNull(Renderer &renderer, int seed)
	: Map(seed), Renderable(renderer) {
	renderer.set(MAP, *this);
}
