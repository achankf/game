#include "base/model/map.h"
#include "base/view/renderer.h"
using namespace Base::Model;

Map::Map(int seed, int length, int width)
	: length(length), width(width) {
	perlin.SetSeed(seed);
	perlin.SetFrequency(0.5);
	perlin.SetPersistence (0.5);

	world.SetModule(perlin);
}

double Map::getHeight(int i, int j) const {
	const int noi = (i + this->length) % this->length;
	const int noj = (j + this->width) % this->width;
	const double lon = static_cast<double>(noi) / this->length * 360;
	const double lat = static_cast<double>(noj) / this->width * 360;
	return this->world.GetValue(lon,lat);
}

int Map::getLength() const {
	return this->length;
}

int Map::getWidth() const {
	return this->width;
}

void Map::render(::Base::Model::Game &game, ::Base::View::Renderer &renderer) {
	renderer.renderMap(game);
}
