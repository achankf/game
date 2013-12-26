#include "null/model/map.h"
#include "null/view/renderer.h"
using namespace Null::Model;

Map::Map(Null::View::Renderer &renderer, int seed)
	: Base::Model::Map(seed), Base::View::Renderable(renderer) {
}

void Map::render(){}
