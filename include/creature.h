#ifndef _creature_h_
#define _creature_h_

#include "type.h"
#include "entity.h"

class Creature : Entity {
	coor_t coor;

public:
	Creature(id_type eid);
};

#endif
