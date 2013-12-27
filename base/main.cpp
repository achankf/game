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

RandGen<int> rando;

void run(Base::Model::Game &game,
         Base::Model::Map &map,
         Base::View::Renderer &renderer,
         Base::Control::Controller &controller) {

	Base::Model::Player player(game, "alfred");
	controller.event_loop(player);
}

void setupNCurses(int argc, char **argv) {
	::Base::Model::Map map(rando.next());
	::Base::Model::Game game(argc, argv, rando, map);
	using namespace NCurses;
	::NCurses::View::Renderer renderer;
	::NCurses::Control::Controller controller(game, map, renderer);

	renderer.set_renderable(View::MAP,map);
	renderer.set_renderable(View::GAME,game);
	//renderer.set_renderable(View::CURSOR,controller.get_cursor());

	run(game, map, renderer, controller);
}

void setupNull(int argc, char **argv) {
	using namespace Base;
	Model::Map map(rando.next());
	Model::Game game(argc, argv, rando, map);
	using namespace Null;
	::Null::View::Renderer renderer;
	::Null::Control::Controller controller(game, map, renderer);

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
