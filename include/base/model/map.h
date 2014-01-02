#ifndef _map_h_
#define _map_h_

#include <noise/noise.h>
#include <utility>
#include "../view/renderable.h"

namespace Base {

namespace View {
class Renderer;
}

namespace Model {

class Game;

class Map : public ::Base::View::Renderable {
	noise::module::Perlin perlin;
	noise::model::Sphere world;
	const int length, width;

public:
	enum TileType {DEEP, SHALLOW, PLAIN, GRASS, HILL, SNOW};

	Map(int seed, int length, int width);
	double getHeight(int i, int j) const;
	int getLength() const;
	int getWidth() const;
	void render(::Base::Model::Game &game, ::Base::View::Renderer &renderer);
};

}
}
#endif
