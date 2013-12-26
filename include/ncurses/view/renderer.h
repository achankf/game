#ifndef _renderer_ncurses_h_
#define _renderer_ncurses_h_

#include "../../base/view/renderer.h"

namespace Rendering {

class RendererNCurses : public ::Base::View::Renderer {

public:
	enum ColourNCurses {GREEN = 1, BLUE, RED, CYAN, WHITE, YELLOW};
	RendererNCurses();
	virtual ~RendererNCurses();
};

}
#endif
