#include <ncurses.h>
#include <iostream>
#include <random>
#include <noise/noise.h>
#include "game.h"
#include "randgen.h"
#include "renderer_ncurses.h"
#include "game_ncurses.h"
#include "map_ncurses.h"

#define S 20

using namespace std;

int main(int argc, char **argv) {
	//int rv = 0;

	Rendering::RendererNCurses renderer;
	Rendering::GameNCurses game(argc, argv, renderer);
	Rendering::MapNCurses map(renderer, game.next_random());
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
			goto END_MAIN;
		default:
			break;
		}
	}

END_MAIN:
	return 0;
}
