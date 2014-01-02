#include <cstring>
#include <iostream>
#include "base/model/game.h"
#include "base/model/player.h"
using namespace Base::Model;

Player::Player(Game &game, const char *uid)
	: game(game), pid(game.getUserID(uid)) {

	std::cout << "Player:" << uid << " has pid:" << pid << std::endl;
}
