#ifndef _sfml_controller_hpp_
#define _sfml_controller_hpp_

#include <SFML/Graphics.hpp>
#include "base/control/controller.hpp"

namespace SFML {

namespace View {
class Renderer;
}

namespace Control {

class Controller : public ::Base::Control::Controller {

public:
	Controller(
	    ::Base::Model::Game &game,
	    ::Base::View::Renderer &renderer
	);
	void event_loop(
	    ::Base::Model::Player &player
	);

	::SFML::View::Renderer &getRenderer();

	void handle_key(sf::RenderWindow &window, int c);
};

}
}
#endif
