#ifndef _model_h_
#define _model_h_

#include <list>
#include "../view/renderable.h"

namespace Base {

namespace View {
class Renderer;
}

namespace Model {

class Model {
protected:
	std::list<::Base::View::Renderable *> view_lst;
public:
	virtual ~Model() {}
	void add_view(::Base::View::Renderable &view);
	void update_all_views(::Base::View::Renderer &renderer);
};

}
}

#endif
