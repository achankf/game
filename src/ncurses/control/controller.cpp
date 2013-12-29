#include <ncurses.h>
#include "base/model/game.h"
#include "base/model/map.h"
#include "base/model/player.h"
#include "base/view/renderer.h"
#include "base/control/cursor.h"
#include "ncurses/control/controller.h"

using namespace NCurses::Control;

Controller::Controller(
    ::Base::Model::Game &game,
    ::Base::View::Renderer &renderer
) : ::Base::Control::Controller (game, renderer) {
	game.add_view(cursor);
}

void Controller::event_loop(
    ::Base::Model::Player &player
) {

	(void) player;

	char input;

	while (true) {
		this->game.update_all_views(this->renderer);
		refresh();
		if (!(input = getch())) break;
		switch (input) {
		case 'q' :
			return;
		case 'j':
			cursor.south();
			break;
		case 'h':
			cursor.west();
			break;
		case 'l':
			cursor.east();
			break;
		case 'k':
			cursor.north();
			break;
		default:
			break;
		}
	}
}
