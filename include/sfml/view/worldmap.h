#ifndef _worldmap_sfml_h_
#define _worldmap_sfml_h_

#include <tuple>
#include <SFML/Graphics.hpp>
#include "base/view/renderable.h"

namespace Base {
namespace Model {
class Game;
}
namespace View {
class Renderer;
}
}

namespace SFML {
namespace View {
class WorldMap : public ::Base::View::Renderable {
	sf::Uint8 *buf;
	sf::Image img;
	sf::Texture tex;
	sf::Sprite spr;
public:
	WorldMap(::Base::Model::Game &game);
	virtual ~WorldMap();
	std::tuple<sf::Uint8, sf::Uint8, sf::Uint8> heightToColour(double height) const;
	const sf::Sprite &getSprite() const;
	void render(::Base::Model::Game &game, ::Base::View::Renderer &renderer);
};
}
}

#endif
