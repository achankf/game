#include "creature.h"

Creature::Creature(id_type eid)
	: Entity(eid) {
	coor = coor_t ((float)10.0,(float)10.0);
}
