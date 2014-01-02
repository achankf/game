#include "base/model/hex.hpp"
#include "base/model/game.hpp"
using namespace Base::Model;

HexCoordinate::HexCoordinate(scalar_t x, scalar_t y, scalar_t z)
	: coor_t(x,y,z) {
}

HexCoordinate::~HexCoordinate(){}

void HexCoordinate::east(Game &game) {
	auto &x = this->get_x();
	const auto length = game.getMap().getLength();
	if (++x < length) return;
	x -= length; // wrap around
}

void HexCoordinate::west(Game &game) {
	auto &x = this->get_x();
	const auto length = game.getMap().getLength();
	if (--x >= 0) return;
	x += length; // wrap around
}

void HexCoordinate::north_east(Game &game) {
	this->north_west(game);
	this->east(game);
}

void HexCoordinate::north_west(Game &game) {
	auto &y = this->get_y();
	const auto width = game.getMap().getWidth();
	if (--y >= 0) return;
	y += width; // wrap around
}

void HexCoordinate::south_east(Game &game) {
	auto &y = this->get_y();
	const auto width = game.getMap().getWidth();
	if (++y < width) return;
	y -= width; // wrap around
}

void HexCoordinate::south_west(Game &game) {
	this->south_east(game);
	this->west(game);
}

scalar_t &HexCoordinate::get_x() {
	return std::get<0>(*this);
}

scalar_t &HexCoordinate::get_y() {
	return std::get<1>(*this);
}

scalar_t &HexCoordinate::get_z() {
	return std::get<2>(*this);
}
