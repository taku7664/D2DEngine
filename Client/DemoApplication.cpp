#include "DemoApplication.h"

void DemoApplication::Initialize()
{
	InitializeWindow();
}

void DemoApplication::InitializeWindow()
{
	WindowData  mainWindow;
	WindowData  subWindow;
	ConsoleData console;

	mainWindow.
		InitializeTitle(TITLE).
		InitializeSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	subWindow.
		InitializeTitle(L"SubWindow").
		InitializeSize(800, 600);

	console.
	InitializeTitle(TITLE).
	InitializeSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	if (!processCore->CreateWindows(mainWindow))
	{
		Application::Quit();
	}
	if (!processCore->CreateWindows(subWindow))
	{
		Application::Quit();
	}
	if (!processCore->CreateConsole(console))
	{
		Application::Quit();
	}
}