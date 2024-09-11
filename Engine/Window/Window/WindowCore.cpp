#include "pch.h"
#include "WindowCore.h"
#include "System/Window/WindowSystem.h"

namespace Engine
{
	WindowCore::~WindowCore()
	{
	}
	void WindowCore::Initialize()
	{
#ifdef _D2D1_H_
		m_renderer = new Renderer::D2DRenderer();
#endif
#ifdef _D3D1_H_
		m_renderer = new Renderer::D3DRenderer();
#endif
		m_renderer->Initialize(this);
		SetPositionCenter();
	}
	void WindowCore::Render()
	{
		m_renderer->BeginRender();
		m_renderer->Clear();

		m_renderer->EndRender();
	}
}