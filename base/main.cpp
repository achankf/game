#include <iostream>
#include <random>
#include <noise/noise.h>
#include "randgen.h"
#include "base/model/player.h"
#include "base/model/map.h"
#include "base/model/game.h"
#include "base/view/renderer.h"
#include "null/view/renderer.h"
#include "null/control/controller.h"
#include "ncurses/view/renderer.h"
#include "ncurses/control/controller.h"

void run(Base::Model::Game &game,
         Base::View::Renderer &renderer,
         Base::Control::Controller &controller) {

	Base::Model::Player player(game, "alfred");
	controller.event_loop(player);
}

void setupNCurses(int argc, char **argv) {
	::Base::Model::Game game(argc, argv);
	using namespace NCurses;
	View::Renderer renderer;
	Control::Controller controller(game, renderer);

	run(game, renderer, controller);
}

void setupNull(int argc, char **argv) {
	::Base::Model::Game game(argc, argv);
	using namespace Null;
	View::Renderer renderer;
	Control::Controller controller(game, renderer);

	run(game, renderer, controller);
}

int main(int argc, char **argv) {
	try {
		setupNCurses(argc, argv);
		setupNull(argc, argv);
	} catch (std::exception &ex) {
		std::cerr << "Errors found: " << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
