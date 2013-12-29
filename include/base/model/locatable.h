#ifndef _locatable_h_
#define _locatable_h_

#include "type.h"

namespace Base {

namespace Model {

class Game;

class Locatable {
protected:
	id_type lid;
public:
	Locatable(Game &game, id_type lid);
	void update_coor(Game &game, scalar_t x, scalar_t y, scalar_t z);
	void get_coor(Game &game, coor_t &coor);
};

}
}
#endif
