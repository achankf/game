#ifndef _base_entity_hpp_
#define _base_entity_hpp_

#include "locatable.hpp"
#include "base/view/renderable.hpp"

namespace Base {

namespace Model {

class Game;

class Entity
	: public ::Base::View::Renderable
	, public Locatable {
protected:
	id_type cid;
public:
	Entity(Game &game, id_type cid);
};

}
}

#endif
