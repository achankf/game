#ifndef _game_h_
#define _game_h_

#include <list>
#include "../../gamedb.h"
#include "../../randgen.h"
#include "../../type.h"
#include "map.h"

namespace Base {

namespace View {
class Renderer;
}

namespace Model {

class Game {
protected:
	std::list<::Base::View::Renderable *> view_lst;
	RandGen<int> rando;
	GameDB db;
	Map map;

public:
	Game();
	virtual ~Game() {}
	const Map &getMap() const;
	void addView(::Base::View::Renderable &view);
	void updateAllViews(::Base::View::Renderer &renderer);

	id_type getUserID(const char *uid);
};

}
}
#endif
