#ifndef _entity_h_
#define _entity_h_

#include "locatable.h"
#include "../view/renderable.h"

namespace Base {

namespace View {
class Renderer;
}

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
