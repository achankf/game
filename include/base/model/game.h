#ifndef _game_h_
#define _game_h_

#include <random>
#include "../view/renderable.h"
#include "../../gamedb.h"
#include "../../randgen.h"
#include "../../type.h"

namespace Base {
namespace Model {

class Map;

class Game : public ::Base::View::Renderable {
protected:
	RandGen<int> &rando;
	GameDB db;

public:
	Game(int argc, char **argv, RandGen<int> &rando, ::Base::View::Renderer &renderer, Map &map);
	virtual ~Game() {}

	id_type get_userid(const char *uid);
};

}
}
#endif
