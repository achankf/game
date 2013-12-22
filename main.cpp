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
#if 0
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<uint32_t> uint_dist;

	noise::module::Perlin perlin;
	perlin.SetSeed(uint_dist(generator));

	initscr(); // ncurses
	if(has_colors() == FALSE) {
		endwin();
		cout << "Your terminal does not support color" << endl;
		return 1;
	}
	start_color();
	rv |= init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
	rv |= init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	rv |= init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
	rv |= init_pair(LIGHT_GREEN, COLOR_GREEN, COLOR_WHITE);
	if (rv) {
		cout << "Something is wrong with the colours" << endl;
		return 1;
	}

	for (int i = 0; i < S+S+S; i++) {
		for (int j = 0; j < S; j++) {

			double val = perlin.GetValue((double)i,(double)j,0.1);
			int k = i + j;

			int colour;
			(void)colour;
			if (val < -0.2) colour = BLUE;
			else if (val < 0) colour = CYAN;
			else if (val < 1) colour = GREEN;
			else colour = LIGHT_GREEN;

			attron(COLOR_PAIR(colour));
			mvwprintw(stdscr, j, k, "%c ", 254);//, map[i][j]);
			attroff(COLOR_PAIR(colour));
		}
	}
	attrset(0);
	refresh();
	char input;
	while((input = getch())) {
		switch (input) {
		case 'q' :
			goto END_MAIN;
		default:
			break;
		}
	}

END_MAIN:
	endwin();
#endif
}
