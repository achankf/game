#include <iostream>
#include <random>
#include <cstring>
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

static void run(Base::Model::Game &game,
         Base::View::Renderer &renderer,
         Base::Control::Controller &controller) {

	(void) renderer;

	Base::Model::Player player(game, "alfred");
	controller.event_loop(player);
}

inline void runNCurses(::Base::Model::Game &game) {
	using namespace NCurses;
	View::Renderer renderer;
	Control::Controller controller(game, renderer);

	run(game, renderer, controller);
}

inline void runNull(::Base::Model::Game &game) {
	using namespace Null;
	View::Renderer renderer;
	Control::Controller controller(game, renderer);

	run(game, renderer, controller);
}

inline void setup(int argc, char **argv) {
	::Base::Model::Game game;

	if (argc == 1 || std::strcmp("ncurses", argv[1]) == 0) {
		runNCurses(game);
	} else if (std::strcmp("null", argv[1]) == 0) {
		runNull(game);
	} else {
		std::cerr << "Invalid display/controlling model" << std::endl;
		throw std::exception();
	}
}

int main(int argc, char **argv) {
	try {
		setup(argc, argv);
	} catch (std::exception &ex) {
		std::cerr << "Errors found: " << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
