#include "base/model/game.h"
#include "base/view/renderer.h"
#include "base/control/cursor.h"
using namespace Base::Control;

Cursor::Cursor() : coor_t(0,0,0) {}

Cursor::Cursor(scalar_t x, scalar_t y, scalar_t z)
	: coor_t(x,y,z) {
}

void Cursor::render(::Base::Model::Game &game, ::Base::View::Renderer &renderer) {
	(void)renderer;
	(void)game;
	renderer.render_cursor(game, *this);
}

void Cursor::north() {
	this->get_y()--;
}

void Cursor::south() {
	this->get_y()++;
}

void Cursor::east() {
	this->get_x()++;
}

void Cursor::west() {
	this->get_x()--;
}

void Cursor::north_east() {
	this->north();
	this->east();
}

void Cursor::north_west() {
	this->north();
	this->west();
}

void Cursor::south_east() {
	this->south();
	this->east();
}

void Cursor::south_west() {
	this->south();
	this->west();
}

scalar_t &Cursor::get_x() {
	return std::get<0>(*this);
}

scalar_t &Cursor::get_y() {
	return std::get<1>(*this);
}

scalar_t &Cursor::get_z() {
	return std::get<2>(*this);
}
