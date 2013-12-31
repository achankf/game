#include "base/model/entity.h"
#include "base/model/game.h"
using namespace ::Base::Model;

Entity::Entity(Game &game, id_type cid)
	: Locatable(game,cid), cid(cid) {
}
