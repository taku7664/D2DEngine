#pragma once

using namespace DirectX::SimpleMath;

class WindowInfo
{
public:
	const WCHAR* GetWindowTitle() const { return m_title; }
	Vector2   GetWindowSize()	  const { return m_windowSize; }
	Vector2   GetWindowPosition() const { return m_windowPosition; }
protected:
	const WCHAR* m_title;
	Vector2      m_windowPosition;
	Vector2      m_windowSize;
};