#ifndef _renderable_h_
#define _renderable_h_

namespace Base {

namespace Model {
class Game;
}

namespace View {

class Renderer;

class Renderable {
protected:
	bool show = true;
public:
	virtual ~Renderable() {}
	virtual void render(::Base::Model::Game &game, Renderer &renderer) = 0;
	void toggle() {
		show = !show;
	}
};

}
}
#endif
