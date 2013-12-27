#ifndef _renderable_h_
#define _renderable_h_

namespace Base {
namespace View {

class Renderer;

struct Renderable {
	virtual ~Renderable() {}
	virtual void render(Renderer &renderer) = 0;
};

}
}
#endif
