#include "base/view/renderer.h"
#include "null/model/map.h"
using namespace Rendering;

MapNull::MapNull(Renderer &renderer, int seed)
	: Map(seed), Renderable(renderer) {
	renderer.set(MAP, *this);
}
