#include "base/model/creature.h"
#include "base/model/game.h"
using namespace ::Base::Model;

Creature::Creature(Game &game, id_type cid)
	: Locatable(game,cid), cid(cid) {
}
