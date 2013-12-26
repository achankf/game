#include <ncurses.h>
#include "base/view/renderer.h"
#include "ncurses/control/controller.h"

using namespace NCurses::Control;

Controller::Controller(::Base::Model::Game &game, ::Base::Model::Map &map, ::Base::View::Renderer &renderer)
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
