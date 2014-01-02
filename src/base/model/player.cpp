#include <cstring>
#include <iostream>
#include "base/model/game.hpp"
#include "base/model/player.hpp"
using namespace Base::Model;

Player::Player(Game &game, const char *uid)
	: game(game), pid(game.getUserID(uid)) {

	std::cout << "Player:" << uid << " has pid:" << pid << std::endl;
}
