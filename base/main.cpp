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

RandGen<int> rando;

void run(Base::Model::Game &game,
         Base::Model::Map &map,
         Base::View::Renderer &renderer,
         Base::Control::Controller &controller) {

	Base::Model::Player player(game, "alfred");
	controller.event_loop(player);
}

void setupNCurses(int argc, char **argv) {
	using namespace NCurses;
	View::Renderer renderer;
	Model::Map map(rando.next());
	Model::Game game(argc, argv, rando, map);
	Control::Controller controller(game, map, renderer);

	renderer.set_renderable(View::MAP,map);
	renderer.set_renderable(View::GAME,game);
	//renderer.set_renderable(View::CURSOR,controller.get_cursor());

	run(game, map, renderer, controller);
}

void setupNull(int argc, char **argv) {
	using namespace Null;
	View::Renderer renderer;
	Model::Map map(rando.next());
	Model::Game game(argc, argv, rando, map);
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
