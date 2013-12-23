#ifndef _renderer_ncurses_h_
#define _renderer_ncurses_h_

#include "renderer.h"

namespace Rendering {

enum { GREEN = 1, BLUE, RED, CYAN, WHITE, YELLOW};

class RendererNCurses : public Renderer {

public:
	RendererNCurses();
	virtual ~RendererNCurses();
};

}
#endif
