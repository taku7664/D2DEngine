#include "pch.h"
#include "Window.h"

Window::Window()
	: m_handle(nullptr)
	, m_class({})
	, m_hInstance(nullptr)
{
}

Window::~Window()
{
}

void Window::Initialize(HINSTANCE _hInstance, const WCHAR* _title, float _sizeX, float _sizeY)
{
	m_hInstance		= _hInstance;
	m_title			= _title;
	m_windowSize.x  = _sizeX;
	m_windowSize.y  = _sizeY;
	Register();
	Create();
	Show();
}

void Window::Release()
{
	if (m_handle != nullptr) {
		DestroyWindow(m_handle);
		m_handle = nullptr;
	}
	delete this;
}

void Window::Register()
{
	m_class = {};
	m_class.style = CS_HREDRAW | CS_VREDRAW;
	m_class.lpfnWndProc = WinProc;
	m_class.cbClsExtra = NULL;
	m_class.cbWndExtra = NULL;
	m_class.hInstance = m_hInstance;
	m_class.hIcon = LoadIcon(m_hInstance, IDI_APPLICATION);
	m_class.hCursor = LoadCursor(NULL, IDC_ARROW);
	m_class.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	m_class.lpszMenuName = NULL;
	m_class.lpszClassName = m_title;

	RegisterClass(&m_class);
}

void Window::Create()
{
	RECT rect = { 0, 0, m_windowSize.x, m_windowSize.y };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
	const LONG width = rect.right - rect.left;
	const LONG height = rect.bottom - rect.top;

	m_handle = CreateWindow(
		m_class.lpszClassName,
		m_class.lpszClassName,
		WS_OVERLAPPEDWINDOW,
		rect.left, rect.top, width, height,
		NULL, NULL, m_hInstance, NULL);

	if (!m_handle) {
		MessageBox(nullptr, L"Window creation failed!", L"Error", MB_ICONERROR);
	}
}

void Window::Show()
{
	ShowWindow(m_handle, SW_SHOWNORMAL);
	UpdateWindow(m_handle);
}

void Window::SetScreenToCenter(HWND _hwnd)
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	RECT windowRect; 
	GetWindowRect(_hwnd, &windowRect);

	int windowWidth = windowRect.right - windowRect.left;
	int windowHeight = windowRect.bottom - windowRect.top;

	SetWindowPos(_hwnd, NULL,
		(screenWidth - windowWidth) * 0.5f,
		(screenHeight - windowHeight) * 0.5f,
		0, 0, SWP_NOZORDER | SWP_NOSIZE
	);
}

LRESULT CALLBACK Window::WinProc(HWND _hwnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)
{
	switch (_msg)
	{
	case WM_CREATE:
		SetScreenToCenter(_hwnd);
		break;

	case WM_SIZE:
		break;

	case WM_MOVE:
		break;
	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
		if (_wParam == VK_MENU)
			return 0;
		break;

	case WM_LBUTTONDOWN:
		break;

	case WM_LBUTTONUP:
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(_hwnd, _msg, _wParam, _lParam);
	}
	return 0;
}
