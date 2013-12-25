#ifndef _renderer_ncurses_h_
#define _renderer_ncurses_h_

#include "renderer.h"

namespace Rendering {

class RendererNCurses : public Renderer {

public:
	enum ColourNCurses {GREEN = 1, BLUE, RED, CYAN, WHITE, YELLOW};
	RendererNCurses();
	virtual ~RendererNCurses();
};

}
#endif
