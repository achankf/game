#ifndef _renderer_ncurses_h_
#define _renderer_ncurses_h_

#include "renderer.h"

namespace Rendering {

enum { GREEN = 1, BLUE, CYAN, LIGHT_GREEN};

class RendererNCurses : public Renderer {

public:
	RendererNCurses();
	virtual ~RendererNCurses();
};

}
#endif
