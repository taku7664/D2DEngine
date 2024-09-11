#include "pch.h"
#include "D2DRenderer.h"
#include "Window/Window/WindowCore.h"

namespace Renderer
{
	bool D2DRenderer::Initialize(Engine::WindowCore* _window)
	{
		m_ownerWindow = _window;

		HRESULT check;

		check = CoInitialize(NULL);

		// ���丮 �ʱ�ȭ
		check = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory);
		if (FAILED(check)) return false;

		check = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&m_writeFactory));
		if (FAILED(check)) return false;

		// Create WIC factory
		check = CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(&m_imgFactory));
		// ����Ÿ�� ����
		RECT rc;
		GetClientRect(*m_ownerWindow, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top);

		ID2D1HwndRenderTarget* renderTarget = nullptr;

		check = m_factory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(*m_ownerWindow, size),
			&renderTarget);
		if (FAILED(check))
			assert(false);

		check = renderTarget->QueryInterface(&m_deviceContext);
		if (FAILED(check)) return false;

		check = m_writeFactory->CreateTextFormat(
			L"���� ���",                        // ��Ʈ �̸�
			nullptr,                            // ��Ʈ �÷��� (nullptr�� �⺻ ��Ʈ �÷���)
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			20.0f,                              // ��Ʈ ũ��
			L"ko-kr",                           // ��Ķ(�۾� �����̸� �����̶�µ� �𸣰ڳ׿�)
			&m_textFormat);
		if (FAILED(check)) return false;

		// �⺻ �귯�� ����
		check = renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_defaultBrush);
		if (FAILED(check)) return false;

		return true;
	}
	void D2DRenderer::Release()
	{
		SAFE_RELEASE(m_factory)
		SAFE_RELEASE(m_writeFactory)
		SAFE_RELEASE(m_imgFactory)
		SAFE_RELEASE(m_deviceContext)
		SAFE_RELEASE(m_textFormat)
		SAFE_RELEASE(m_defaultBrush)
		CoUninitialize();
	}
	void D2DRenderer::Clear()
	{
		m_deviceContext->Clear(ColorF(0.0f, 0.0f, 0.0f, 1.0f));
	}
	void D2DRenderer::Clear(ColorF _color)
	{
		m_deviceContext->Clear(_color);
	}
	void D2DRenderer::BeginRender()
	{
		m_deviceContext->BeginDraw();
	}
	void D2DRenderer::EndRender()
	{
		m_deviceContext->EndDraw();
	}
}