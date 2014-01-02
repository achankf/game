#ifndef _sfml_worldmap_hpp_
#define _sfml_worldmap_hpp_

#include <tuple>
#include <SFML/Graphics.hpp>
#include "base/view/renderable.hpp"

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
	void render(
	    ::Base::Model::Game &game,
	    ::Base::View::Renderer &renderer,
	    ::Base::Control::Controller &controller);
};
}
}

#endif
