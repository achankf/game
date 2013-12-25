#include "map_ncurses.h"
#include "renderer_ncurses.h"
#include <ncurses.h>
using namespace Rendering;

void MapNCurses::render() {
	for (int i = 0; i < this->getLength(); i++) {
		for (int j = 0; j < this->getWidth(); j++) {

			double val = this->getBaseTile(0.5 + i, 0.5 + j);
			RendererNCurses::ColourNCurses colour;

			switch (this->baseToTile(val)) {
			case DEEP:
				colour = RendererNCurses::BLUE;
				break;
			case SHALLOW:
				colour = RendererNCurses::CYAN;
				break;
			case PLAIN:
				colour = RendererNCurses::YELLOW;
				break;
			case GRASS:
				colour = RendererNCurses::GREEN;
				break;
			case HILL:
				colour = RendererNCurses::RED;
				break;
			case SNOW:
				colour = RendererNCurses::WHITE;
				break;
			default:
				assert("Invalid Tile Type" == nullptr); // aka fails
			}

			attron(COLOR_PAIR(colour));
			mvwprintw(stdscr, j, i, "%c ", 254);
			attroff(COLOR_PAIR(colour));
		}
	}
	attrset(0);
}
