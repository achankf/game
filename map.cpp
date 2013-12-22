#include "map.h"
using namespace Rendering;

Map::Map(Renderer &renderer, int seed) : Renderable(renderer) {
	perlin.SetSeed(seed);
}

double Map::getBaseTile(double x, double y, double z) {
	return perlin.GetValue(x,y,z);
}
