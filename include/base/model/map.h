#ifndef _map_h_
#define _map_h_

#include <noise/noise.h>
#include "../view/renderable.h"

namespace Base {

namespace View {
class Renderer;
}

namespace Model {

class Game;

class Map : public ::Base::View::Renderable {
	noise::module::Perlin perlin;
	const int length, width;

public:
	enum Config {MAP_LENGTH = 70, MAP_WIDTH = 30};
	enum TileType {DEEP, SHALLOW, PLAIN, GRASS, HILL, SNOW};

	Map(int seed, int length = MAP_LENGTH, int width = MAP_WIDTH);
	double getBaseTile(double x, double y, double z = 100) const;

	int getLength();
	int getWidth();
	TileType baseToTile(double val) const;
	void render(::Base::Model::Game &game, ::Base::View::Renderer &renderer);
};

}
}
#endif
