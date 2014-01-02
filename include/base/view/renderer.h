#ifndef _renderer_h_
#define _renderer_h_

#include "type.h"

namespace Base {
namespace Model {
class Game;
}

namespace Control {
class Cursor;
}

namespace View {

class Renderer {
protected:
	virtual void renderUI(::Base::Model::Game &game) = 0;
	virtual void renderTerrain(::Base::Model::Game &game, int i, int j) = 0;
public:
	virtual ~Renderer() {}
	virtual void renderMap(::Base::Model::Game &game) = 0;
	virtual void renderCursor(::Base::Model::Game &game, ::Base::Control::Cursor &cursor) = 0;
	virtual void renderAll(::Base::Model::Game &game) = 0;
};

}
}
#endif
