#ifndef _base_game_hpp_
#define _base_game_hpp_

#include <list>
#include "gamedb.hpp"
#include "randgen.hpp"
#include "type.hpp"
#include "map.hpp"
#include "base/view/renderable.hpp"

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
