#include <iostream>
#include <cstring>
#include "randgen.hpp"
#include "base/model/player.hpp"
#include "base/model/game.hpp"
#include "sfml/view/renderer.hpp"
#include "sfml/control/controller.hpp"

static void run(int argc, char **argv,
                Base::Model::Game &game,
                Base::View::Renderer &renderer,
                Base::Control::Controller &controller) {

	std::cout << "Running game" << std::endl;

	(void) renderer;
	const char *pname = "alfred";

	if (argc == 3) pname = argv[2];
	Base::Model::Player player(game, pname);
	controller.eventLoop(player);
}

static void runSFML(int argc, char **argv, ::Base::Model::Game &game) {
	SFML::View::Renderer renderer(game);
	SFML::Control::Controller controller(game, renderer);

	run(argc, argv, game, renderer, controller);
}

static void setup(int argc, char **argv) {
	::Base::Model::Game game;

	if (argc == 1 || std::strcmp("sfml", argv[1]) == 0) {
		runSFML(argc, argv, game);
	} else {
		std::cerr << "Invalid display/controlling model" << std::endl;
		throw std::exception();
	}
}

int main(int argc, char **argv) {
	std::cout << "Starting game" << std::endl;
	try {
		setup(argc, argv);
	} catch (std::exception &ex) {
		std::cerr << "Errors found: " << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
