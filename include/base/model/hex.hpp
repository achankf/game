#ifndef _base_hex_h_
#define _base_hex_h_

#include "type.hpp"

namespace Base {
namespace Model {

class Game;

class HexCoordinate : public coor_t {
protected:
	scalar_t &get_x();
	scalar_t &get_y();
	scalar_t &get_z();
public:
	HexCoordinate(scalar_t x, scalar_t y, scalar_t z);
	virtual ~HexCoordinate();
	void east(Game &game);
	void west(Game &game);
	void north_east(Game &game);
	void north_west(Game &game);
	void south_east(Game &game);
	void south_west(Game &game);
};

}
}

#endif
