#include "base/model/map.h"
#include "base/model/game.h"
#include "base/control/cursor.h"
#include "null/view/renderer.h"
using namespace Null::View;

void Renderer::render_terrain(::Base::Model::Game &game, int i, int j, scalar_t x, scalar_t y) {
	(void) game;
	(void) i;
	(void) j;
	(void) x;
	(void) y;
}

void Renderer::render_cursor(::Base::Model::Game &game, ::Base::Control::Cursor &cursor) {
	(void) game;
	(void) cursor;
}
