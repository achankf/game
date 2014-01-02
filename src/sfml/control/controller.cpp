#include <SFML/Graphics.hpp>
#include <iostream>
#include "base/model/game.hpp"
#include "base/model/map.hpp"
#include "base/model/player.hpp"
#include "base/control/cursor.hpp"
#include "sfml/view/renderer.hpp"
#include "sfml/control/controller.hpp"
using namespace SFML::Control;

Controller::Controller(
    ::Base::Model::Game &game,
    ::Base::View::Renderer &renderer
) : ::Base::Control::Controller (game, renderer) {
	game.addView(cursor);
}

void Controller::event_loop(
    ::Base::Model::Player &player
) {

	(void) player;
	bool change = true;

	sf::RenderWindow &window = this->getRenderer().getWindow();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			else if (event.type == sf::Event::TextEntered) this->handle_key(window, event.text.unicode);
			else continue;
			change = true;
		}
		if (change) {
			window.clear(sf::Color::Black);
			this->game.updateAllViews(this->game, this->renderer, *this);
		}
		window.display();
		change = false;
	}
}

void Controller::handle_key(sf::RenderWindow &window, int c) {
	if (c >= 128) {
		std::cerr << "Only ASCII is supported" << std::endl;
		return;
	}

	switch(c) {
	case 'q':
		window.close();
		break;
	case 'w':
		this->cursor.north_west(this->game);
		break;
	case 'e':
		this->cursor.north_east(this->game);
		break;
	case 'd':
		this->cursor.east(this->game);
		break;
	case 's':
		this->cursor.west(this->game);
		break;
	case 'x':
		this->cursor.south_west(this->game);
		break;
	case 'c':
		this->cursor.south_east(this->game);
		break;
	case 'm':
		this->getRenderer().toggleWorldMap();
		break;
	}
}

::SFML::View::Renderer &Controller::getRenderer() {
	return static_cast<::SFML::View::Renderer&>(this->renderer);
}
