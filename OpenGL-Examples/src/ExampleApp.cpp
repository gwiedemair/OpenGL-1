#include "GLCore.h"
#include "LearnOpenGLLayer.h"

using namespace GLCore;


class Example : public Application
{
public:
	Example()
		: Application("OpenGL Examples", SCR_WIDTH, SCR_HEIGHT)
	{
		PushLayer(new LearnOpenGLLayer());
	}
};

int main()
{
	std::unique_ptr<Example> app = std::make_unique<Example>();
	app->Run();
}