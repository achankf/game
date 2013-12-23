#include "map.h"
using namespace Rendering;

Map::Map(Renderer &renderer, int seed) : Renderable(renderer) {
	perlin.SetSeed(seed);
	perlin.SetFrequency(0.15);
	perlin.SetFrequency(0.03);
	perlin.SetPersistence (0.5);
	perlin.SetPersistence (0.55);
}

double Map::getBaseTile(double x, double y, double z) {
	return perlin.GetValue(x,y,z);
}
