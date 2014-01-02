#ifndef _sfml_renderer_h_
#define _sfml_renderer_h_

#include "type.hpp"
#include "base/view/renderer.hpp"
#include "sfml/view/worldmap.hpp"
#include <SFML/Graphics.hpp>

namespace SFML {
namespace View {

class Renderer : public ::Base::View::Renderer {
	sf::RenderWindow window;
	sf::ConvexShape hexagon;
	WorldMap worldmap;

	std::tuple<sf::Uint8, sf::Uint8, sf::Uint8> heightToColour(double height);
protected:
	void renderTerrain(::Base::Model::Game &game, int i, int j);
public:
	Renderer(::Base::Model::Game &game);
	void renderMap(::Base::Model::Game &game);
	void renderCursor(
	    ::Base::Model::Game &game,
	    ::Base::Control::Cursor &cursor);
	void toggleWorldMap();
	sf::RenderWindow &getWindow();
};

}
}
#endif
