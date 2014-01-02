#include "base/model/entity.hpp"
#include "base/model/game.hpp"
using namespace ::Base::Model;

Entity::Entity(Game &game, id_type cid)
	: Locatable(game,cid), cid(cid) {
}
