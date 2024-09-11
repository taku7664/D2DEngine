#include "pch.h"
#include "WindowCore.h"
#include "System/Window/WindowSystem.h"

namespace Engine
{
	WindowCore::~WindowCore()
	{
	}
	void WindowCore::Render()
	{
		m_renderer->Clear();
		m_renderer->BeginRender();
		m_renderer->Draw();
		m_renderer->EndRender();
	}
}