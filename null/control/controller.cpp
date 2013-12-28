#include <ncurses.h>
#include "base/model/game.h"
#include "base/model/map.h"
#include "base/model/player.h"
#include "base/view/renderer.h"
#include "null/control/controller.h"

using namespace Null::Control;

Controller::Controller(
    ::Base::Model::Game &game,
    ::Base::View::Renderer &renderer
) : ::Base::Control::Controller (game, renderer) {}

void Controller::event_loop(
    ::Base::Model::Player &player
) {
	(void) player;
}
