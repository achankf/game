#include <ncurses.h>
#include <iostream>
#include <random>
#include <noise/noise.h>
#include "game.h"
#include "randgen.h"
#include "renderer_ncurses.h"
#include "renderer_null.h"
#include "game_ncurses.h"
#include "game_null.h"
#include "map_ncurses.h"
#include "map_null.h"
#include "player.h"

#define S 20

using namespace std;

RandGen<int> rando;

void runNCurses(int argc, char **argv) {
	Rendering::RendererNCurses renderer;
	Rendering::MapNCurses map(renderer, rando.next());
	Rendering::GameNCurses game(argc, argv, rando, renderer, map);
	renderer.set(Rendering::MAP, map);
	renderer.set(Rendering::GAME, game);

	renderer.render_all();
	refresh();

	char input;


	while((input = getch())) {
		renderer.render_all();
		refresh();
		switch (input) {
		case 'q' :
			return;
		default:
			break;
		}
	}
}

void runNull(int argc, char **argv) {
	Rendering::RendererNull renderer;
	Rendering::MapNull map(renderer, rando.next());
	Rendering::GameNull game(argc, argv, rando, renderer, map);
	Player player(game, "alfred");
	renderer.set(Rendering::MAP, map);
	renderer.set(Rendering::GAME, game);

	renderer.render_all();
}

int main(int argc, char **argv) {
	try {
		runNull(argc, argv);
	} catch (std::exception &ex) {
		std::cerr << "Errors found: " << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
