#include "ncurses/renderer.h"
#include "ncurses/game.h"
#include "ncurses/map.h"
#include <ncurses.h>
#include <iostream>
using namespace Rendering;

RendererNCurses::RendererNCurses() {
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

RendererNCurses::~RendererNCurses() {
	endwin();
}
