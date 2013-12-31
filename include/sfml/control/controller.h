#ifndef _controller_sfml_h_
#define _controller_sfml_h_

#include <SFML/Graphics.hpp>
#include "../../base/control/controller.h"

namespace SFML {

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

	void handle_key(sf::RenderWindow &window, int c);
};

}
}
#endif
