#pragma once
#include "Window/Window/WindowCore.h"
#include "Window/Console/ConsoleCore.h"
#include "Window/DialogBox/DialogWindowCore.h"
#include "System/Window/WindowSystem.h"

class GameManager
{
	class WorldManager
	{
	public:
		//World* operator [](std::wstring_view _key);
	};

	class WindowManager
	{
	public:
		Console* GetConsole() { return Engine::WindowSystem::GetConsole(); }
		Window* GetMainWindow() { return Engine::WindowSystem::GetMainWindow(); }
		Window* GetWindow(const std::wstring& _name) { return Engine::WindowSystem::GetWindow(_name); }
	};
public:
	static WorldManager world;
	static WindowManager window;
private:
	
};

