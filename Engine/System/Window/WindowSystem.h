#pragma once

class Window;
class Console;
class DialogWindow;
class WindowData;
class ConsoleData;
class DialogWindowData;

namespace Engine
{
	class WindowBase;
	class WindowCore;
	class ConsoleCore;
	class DialogWindowCore;
	class WindowSystem
	{
	public:
		static void Render();
		static bool RegisterAndShowWindow(WindowData& _windowData, WindowCore** _window);
		static bool RegisterAndShowConsole(ConsoleData& _consoleData, ConsoleCore** _console);
		static bool IsActiveConsole() { return m_activeConsole != nullptr; }
		// Proc
		static LRESULT CALLBACK WinProc(HWND _hwnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);
	private:
		static WindowBase*				   m_focusWindow;
		static ConsoleCore*			       m_activeConsole;
		static std::map<HWND, WindowBase*> m_hwndWindowTable;
		static std::map<std::wstring, WindowCore*> m_windows;
		friend Engine::WindowBase;
	};
}