#ifndef _base_player_hpp_
#define _base_player_hpp_

#include "type.hpp"

namespace Base {
namespace Model {

class Game;

class Player {
	Game &game;
	id_type pid;
	const char *uid;

public:
	Player(Game &game, const char *uid);
};

}
}
#endif
