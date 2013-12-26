#include "base/view/renderer.h"
#include "ncurses/model/map.h"
#include "ncurses/view/renderer.h"
#include <ncurses.h>
using namespace NCurses::Model;

Map::Map(NCurses::View::Renderer &renderer, int seed)
	: Base::Model::Map(seed), Base::View::Renderable(renderer) {
}

void Map::render() {
	for (int i = 0; i < this->getLength(); i++) {
		for (int j = 0; j < this->getWidth(); j++) {

			double val = this->getBaseTile(0.5 + i, 0.5 + j);

			using namespace NCurses::View;
			Renderer::Colour colour;

			switch (this->baseToTile(val)) {
			case DEEP:
				colour = Renderer::BLUE;
				break;
			case SHALLOW:
				colour = Renderer::CYAN;
				break;
			case PLAIN:
				colour = Renderer::YELLOW;
				break;
			case GRASS:
				colour = Renderer::GREEN;
				break;
			case HILL:
				colour = Renderer::RED;
				break;
			case SNOW:
				colour = Renderer::WHITE;
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
