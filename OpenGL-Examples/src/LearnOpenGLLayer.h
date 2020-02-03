#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>

const unsigned int SCR_WIDTH = 2560;
const unsigned int SCR_HEIGHT = 1440;


class LearnOpenGLLayer : public GLCore::Layer
{
public:
	LearnOpenGLLayer();
	virtual ~LearnOpenGLLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(GLCore::Event& event) override;
	virtual void OnUpdate(GLCore::Timestep ts) override;
	virtual void OnImGuiRender() override;
private:
	GLCore::Utils::Shader* m_Shader;

	std::unique_ptr<GLCore::Utils::Camera> m_Camera;
	float m_lastX = SCR_WIDTH / 2.f;
	float m_lastY = SCR_HEIGHT / 2.f;
	bool m_firstMouse = true;

	float m_deltaTime = 0.f;
	float m_lastFrame = 0.f;

	GLuint m_QuadVA, m_QuadVB, m_QuadIB;
};