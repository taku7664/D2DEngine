#pragma once
#include "WindowInfo.h"


class Window final
    : public WindowInfo
{

public:
    Window();
    virtual ~Window();

    void Initialize(HINSTANCE _hInstance, const WCHAR* _title, float _sizeX, float _sizeY);
    void Release();

    HWND      GetHandle() const { return m_handle; }
    HINSTANCE GetHInstace() const { return m_hInstance; }
private:
    HINSTANCE    m_hInstance;
    HWND         m_handle;
    WNDCLASS     m_class;

    static void SetScreenToCenter(HWND _hwnd);
    static LRESULT CALLBACK WinProc(HWND _hwnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

    void Create();
    void Show();
    void Register();

};

