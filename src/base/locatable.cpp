#include "base/model/locatable.h"
#include "base/model/game.h"
using namespace Base::Model;

Locatable::Locatable(Game &game, id_type cid){
	(void) game;
	(void) cid;
	this->lid = 0;
}

void Locatable::set_x(scalar_t x){
	std::get<0>(this->coor) = x;
}

void Locatable::set_y(scalar_t y){
	std::get<1>(this->coor) = y;
}

void Locatable::set_z(scalar_t z){
	std::get<2>(this->coor) = z;
}

const coor_t &Locatable::get_coor() const{
	return this->coor;
}
