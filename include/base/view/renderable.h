#ifndef _renderable_h_
#define _renderable_h_

#include <list>

namespace Base {

namespace Model {
class Game;
}

namespace Control {
class Controller;
}

namespace View {

class Renderer;

class Renderable {
protected:
	bool show = true;
public:
	virtual ~Renderable() {}
	virtual void render(
	    ::Base::Model::Game &game,
	    ::Base::View::Renderer &renderer,
	    ::Base::Control::Controller &controller) = 0;
	void toggle() {
		show = !show;
	}
};

class RenderableList {
protected:
	std::list<::Base::View::Renderable *> view_lst;
public:
	virtual ~RenderableList();
	void addView(::Base::View::Renderable &view);
	void updateAllViews(
	    ::Base::Model::Game &game,
	    ::Base::View::Renderer &renderer,
	    ::Base::Control::Controller &controller);
};

}
}
#endif
