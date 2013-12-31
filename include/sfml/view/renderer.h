#ifndef _renderer_sfml_h_
#define _renderer_sfml_h_

#include "../../type.h"
#include "../../base/view/renderer.h"
#include <SFML/Graphics.hpp>

namespace SFML {
namespace View {

class Renderer : public ::Base::View::Renderer {
	sf::RenderWindow window;
	sf::ConvexShape hexagon;

public:
	Renderer();
	virtual ~Renderer();
	void render_terrain(::Base::Model::Game &game, int i, int j, scalar_t x, scalar_t y);
	void render_cursor(::Base::Model::Game &game, ::Base::Control::Cursor &cursor);
	sf::RenderWindow &get_window();
};

}
}
#endif
