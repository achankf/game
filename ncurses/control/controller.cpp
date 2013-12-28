#include <ncurses.h>
#include "base/model/game.h"
#include "base/model/map.h"
#include "base/model/player.h"
#include "base/view/renderer.h"
#include "ncurses/control/controller.h"

using namespace NCurses::Control;

Controller::Controller(
    ::Base::Model::Game &game,
    ::Base::View::Renderer &renderer
) : ::Base::Control::Controller (game, renderer), cursor(0,0) {
}

void Controller::event_loop(
    ::Base::Model::Player &player
) {

	(void) player;

	this->game.update_all_views(this->renderer);
	refresh();

	char input;

	while (true) {
		this->game.update_all_views(this->renderer);
		refresh();
		if (!(input = getch())) break;
		switch (input) {
		case 'q' :
			return;
		case KEY_LEFT:
			break;
		default:
			break;
		}
	}
}
