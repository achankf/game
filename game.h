#ifndef _game_h_
#define _game_h_

#include <random>
#include "renderable.h"
#include "randgen.h"

namespace Rendering {
class Map;
class Renderer;

class Game : public Renderable {
	RandGen<int> rando;

public:
	Game(int argc, char **argv, Renderer &renderer) : Renderable(renderer) {}
	int next_random() {
		return rando.next();
	}
};
}
#endif
