#include "base/model/map.hpp"
#include "base/model/game.hpp"
#include "base/control/cursor.hpp"
#include "sfml/view/renderer.hpp"
#include <iostream>
#include <algorithm>
#include <tuple>
#include <SFML/Graphics.hpp>
using namespace SFML::View;

static const int edge_half = 8;
static const int edge = edge_half * 2;
static const int edge_twice = edge * 2;
static const int edge_with_half = edge + edge_half;

Renderer::Renderer(::Base::Model::Game &game)
	: window(sf::VideoMode(1024, 768), "Game",
	         sf::Style::Default,
	         sf::ContextSettings(0,0,2)),
	worldmap(game) {

	window.setVerticalSyncEnabled(true);

	hexagon.setPointCount(6);
	hexagon.setPoint(0, sf::Vector2f(edge, 0));
	hexagon.setPoint(1, sf::Vector2f(edge_twice, edge_half));
	hexagon.setPoint(2, sf::Vector2f(edge_twice, edge_with_half));
	hexagon.setPoint(3, sf::Vector2f(edge, edge_twice));
	hexagon.setPoint(4, sf::Vector2f(0, edge_with_half));
	hexagon.setPoint(5, sf::Vector2f(0, edge_half));

	hexagon.setOutlineThickness(1);
	hexagon.setOutlineColor(sf::Color::Black);
}

sf::RenderWindow &Renderer::getWindow() {
	return this->window;
}

void Renderer::renderMap(::Base::Model::Game &game) {
	const auto &map = game.getMap();
	const auto dim = this->window.getSize();
	const int dlength = dim.x;
	const int dwidth = dim.y;
	const int hfit = std::min(dlength / edge_twice + 2, map.getLength());
	const int vfit = std::min(dwidth / edge_with_half + 2, map.getWidth());

	for (int i = 0; i < hfit; i++) {
		for (int j = 0; j < vfit; j++) {
			const int x = i - j / 2 - 1;
			const int y = j;
			this->renderTerrain(game, x, y);
		}
	}
}

void Renderer::renderTerrain(::Base::Model::Game &game, int i, int j) {

	int startx = 20;
	int starty = 100;

	const auto &map = game.getMap();
	const int newi = i * edge_twice + j * edge;
	const int newj = j * edge_with_half - edge_half;
	auto val = map.getHeight(i + startx,j + starty);
	sf::Uint8 r,g,b;
	std::tie(r,g,b) = this->worldmap.heightToColour(val);
	hexagon.setPosition(newi, newj);
	hexagon.setFillColor(sf::Color(r,g,b));
	window.draw(hexagon);
}

void Renderer::renderCursor(
    ::Base::Model::Game &game,
    ::Base::Control::Cursor &cursor) {

	(void) game;
	scalar_t x,y,z;
	std::tie(x,y,z) = cursor;

	const int newi = x * edge_twice + y * edge;
	const int newj = y * edge_with_half - edge_half;

	sf::Uint8 r,g,b;
	r = g = b = 0x00;

	hexagon.setPosition(newi, newj);
	hexagon.setFillColor(sf::Color(r,g,b));
	window.draw(hexagon);
}

void Renderer::toggleWorldMap() {
	this->worldmap.toggle();
}
