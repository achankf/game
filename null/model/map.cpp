#include "base/view/renderer.h"
#include "null/model/map.h"
using namespace Rendering;

MapNull::MapNull(::Base::View::Renderer &renderer, int seed)
	: Map(seed), Renderable(renderer) {
}
