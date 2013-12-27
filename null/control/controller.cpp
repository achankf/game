#include <ncurses.h>
#include "base/model/game.h"
#include "base/model/map.h"
#include "base/model/player.h"
#include "base/view/renderer.h"
#include "null/control/controller.h"
#include "null/view/renderer.h"

using namespace Null::Control;

Controller::Controller(
    ::Base::Model::Game &game,
    ::Null::View::Renderer &renderer
) : ::Base::Control::Controller (game, renderer) {}

void Controller::event_loop(
    ::Base::Model::Player &player
) {
}
