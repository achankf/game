#ifndef _game_h_
#define _game_h_

#include <list>
#include "gamedb.h"
#include "randgen.h"
#include "type.h"
#include "map.h"
#include "base/view/renderable.h"

namespace Base {

namespace View {
class Renderer;
}

namespace Model {

class Game : public ::Base::View::RenderableList {
protected:
	RandGen<int> rando;
	GameDB db;
	Map map;

public:
	Game();
	virtual ~Game() {}
	const Map &getMap() const;

	id_type getUserID(const char *uid);
};

}
}
#endif
