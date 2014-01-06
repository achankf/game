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
protected:
	void handleInput(sf::RenderWindow &window, int c);
	void handleKeyPressed();

public:
	Controller(
	    ::Base::Model::Game &game,
	    ::SFML::View::Renderer &renderer
	);
	void eventLoop(
	    ::Base::Model::Player &player
	);

	::SFML::View::Renderer &getRenderer();
	void invokeRenderAll();
};

}
}
#endif
