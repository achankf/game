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
) : ::Base::Control::Controller (game, renderer) {}

void Controller::event_loop(
    ::Base::Model::Player &player
) {
	this->game.render(this->renderer);
	refresh();

	char input;

	while((input = getch())) {
		this->game.render(this->renderer);
		refresh();
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
