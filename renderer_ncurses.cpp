#include "renderer_ncurses.h"
#include "game_ncurses.h"
#include "map_ncurses.h"
#include <ncurses.h>
#include <iostream>
using namespace Rendering;

RendererNCurses::RendererNCurses() {
	int rv = 0;

	initscr();
	if(has_colors() == FALSE) {
		endwin();
		std::cout << "Your terminal does not support color" << std::endl;
		throw std::bad_alloc();
	}

	start_color();
	rv |= init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
	rv |= init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	rv |= init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
	rv |= init_pair(LIGHT_GREEN, COLOR_GREEN, COLOR_WHITE);
	if (rv) {
		std::cout << "Something is wrong with the colours" << std::endl;
		throw std::bad_alloc();
	}
}

RendererNCurses::~RendererNCurses() {
	endwin();
}
