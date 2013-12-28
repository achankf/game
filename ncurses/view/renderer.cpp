#include "base/model/map.h"
#include "ncurses/view/renderer.h"
#include <ncurses.h>
#include <iostream>
using namespace NCurses::View;

Renderer::Renderer() {
	int rv = 0;

	initscr();
	if(has_colors() == FALSE) {
		endwin();
		std::cerr << "Your terminal does not support color" << std::endl;
		throw std::bad_alloc();
	}

	start_color();
	rv |= init_pair(BLUE, COLOR_BLACK, COLOR_BLUE);
	rv |= init_pair(RED, COLOR_BLACK, COLOR_RED);
	rv |= init_pair(GREEN, COLOR_BLACK, COLOR_GREEN);
	rv |= init_pair(CYAN, COLOR_BLACK, COLOR_CYAN);
	rv |= init_pair(YELLOW, COLOR_BLACK, COLOR_YELLOW);
	rv |= init_pair(WHITE, COLOR_BLACK, COLOR_WHITE);
	if (rv) {
		std::cerr << "Something is wrong with the colours" << std::endl;
		throw std::bad_alloc();
	}
}

Renderer::~Renderer() {
	endwin();
}

void Renderer::render_terrain(::Base::Model::Map &map, int i, int j, scalar_t x, scalar_t y) {

	(void) i;
	(void) j;

	Colour colour;
	double val = map.getBaseTile(0.5 + x, 0.5 + y);

	switch (map.baseToTile(val)) {
	case ::Base::Model::Map::DEEP:
		colour = Renderer::BLUE;
		break;
	case ::Base::Model::Map::SHALLOW:
		colour = Renderer::CYAN;
		break;
	case ::Base::Model::Map::PLAIN:
		colour = Renderer::YELLOW;
		break;
	case ::Base::Model::Map::GRASS:
		colour = Renderer::GREEN;
		break;
	case ::Base::Model::Map::HILL:
		colour = Renderer::RED;
		break;
	case ::Base::Model::Map::SNOW:
		colour = Renderer::WHITE;
		break;
	default:
		assert("Invalid Tile Type" == nullptr); // aka fails
	}

	attron(COLOR_PAIR(colour));
	mvwprintw(stdscr, y, x, " ");
	attroff(COLOR_PAIR(colour));
}

void Renderer::render_cursor(::Base::Model::Map &map, scalar_t x, scalar_t y) {
	double val = map.getBaseTile(0.5 + x, 0.5 + y);
	Colour colour = tile_type_to_colour(map.baseToTile(val));
	attron(COLOR_PAIR(colour));
	mvwprintw(stdscr, y, x, " ");
	attroff(COLOR_PAIR(colour));
}

Renderer::Colour Renderer::tile_type_to_colour(::Base::Model::Map::TileType type) {
	switch (type) {
	case ::Base::Model::Map::DEEP:
		return Renderer::BLUE;
	case ::Base::Model::Map::SHALLOW:
		return Renderer::CYAN;
	case ::Base::Model::Map::PLAIN:
		return Renderer::YELLOW;
	case ::Base::Model::Map::GRASS:
		return Renderer::GREEN;
	case ::Base::Model::Map::HILL:
		return Renderer::RED;
	case ::Base::Model::Map::SNOW:
		return Renderer::WHITE;
	}
	std::cerr << "Invalid tile type" << std::endl;
	throw std::exception();
}
