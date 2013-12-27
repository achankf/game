#include "base/model/map.h"
#include "ncurses/view/renderer.h"
#include "ncurses/model/game.h"
#include "ncurses/model/map.h"
#include <ncurses.h>
#include <iostream>
using namespace NCurses::View;

Renderer::Renderer(){
	int rv = 0;

	initscr();
	if(has_colors() == FALSE) {
		endwin();
		std::cerr << "Your terminal does not support color" << std::endl;
		throw std::bad_alloc();
	}

	start_color();
	rv |= init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
	rv |= init_pair(RED, COLOR_RED, COLOR_BLACK);
	rv |= init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	rv |= init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
	rv |= init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
	rv |= init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
	if (rv) {
		std::cerr << "Something is wrong with the colours" << std::endl;
		throw std::bad_alloc();
	}
}

Renderer::~Renderer() {
	endwin();
}

void Renderer::render_all() {
#ifndef NDEBUG
	for (int i = 0; i < NUM_RANDERABLES; i++) {
		assert(render_lst[i] != nullptr);
	}
#endif

	for (int i = 0; i < NUM_RANDERABLES; i++) {
		//if (!this->render_lst[i]) continue;
		this->render_lst[i]->render(*this);
	}
}

void Renderer::set_renderable(
	RenderableType type,
	::Base::View::Renderable<Renderer> &renderable) {
	this->render_lst[type] = &renderable;
}

void Renderer::render_terrain(::Base::Model::Map &map, int i, int j, scalar_t x, scalar_t y){
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
			mvwprintw(stdscr, y, x, "%c ", 254);
			attroff(COLOR_PAIR(colour));
}
