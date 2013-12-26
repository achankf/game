#include "null/model/map.h"
#include "null/view/renderer.h"
using namespace Null::Model;

Map::Map(Null::View::Renderer &renderer, int seed)
	: Base::Model::Map(renderer, seed) {
}

void Map::render() {}
