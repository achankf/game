#include <ncurses.h>
#include "base/view/renderer.h"
#include "null/control/controller.h"
#include "null/model/game.h"
#include "null/model/map.h"
#include "null/view/renderer.h"

using namespace Null::Control;

Controller::Controller(::Null::Model::Game &game, ::Null::Model::Map &map, ::Null::View::Renderer &renderer)
	: ::Base::Control::Controller (game, map, renderer) {}

void Controller::event_loop() {
}
