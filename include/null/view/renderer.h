#ifndef _renderer_null_h_
#define _renderer_null_h_

#include "../../base/view/renderer.h"

namespace Rendering {

class RendererNull : public ::Base::View::Renderer {

public:
	RendererNull() {}
	virtual ~RendererNull() {}
};

}
#endif