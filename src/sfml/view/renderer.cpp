#include "base/model/map.h"
#include "base/model/game.h"
#include "base/control/cursor.h"
#include "sfml/view/renderer.h"
#include <ncurses.h>
#include <iostream>
#include <tuple>
#include <SFML/Graphics.hpp>
using namespace SFML::View;

static const int edge_half = 8;
static const int edge = edge_half << 1;
static const int edge_twice = edge << 1;
static const int edge_with_half = edge + edge_half;

Renderer::Renderer() : window(sf::VideoMode(800, 600), "Game", sf::Style::Default, sf::ContextSettings(0,0,2)) {
	window.setVerticalSyncEnabled(true);

	hexagon.setPointCount(6);
	hexagon.setPoint(0, sf::Vector2f(edge, 0));
	hexagon.setPoint(1, sf::Vector2f(edge_twice, edge_half));
	hexagon.setPoint(2, sf::Vector2f(edge_twice, edge_with_half));
	hexagon.setPoint(3, sf::Vector2f(edge, edge_twice));
	hexagon.setPoint(4, sf::Vector2f(0, edge_with_half));
	hexagon.setPoint(5, sf::Vector2f(0, edge_half));

}

Renderer::~Renderer() {
}

sf::RenderWindow &Renderer::get_window() {
	return this->window;
}

void Renderer::render_terrain(::Base::Model::Game &game, int i, int j, scalar_t x, scalar_t y) {

	(void) game;
	(void) i;
	(void) j;
	(void) x;
	(void) y;

	int newi = i * edge_twice;
	int newj = j * edge_with_half - edge_half;

	const auto &map = game.get_map();
	auto height_pair = map.getHeightPair(x,y);
	double val = height_pair.first;//map.getBaseTile(x,y);

	int r,b,g;
	if (val < -0.95) r = 0x00, b = 0x60, g = 0x00;
	else if (val < -0.9) r = 0x00, b = 0x60, g = 0x00;
	else if (val < -0.7) r = 0x00, b = 0x80, g = 0x00;
	else if (val < -0.5) r = 0x00, b = 0xa0, g = 0x00;
	else if (val < -0.2) r = 0x00, b = 0xB0, g = 0x00;
	else if (val < -0.1) r = 0x00, b = 0xFF, g = 0x00;
	//else if (val < 0) r = 0xD3, b = 0xF0, g = 0xE7;
	else if (val < 0.3) r = 0x00, b = 0x00, g = 0x60;
	else if (val < 0.5) r = 0x80, b = 0x00, g = 0x80;
	else if (val < 0.7) r = 0x50, b = 0x50, g = 0x50;
	else if (val < 0.97) r = 0x20, b = 0x20, g = 0x20;
	else r = 0xff, b = 0xff, g = 0xff;

	if ((j % 2) == 1) newi -= edge;
	hexagon.setPosition(newi, newj);
	hexagon.setFillColor(sf::Color(r,g,b));
	window.draw(hexagon);
}

void Renderer::render_cursor(::Base::Model::Game &game, ::Base::Control::Cursor &cursor) {
	(void) game;
	(void) cursor;
	//const ::Base::Model::Map &map = game.get_map();

#if 0
	scalar_t x,y,z;
	std::tie(x,y,z) = cursor;

	double val = map.getBaseTile(x, y);
	Colour colour = tile_type_to_colour(map.baseToTile(val));
	attron(COLOR_PAIR(colour));
	mvwprintw(stdscr, y, x, "%c", 254);
	attroff(COLOR_PAIR(colour));
#endif
}
