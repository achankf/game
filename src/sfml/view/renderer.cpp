#include "base/model/map.h"
#include "base/model/game.h"
#include "base/control/cursor.h"
#include "sfml/view/renderer.h"
#include <ncurses.h>
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

Renderer::~Renderer() {
}

sf::RenderWindow &Renderer::getWindow() {
	return this->window;
}

void Renderer::renderMap(::Base::Model::Game &game) {
	const auto &map = game.getMap();
	const auto dim = this->window.getSize();
	const int dlength = dim.x;
	const int dwidth = dim.y;
	const int hfit = std::min(dlength / edge_twice + 1, map.getLength());
	const int vfit = std::min(dwidth / edge_with_half + 1, map.getWidth());

	for (int i = 0; i < hfit; i++) {
		for (int j = 0; j < vfit; j++) {
			const int x = i - j / 2 - 1;
			const int y = j;
			this->renderTerrain(game, x, y);
		}
	}
}

void Renderer::renderTerrain(::Base::Model::Game &game, int i, int j) {

	const auto &map = game.getMap();
	const int newi = i * edge_twice + j * edge;
	const int newj = j * edge_with_half - edge_half;
	auto val = map.getHeight(i,j);
	int r,b,g;
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

	int newi = x * edge_twice + y * edge;
	int newj = y * edge_with_half - edge_half;

	int r,b,g;
	r = g = b = 0x00;

	hexagon.setPosition(newi, newj);
	hexagon.setFillColor(sf::Color(r,g,b));
	window.draw(hexagon);
}

void Renderer::toggleWorldMap() {
	this->worldmap.toggle();
}

void Renderer::renderAll(::Base::Model::Game &game) {
	game.updateAllViews(*this);
}

void Renderer::renderUI(::Base::Model::Game &game) {
	(void) game;
}
