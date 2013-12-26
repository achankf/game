#ifndef _game_h_
#define _game_h_

#include <random>
#include "../../gamedb.h"
#include "../../randgen.h"
#include "../../type.h"

class Map;

class Game {
protected:
	RandGen<int> &rando;
	GameDB db;

public:
	Game(int argc, char **argv, RandGen<int> &rando, Map &map);
	virtual ~Game() {}

	id_type get_userid(const char *uid);
};

#endif
