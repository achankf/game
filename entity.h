#ifndef _entity_h_
#define _entity_h_

#include "type.h"

class Entity {
	id_type eid;
public:
	Entity(id_type eid) : eid(eid) {}
};

#endif
