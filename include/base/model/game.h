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
	const Map &get_map() const;
	void add_view(::Base::View::Renderable &view);
	void update_all_views(::Base::View::Renderer &renderer);

	id_type get_userid(const char *uid);
};

}
}
#endif
