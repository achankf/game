#include <iostream>
#include <random>
#include <noise/noise.h>
#include "randgen.h"
#include "player.h"
#include "ncurses/mvc.h"
#include "null/mvc.h"

#define S 20

using namespace std;

RandGen<int> rando;

void runNCurses(int argc, char **argv) {
	Rendering::RendererNCurses renderer;
	Rendering::MapNCurses map(renderer, rando.next());
	Rendering::GameNCurses game(argc, argv, rando, renderer, map);
	Control::NCurses controller(game, map, renderer);

	renderer.set(Rendering::MAP, map);
	renderer.set(Rendering::GAME, game);
	controller.event_loop();
}

void runNull(int argc, char **argv) {
	Rendering::RendererNull renderer;
	Rendering::MapNull map(renderer, rando.next());
	Rendering::GameNull game(argc, argv, rando, renderer, map);
	Player player(game, "alfred");
	renderer.set(Rendering::GAME, game);

	renderer.render_all();
}

int main(int argc, char **argv) {
	try {
		runNCurses(argc, argv);
	} catch (std::exception &ex) {
		std::cerr << "Errors found: " << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
