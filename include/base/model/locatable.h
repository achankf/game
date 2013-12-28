#ifndef _locatable_h_
#define _locatable_h_

#include "type.h"

namespace Base {

namespace Model {

class Game;

class Locatable {
	coor_t coor;
	id_type lid;

public:
	Locatable(Game &game, id_type cid);
	void set_x(scalar_t x);
	void set_y(scalar_t y);
	void set_z(scalar_t z);
	const coor_t &get_coor() const;
};

}
}
#endif
