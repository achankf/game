#ifndef _renderer_ncurses_h_
#define _renderer_ncurses_h_

#include "../../base/view/renderer.h"

namespace NCurses {
namespace View {

class Renderer : public ::Base::View::Renderer {

public:
	enum Colour {GREEN = 1, BLUE, RED, CYAN, WHITE, YELLOW};
	Renderer();
	virtual ~Renderer();
};

}
}
#endif
