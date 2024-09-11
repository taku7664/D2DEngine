#pragma once
#include "Window/Window/WindowCore.h"
#include "Window/Console/ConsoleCore.h"
#include "Core/WorldCore.h"

class Window;
class WindowData;

namespace Engine
{
	class WindowCore;
	
	class ProcessCore final
		: public ILifeCycle
	{
	public:
		ProcessCore() = default;
		~ProcessCore();

		void Initialize();
		void Run();
		void Release();

		virtual void FixedUpdate() override;
		virtual void PreUpdate() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(WindowCore* _window) override;
	private:
		WorldCore* m_worldCore;
		WindowCore*  m_window = nullptr;
		ConsoleCore* m_console = nullptr;
	public:
		bool CreateWindows(WindowData& _windowData);
		bool CreateConsole(ConsoleData& _consoleData);
		bool DestroyWindows();
		::Window*  GetWindow() { return m_window; }
		::Console* GetConsole() { return m_console; }
	};
}