#include <iostream>
#include <random>
#include <noise/noise.h>
#include "randgen.h"
#include "base/model/player.h"
#include "base/view/renderer.h"
#include "null/model/map.h"
#include "null/model/game.h"
#include "null/view/renderer.h"
#include "null/control/controller.h"
#include "ncurses/model/map.h"
#include "ncurses/model/game.h"
#include "ncurses/view/renderer.h"
#include "ncurses/control/controller.h"

#define S 20

using namespace std;

RandGen<int> rando;

void run(Base::Model::Game &game,
         Base::Model::Map &map,
         Base::View::Renderer &renderer,
         Base::Control::Controller &controller) {

	renderer.set(Base::View::MAP, map);
	renderer.set(Base::View::GAME, game);

	Base::Model::Player player(game, "alfred");

	controller.event_loop();
}

void setupNCurses(int argc, char **argv) {
	using namespace NCurses;
	View::Renderer renderer;
	Model::Map map(renderer, rando.next());
	Model::Game game(argc, argv, rando, renderer, map);
	Control::Controller controller(game, map, renderer);

	run(game, map, renderer, controller);
}

void setupNull(int argc, char **argv) {
	using namespace Null;
	View::Renderer renderer;
	Model::Map map(renderer, rando.next());
	Model::Game game(argc, argv, rando, renderer, map);
	Control::Controller controller(game, map, renderer);

	run(game, map, renderer, controller);
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
