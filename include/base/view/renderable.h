#ifndef _renderable_h_
#define _renderable_h_

namespace Base {

namespace Model {
class Game;
}

namespace View {

class Renderer;

struct Renderable {
	virtual ~Renderable() {}
	virtual void render(::Base::Model::Game &game, Renderer &renderer) = 0;
};

}
}
#endif
