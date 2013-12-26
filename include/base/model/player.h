#ifndef _player_h_
#define _player_h_

#include "../../type.h"

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
