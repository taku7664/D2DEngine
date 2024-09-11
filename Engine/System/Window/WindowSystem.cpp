#include "pch.h"
#include "WindowSystem.h"
#include "Window/Window/WindowCore.h"
#include "Window/Console/ConsoleCore.h"
#include "Window/DialogBox/DialogWindowCore.h"
#include "Application.h"
#include "Renderer/D3DRenderer.h"

namespace Engine
{
	std::map<HWND, WindowBase*> WindowSystem::m_hwndWindowTable = {};
	std::map<std::wstring, WindowCore*> WindowSystem::m_windows = {};
	ConsoleCore*				WindowSystem::m_activeConsole = nullptr;
	WindowBase*		   		    WindowSystem::m_focusWindow  = nullptr;

	void WindowSystem::Render()
	{
		for (auto window : m_windows)
		{
			window.second->Render();
		}
	}

	bool WindowSystem::RegisterAndShowWindow(WindowData& _windowData, WindowCore** _window)
	{
		(*_window) = new WindowCore();
		(*_window)->m_class = std::move(_windowData.m_class);
		(*_window)->m_title = std::move(_windowData.m_title);
		(*_window)->m_class.lpszClassName = (*_window)->m_title;
		(*_window)->m_windowPosition = std::move(_windowData.m_windowPosition);
		(*_window)->m_windowSize = std::move(_windowData.m_windowSize);

		if (!RegisterClass(&(*_window)->m_class)) {
			return false;
		}

		RECT rect = { 0, 0
			, static_cast<LONG>((*_window)->m_windowSize.x)
			, static_cast<LONG>((*_window)->m_windowSize.y) };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
		const LONG width = rect.right - rect.left;
		const LONG height = rect.bottom - rect.top;

		HINSTANCE hInstance = *Application::Instance;

		(*_window)->m_handle = CreateWindow(
			(*_window)->m_title,
			(*_window)->m_title,
			WS_OVERLAPPEDWINDOW,
			rect.left, rect.top, width, height,
			NULL, NULL, hInstance, NULL);

		if ((*_window)->m_handle) 
		{
			ShowWindow((*_window)->m_handle, SW_SHOWNORMAL);
			UpdateWindow((*_window)->m_handle);
			(*_window)->m_renderer = new Renderer::D3DRenderer();
			(*_window)->m_renderer->Initialize((*_window));
			(*_window)->SetPositionCenter();
			m_focusWindow = (*_window);
			m_hwndWindowTable.insert(std::make_pair((*_window)->m_handle, (*_window)));
			m_windows.insert(std::make_pair((*_window)->m_title, (*_window)));
			return true;
		}
		else
		{
			return false;
		}
	}

	bool WindowSystem::RegisterAndShowConsole(ConsoleData& _consoleData, ConsoleCore** _console)
	{
		if (!m_activeConsole)
		{
			if (AllocConsole())
			{
				(*_console) = new ConsoleCore();
				SetConsoleTitleW(_consoleData.m_title);
				(*_console)->m_inputHandle = GetStdHandle(STD_INPUT_HANDLE);
				(*_console)->m_outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				(*_console)->m_handle = GetConsoleWindow();
				m_activeConsole = (*_console);
				return true;
			}
		}
		return false;
	}

	LRESULT CALLBACK WindowSystem::WinProc(HWND _hwnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)
	{
		WindowBase* handler = nullptr;
		auto windowIter = m_hwndWindowTable.find(_hwnd);
		if (windowIter != m_hwndWindowTable.end())
		{
			handler = windowIter->second;
		}
		switch (_msg)
		{
		case WM_CREATE:
			break;

		case WM_SIZE:
			if (handler)
			{
				RECT windowRect; GetWindowRect(_hwnd, &windowRect);
				handler->m_windowSize.x = static_cast<float>(windowRect.right - windowRect.left);
				handler->m_windowSize.y = static_cast<float>(windowRect.bottom - windowRect.top);
				Console::Log(L"Window Resizing (", handler->m_title, " - x : " ,handler->m_windowSize.x,
					", y : ", handler->m_windowSize.y, ")\n");
			}
			break;

		case WM_MOVE:
			if (handler)
			{
				RECT windowRect; GetWindowRect(_hwnd, &windowRect);
				handler->m_windowPosition.x = static_cast<float>(windowRect.left);
				handler->m_windowPosition.y = static_cast<float>(windowRect.top);
				Console::Log(L"Window Moving (", handler->m_title, " - x : ", handler->m_windowPosition.x,
					", y : ", handler->m_windowPosition.y, ")\n");
			}
			break;

		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
			if (_wParam == VK_MENU)
				return 0;
			break;

		case WM_SETFOCUS:
			if (handler)
			{
				m_focusWindow = handler;
				Console::Log("Window Forcus (", handler->m_title, ")\n");
			}
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			Application::Quit();
			break;

		default:
			return DefWindowProc(_hwnd, _msg, _wParam, _lParam);
		}
		return 0;
	}
}
