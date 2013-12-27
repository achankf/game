#ifndef _game_h_
#define _game_h_

#include <random>
#include "../../gamedb.h"
#include "../../randgen.h"
#include "../../type.h"
#include "../view/renderable.h"

namespace Base {

namespace View {
class Renderer;
}

namespace Model {

class Map;

class Game : public ::Base::View::Renderable {
protected:
	RandGen<int> &rando;
	GameDB db;

public:
	Game(int argc, char **argv, RandGen<int> &rando, Map &map);
	virtual ~Game() {}

	id_type get_userid(const char *uid);
	void render(::Base::View::Renderer &renderer);
};

}
}
#endif
