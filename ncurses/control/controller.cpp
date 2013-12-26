#include <ncurses.h>
#include "base/view/renderer.h"
#include "ncurses/control/controller.h"
#include "ncurses/model/game.h"
#include "ncurses/model/map.h"

using namespace NCurses::Control;

Controller::Controller(::NCurses::Model::Game &game, ::NCurses::Model::Map &map, ::NCurses::View::Renderer &renderer)
	: ::Base::Control::Controller (game, map, renderer) {}

void Controller::event_loop() {
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
