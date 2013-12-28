#ifndef _creature_h_
#define _creature_h_

#include "locatable.h"
#include "../view/renderable.h"

namespace Base{

namespace View{
	class Renderer;
}

namespace Model{

class Game;

class Creature
	: public ::Base::View::Renderable
	, public Locatable{
protected:
	id_type cid;
public:
	Creature(Game &game, id_type cid);
	//virtual void render(::Base::Model::Game &game, ::Base::View::Renderer &renderer) = 0;
};

}
}

#endif
