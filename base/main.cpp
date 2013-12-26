#include <iostream>
#include <random>
#include <noise/noise.h>
#include "randgen.h"
#include "base/model/player.h"
#include "base/view/renderer.h"
#include "null/model/map.h"
#include "null/model/game.h"
#include "null/view/renderer.h"
#include "ncurses/model/map.h"
#include "ncurses/model/game.h"
#include "ncurses/view/renderer.h"
#include "ncurses/control/controller.h"

#define S 20

using namespace std;

RandGen<int> rando;

void runNCurses(int argc, char **argv) {
	using namespace NCurses;
	View::Renderer renderer;
	Model::Map map(renderer, rando.next());
	Model::Game game(argc, argv, rando, renderer, map);
	Control::Controller controller(game, map, renderer);

	renderer.set(Base::View::MAP, map);
	renderer.set(Base::View::GAME, game);
	controller.event_loop();
}

void runNull(int argc, char **argv) {
	using namespace Null;
	View::Renderer renderer;
	Model::Map map(renderer, rando.next());
	Model::Game game(argc, argv, rando, renderer, map);
	Base::Model::Player player(game, "alfred");
	renderer.set(Base::View::GAME, game);
	renderer.set(Base::View::MAP, map);

	renderer.render_all();
}

int main(int argc, char **argv) {
	try {
		runNCurses(argc, argv);
		runNull(argc, argv);
	} catch (std::exception &ex) {
		std::cerr << "Errors found: " << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
