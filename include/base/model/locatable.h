#ifndef _locatable_h_
#define _locatable_h_

#include "type.h"

namespace Base {

namespace Model {

class Locatable : public coor_t {
	id_type lid;

public:
	Locatable(id_type lid, scalar_t x, scalar_t y)
	: coor_t(x,y), lid (lid) {}
};

}
}
#endif
