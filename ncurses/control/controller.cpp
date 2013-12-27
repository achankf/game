#include <ncurses.h>
#include "base/model/game.h"
#include "base/model/map.h"
#include "base/model/player.h"
#include "base/view/renderer.h"
#include "ncurses/view/renderer.h"
#include "ncurses/control/controller.h"

using namespace NCurses::Control;

Controller::Controller(
    ::Base::Model::Game &game,
    ::Base::Model::Map &map,
    ::NCurses::View::Renderer &renderer
) : ::Base::Control::Controller (game, map, renderer) {}

void Controller::event_loop(
    ::Base::Model::Player &player
) {
	renderer.render_all();
	refresh();

	char input;

	while((input = getch())) {
		renderer.render_all();
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
