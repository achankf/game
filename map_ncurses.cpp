#include "map_ncurses.h"
#include "renderer_ncurses.h"
#include <ncurses.h>
using namespace Rendering;

void MapNCurses::render() {
	for (int i = 0; i < MAP_LENGTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {

			double val = this->getBaseTile(i,j);
			//int k = i + j;
			int k = i;

			int colour;
			(void)colour;
			if (val < -0.1) colour = BLUE;
			else if (val < 0) colour = CYAN;
			else if (val < 0.25) colour = YELLOW;
			else if (val < 0.6) colour = GREEN;
			else if (val < 0.9) colour = RED;
			else colour = WHITE;

			attron(COLOR_PAIR(colour));
			mvwprintw(stdscr, j, k, "%c ", 254);
			attroff(COLOR_PAIR(colour));
		}
	}
	attrset(0);
}
