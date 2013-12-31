#include "base/model/map.h"
#include "base/view/renderer.h"
using namespace Base::Model;

Map::Map(int seed, int length, int width)
	: length(length), width(width) {
	perlin.SetSeed(seed);
	perlin.SetFrequency(0.05);
	perlin.SetPersistence (0.55);
}

double Map::getBaseTile(double x, double y, double z) const {
	return this->perlin.GetValue(x,y,z);
}

int Map::getLength() {
	return this->length;
}

int Map::getWidth() {
	return this->width;
}

Map::TileType Map::baseToTile(double val) const {
	if (val < -0.1) return DEEP;
	else if (val < 0) return SHALLOW;
	else if (val < 0.25) return GRASS;
	else if (val < 0.6) return PLAIN;
	else if (val < 0.9) return HILL;
	else return SNOW;
}

void Map::render(::Base::Model::Game &game, ::Base::View::Renderer &renderer) {
	for (int i = 0; i < this->getLength(); i++) {
		for (int j = 0; j < this->getWidth(); j++) {
			renderer.render_terrain(game, i,j,i, j);
		}
	}
}

std::pair<double, double> Map::getHeightPair(double x, double y, double z) const {
	double val = this->perlin.GetValue(x,y,z);
	TileType tt;
	if (val < -0.1) tt = DEEP;
	else if (val < 0) tt = SHALLOW;
	else if (val < 0.6) tt = GRASS;
	else tt = HILL;
	return std::pair<double,double>(val,tt);
}
