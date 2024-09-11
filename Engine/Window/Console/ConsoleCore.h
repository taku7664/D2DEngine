#pragma once
#include "Console.h"

namespace Engine
{
	class WindowSystem;

	class ConsoleCore : public Console
	{
	public:
		virtual void Render() {};
	protected:
	private:
		friend class Engine::WindowSystem;
	};
}
