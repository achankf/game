#ifndef _map_h_
#define _map_h_

#include <noise/noise.h>
#include "renderable.h"

namespace Rendering {

class Renderer;

enum {MAP_LENGTH = 128, MAP_WIDTH = 40};

class Map : public Renderable {
	noise::module::Perlin perlin;

public:
	Map(Renderer&, int seed);
	double getBaseTile(double x, double y, double z = 0.1);
};

}
#endif
