#include <ncurses.h>
#include "controller_ncurses.h"
#include "renderer.h"

using namespace Control;

NCurses::NCurses(Game &game, Map &map, Rendering::Renderer &renderer)
	: Control::Controller (game, map, renderer) {}

void NCurses::event_loop() {
	renderer.render_all();
	refresh();

	char input;

	while((input = getch())) {
		renderer.render_all();
		refresh();
		switch (input) {
		case 'q' :
			return;
		default:
			break;
		}
	}
}
