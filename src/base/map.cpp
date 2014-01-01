#include "base/model/map.h"
#include "base/view/renderer.h"
using namespace Base::Model;

Map::Map(int seed, int length, int width)
	: length(length), width(width) {
	perlin.SetSeed(seed);
	perlin.SetFrequency(0.05);
	perlin.SetPersistence (0.55);
}

double Map::get_height(int i, int j) const{
	const double fac = 0.1;
	const double x = fac * i;
	const double y = fac * j;
	return this->perlin.GetValue(x,y,1);
}

int Map::getLength() const {
	return this->length;
}

int Map::getWidth() const {
	return this->width;
}

void Map::render(::Base::Model::Game &game, ::Base::View::Renderer &renderer) {
	renderer.render_map(game);
}
