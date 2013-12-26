#ifndef _renderable_h_
#define _renderable_h_

namespace Base {
namespace View {

class Renderer;

class Renderable {
	Renderer &renderer;

public:
	Renderable(Renderer &renderer) : renderer(renderer) {}
	virtual ~Renderable() {}
	virtual void render() = 0;
};

}
}
#endif
