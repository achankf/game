#include <cstring>
#include <iostream>
#include "player.h"
#include "game.h"

Player::Player(Game &game, const char *uid)
	: game(game), pid(game.get_userid(uid)) {

	std::cout << "Player:" << uid << " has pid:" << pid << std::endl;
}
