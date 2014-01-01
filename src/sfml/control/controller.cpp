#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "base/model/game.h"
#include "base/model/map.h"
#include "base/model/player.h"
#include "base/view/renderer.h"
#include "base/control/cursor.h"
#include "sfml/view/renderer.h"
#include "sfml/control/controller.h"

using namespace SFML::Control;

Controller::Controller(
    ::Base::Model::Game &game,
    ::Base::View::Renderer &renderer
) : ::Base::Control::Controller (game, renderer) {
	game.add_view(cursor);
}

void Controller::event_loop(
    ::Base::Model::Player &player
) {

	(void) player;
	bool change = true;

	sf::RenderWindow &window = static_cast<::SFML::View::Renderer&>(this->renderer).get_window();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			else if (event.type == sf::Event::TextEntered) this->handle_key(window, event.text.unicode);
			else continue;
			change = true;
		}
		if (change){
			window.clear(sf::Color::Black);
			this->game.update_all_views(this->renderer);
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
	case 'q': window.close(); break;
	case 'w': cursor.north_west(); break;
	case 'e': cursor.north_east(); break;
	case 'd': cursor.east(); break;
	case 'a': cursor.west(); break;
	case 'z': cursor.south_west(); break;
	case 'x': cursor.south_east(); break;
	}
}
