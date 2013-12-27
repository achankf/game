#ifndef _coordinate_h_
#define _coordinate_h_

#include "type.h"

class Coordinate {
	coor_t coor;
public:
	Coordinate();
	scalar_t get_x();
	scalar_t get_y();
	void set_x(scalar_t x);
	void set_y(scalar_t y);
	void render();
};

#endif
