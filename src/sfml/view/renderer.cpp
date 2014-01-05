#include "base/model/map.hpp"
#include "base/model/game.hpp"
#include "base/control/cursor.hpp"
#include "sfml/view/renderer.hpp"
#include <iostream>
#include <algorithm>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <cassert>
using namespace SFML::View;

Renderer::Renderer(::Base::Model::Game &game)
	: window(sf::VideoMode(1024, 768), "Game",
	         sf::Style::Default,
	         sf::ContextSettings(0,0,2)),
	worldmap(game) {

	static_assert(EDGE_HALF > 0 && EDGE > 0 && EDGE_TWICE > 0 && EDGE_WITH_HALF > 0, "Hexagon EDGE needs to be longer than 0");

	window.setVerticalSyncEnabled(true);

	hexagon.setPointCount(6);
	hexagon.setPoint(0, sf::Vector2f(EDGE, 0));
	hexagon.setPoint(1, sf::Vector2f(EDGE_TWICE, EDGE_HALF));
	hexagon.setPoint(2, sf::Vector2f(EDGE_TWICE, EDGE_WITH_HALF));
	hexagon.setPoint(3, sf::Vector2f(EDGE, EDGE_TWICE));
	hexagon.setPoint(4, sf::Vector2f(0, EDGE_WITH_HALF));
	hexagon.setPoint(5, sf::Vector2f(0, EDGE_HALF));

	hexagon.setOutlineThickness(1);
	hexagon.setOutlineColor(sf::Color::Black);

	const auto &map = game.getMap();
	this->length = map.getLength();
	this->width = map.getWidth();

	const auto dim = this->window.getSize();
	this->dlength = dim.x;
	this->dwidth = dim.y;

	this->hfit_tiles = std::min(dlength / EDGE_TWICE + 2, map.getLength());
	this->vfit_tiles = std::min(dwidth / EDGE_WITH_HALF + 2, map.getWidth());

	this->hfit = this->hfit_tiles * EDGE_TWICE;
	this->vfit = this->vfit_tiles * EDGE_WITH_HALF;
}

sf::RenderWindow &Renderer::getWindow() {
	return this->window;
}

void Renderer::renderMap(::Base::Model::Game &game) {
	for (int i = 0; i < this->hfit_tiles; i++) {
		for (int j = 0; j < this->vfit_tiles; j++) {
			const int x = i - j / 2 - 1;
			const int y = j;
			this->renderTerrain(game, x, y);
		}
	}
}

void Renderer::renderTerrain(::Base::Model::Game &game, int i, int j) {

	scalar_t focusx, focusy ,focusz;
	std::tie(focusx, focusy, focusz) = this->focus;

	const int newi = i * EDGE_TWICE + j * EDGE;
	const int newj = j * EDGE_WITH_HALF - EDGE_HALF;

	const auto &map = game.getMap();
	auto val = map.getHeight(i + focusx,j + focusy);

	sf::Uint8 r,g,b;
	std::tie(r,g,b) = this->worldmap.heightToColour(val);

	hexagon.setPosition(newi, newj);
	hexagon.setFillColor(sf::Color(r,g,b));
	window.draw(hexagon);
}

void Renderer::renderCursor(
    ::Base::Model::Game &game,
    ::Base::Control::Cursor &cursor) {

	scalar_t x,y,z;
	std::tie(x,y,z) = cursor;

	scalar_t focusx, focusy ,focusz;
	std::tie(focusx, focusy, focusz) = this->focus;

	x -= focusx;
	y -= focusy;
	z -= focusz;

	const auto &map = game.getMap();
	const scalar_t length = map.getLength();
	const scalar_t width = map.getWidth();
	if (x < 0) x += length;
	if (y < 0) y += width;

	coor_t pos;
	if (!this->inBound(game, pos, x, y)) return;

	std::tie(x,y,z) = pos;
	sf::Uint8 r,g,b;
	r = g = b = 0x00;

	hexagon.setFillColor(sf::Color(r,g,b));
	hexagon.setPosition(x, y);
	window.draw(hexagon);
}

void Renderer::toggleWorldMap() {
	this->worldmap.toggle();
}

bool Renderer::inBound(::Base::Model::Game &game, coor_t &normalized_result, scalar_t x, scalar_t y, scalar_t z) const {
#ifndef NDEBUG
	if (z != -1) {
		std::cerr << "SFML::View::Renderer::inBound: z is not being used yet" << std::endl;
		assert(false);
	}
#endif

std::cout << x << ' ' << y << ' ' << z << std::endl;

	(void) game;

	/* Check whether y coordinate is in-bound */
	const int newy = y * EDGE_WITH_HALF - EDGE_HALF;
	if (newy < -EDGE_HALF || newy > this->vfit) return false;

	/* Check whether x coordinate is in-bound */
	const int newx1 = x * EDGE_TWICE + y * EDGE;
	const int newx2 = (x - length) * EDGE_TWICE + y * EDGE;

	int finx;
	if (newx1 >= 0 && newx1 <= this->hfit) finx = newx1;
	else if (newx2 >= 0 && newx2 <= this->hfit) finx = newx2;
	else return false;

	normalized_result = coor_t(finx, newy, std::get<2>(normalized_result));
	return true;
}
