#ifndef _renderer_null_h_
#define _renderer_null_h_

#include "../../view/renderer.h"

namespace Rendering {

class RendererNull : public Renderer {

public:
	RendererNull() {}
	virtual ~RendererNull() {}
};

}
#endif
