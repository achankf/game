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

void Controller::eventLoop(
    ::Base::Model::Player &player
) {

	(void) player;
	bool redraw = true;

	auto &ren = this->getRenderer();
	auto &window = ren.getWindow();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch(event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				this->handleInput(window, event.text.unicode);
				break;
			case sf::Event::KeyPressed:
				this->handleKeyPressed();
				break;
			default:
				continue;
			}
			redraw = true;
		}
		if (redraw) {
			window.clear(sf::Color::Black);
			this->game.updateAllViews(this->game, this->renderer, *this);
		}
		window.display();
		redraw = false;
	}
}

void Controller::handleInput(sf::RenderWindow &window, int c) {
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
	scalar_t x, y, z;
	std::tie(x,y,z) = this->cursor;
	std::cout << x << ' ' << y << ' ' << z << std::endl;
}

::SFML::View::Renderer &Controller::getRenderer() {
	return static_cast<::SFML::View::Renderer&>(this->renderer);
}

void Controller::handleKeyPressed() {
	auto &ren = this->getRenderer();
	auto &focus = ren.getFocus();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		focus.west(this->game);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		focus.east(this->game);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		focus.north_east(this->game);
		focus.north_west(this->game);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		focus.south_east(this->game);
		focus.south_west(this->game);
	}
}
