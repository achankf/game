#include "base/model/locatable.h"
#include "base/model/game.h"
using namespace Base::Model;

Locatable::Locatable(Game &game, id_type cid) {
	(void) game;
	(void) cid;
	this->lid = 0;
}

void Locatable::update_coor(Game &game, scalar_t x, scalar_t y, scalar_t z) {
	(void)x;
	(void)y;
	(void)z;
	(void)game;
}

coor_t Locatable::get_coor(Game &game) {
	(void)game;
	return coor_t(0,0,0);
}
