#ifndef _base_locatable_hpp_
#define _base_locatable_hpp_

#include "type.hpp"

namespace Base {

namespace Model {

class Game;

class Locatable {
protected:
	id_type lid;
public:
	Locatable(Game &game, id_type lid);
	void update_coor(Game &game, scalar_t x, scalar_t y, scalar_t z);
	coor_t get_coor(Game &game);
};

}
}
#endif
