#ifndef _renderer_null_h_
#define _renderer_null_h_

#include "../../base/view/renderer.h"

namespace Null{
namespace View{

class Renderer : public ::Base::View::Renderer {

public:
	Renderer () {}
	virtual ~Renderer() {}
};

}
}
#endif
