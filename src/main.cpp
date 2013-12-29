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

static void run(int argc, char **argv,
                Base::Model::Game &game,
                Base::View::Renderer &renderer,
                Base::Control::Controller &controller) {

	(void) renderer;
	const char *pname = "alfred";

	if (argc == 3) pname = argv[2];
	Base::Model::Player player(game, pname);
	controller.event_loop(player);
}

static void runNCurses(int argc, char **argv, ::Base::Model::Game &game) {
	using namespace NCurses;
	View::Renderer renderer;
	Control::Controller controller(game, renderer);

	run(argc, argv, game, renderer, controller);
}

static void runNull(int argc, char **argv, ::Base::Model::Game &game) {
	using namespace Null;
	View::Renderer renderer;
	Control::Controller controller(game, renderer);

	run(argc, argv, game, renderer, controller);
}

static void setup(int argc, char **argv) {
	::Base::Model::Game game;

	if (argc == 1 || std::strcmp("ncurses", argv[1]) == 0) {
		runNCurses(argc, argv, game);
	} else if (std::strcmp("null", argv[1]) == 0) {
		runNull(argc, argv, game);
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
