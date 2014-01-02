#include "base/model/game.h"
#include "sfml/view/renderer.h"
#include "sfml/view/worldmap.h"
using namespace SFML::View;

WorldMap::WorldMap(::Base::Model::Game &game) {
	const auto &map = game.getMap();
	const int length = map.getLength();
	const int width = map.getWidth();
	buf = new sf::Uint8[length * width * 4];

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			int idx = (i + j * width) * 4;
			int r,g,b;
			const double val = map.getHeight(i,j);
			std::tie(r,g,b) = this->heightToColour(val);
			buf[idx] = r;
			buf[idx + 1] = g;
			buf[idx + 2] = b;
			buf[idx + 3] = 0xff;
		}
	}
	img.create(length, width, buf);
	tex.loadFromImage(img);
	spr.setTexture(tex);

	this->toggle(); // turn this view off
}

WorldMap::~WorldMap() {
	delete [] buf;
}

std::tuple<sf::Uint8, sf::Uint8, sf::Uint8> WorldMap::heightToColour(double height) const {
	int r, g, b;
	if (height < -0.95) r = 0x00, b = 0x60, g = 0x00;
	else if (height < -0.9) r = 0x00, b = 0x60, g = 0x00;
	else if (height < -0.7) r = 0x00, b = 0x80, g = 0x00;
	else if (height < -0.5) r = 0x00, b = 0xa0, g = 0x00;
	else if (height < -0.2) r = 0x00, b = 0xB0, g = 0x00;
	else if (height < 0.0) r = 0x00, b = 0xFF, g = 0x00;
	else if (height < 0.03) r = 0xbF, b = 0x00, g = 0xbF;
	else if (height < 0.3) r = 0x00, b = 0x00, g = 0x60;
	else if (height < 0.5) r = 0x80, b = 0x00, g = 0x80;
	else if (height < 0.7) r = 0x50, b = 0x50, g = 0x50;
	else if (height < 0.97) r = 0x20, b = 0x20, g = 0x20;
	else r = 0xff, b = 0xff, g = 0xff;
	return std::tuple<sf::Uint8,sf::Uint8,sf::Uint8>(r,g,b);
}

const sf::Sprite &WorldMap::getSprite() const {
	return this->spr;
}

void WorldMap::render(::Base::Model::Game &game, ::Base::View::Renderer &renderer) {
	(void)game;
	if (!this->show) return;
	Renderer &ren = static_cast<Renderer &>(renderer);
	ren.getWindow().draw(this->spr);
}
