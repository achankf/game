#ifndef _game_h_
#define _game_h_

#include "../../gamedb.h"
#include "../../randgen.h"
#include "../../type.h"
#include "model.h"
#include "map.h"

namespace Base {

namespace View {
class Renderer;
}

namespace Model {

class Map;

class Game : public ::Base::Model::Model {
protected:
	RandGen<int> rando;
	GameDB db;
	Map map;

public:
	Game();
	virtual ~Game() {}

	id_type get_userid(const char *uid);
};

}
}
#endif
