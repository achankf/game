#ifndef _map_h_
#define _map_h_

#include <noise/noise.h>
#include <utility>
#include "../view/renderable.h"

namespace Base {

namespace Model {

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
	void render(
	    ::Base::Model::Game &game,
	    ::Base::View::Renderer &renderer,
	    ::Base::Control::Controller &controller);
};

}
}
#endif
