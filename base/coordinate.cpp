#include <ncurses.h>
#include "coordinate.h"

Coordinate::Coordinate() : coor(0,0) {}

scalar_t Coordinate::get_x() {
	return coor.first;
}

scalar_t Coordinate::get_y() {
	return coor.second;
}

void Coordinate::set_x(scalar_t x) {
	coor.first = x;
}

void Coordinate::set_y(scalar_t y) {
	coor.second = y;
}

#if 0
void Coordinate::render() {
	mvwprintw(stdscr, get_x(), get_y(), "%c ", 254);
}
#endif
