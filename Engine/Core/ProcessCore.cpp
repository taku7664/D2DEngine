#include "pch.h"
#include "ProcessCore.h"
#include "Renderer/D3DRenderer.h"
#include "System/Window/WindowSystem.h"

namespace Engine
{
	ProcessCore::~ProcessCore()
	{
		DestroyWindows();
	}

	void ProcessCore::Initialize()
	{
	}

	void ProcessCore::Run()
	{
		MSG msg;
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Time::Update();
			Input::Update();
			FixedUpdate();
			PreUpdate();
			Update();
			LateUpdate();
			Render(m_window);
			Input::Reset();
		}
	}

	void ProcessCore::Release()
	{
	}

	void ProcessCore::FixedUpdate()
	{
	}

	void ProcessCore::PreUpdate()
	{
	}

	void ProcessCore::Update()
	{
		if (Input::IsKeyDown('A')) Console::Log("Down - A \n");
		if (Input::IsKeyHold('A')) Console::Log("Hold - A \n");
		if (Input::IsKeyUp('A')) Console::Log("Up - A \n");
	}

	void ProcessCore::LateUpdate()
	{
	}

	void ProcessCore::Render(WindowCore* _window)
	{
		/*if (_window)
		{
			_window->GetRenderer()->Clear();
			_window->GetRenderer()->BeginRender();

			_window->GetRenderer()->Draw();
			_window->GetRenderer()->EndRender();
		}*/
		WindowSystem::Render();
	}

	bool ProcessCore::DestroyWindows()
	{
		SAFE_DELETE(m_window);
		return false;
	}

	bool ProcessCore::CreateWindows(WindowData& _windowData)
	{
		return WindowSystem::RegisterAndShowWindow(_windowData, &m_window);
	}
	bool ProcessCore::CreateConsole(ConsoleData& _consoleData)
	{
		return WindowSystem::RegisterAndShowConsole(_consoleData, &m_console);
	}
}

