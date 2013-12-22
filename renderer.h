#ifndef _renderer_h_
#define _renderer_h_

namespace Rendering {

class Renderable;

enum RenderableType {MAP,GAME,NUM_RANDERABLES};

class Renderer {
	Renderable *render_lst[NUM_RANDERABLES];

public:
	void set(RenderableType type, Renderable &renderable) {
		render_lst[type] = &renderable;
	}
	virtual ~Renderer() {}
	void render_all();
};

}
#endif
