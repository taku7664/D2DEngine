#pragma once
#include "IRenderer.h"

namespace Renderer
{
	class D2DRenderer : public IRenderer
	{
	public:
		virtual bool Initialize(Engine::WindowCore*& _window) override;
		virtual void Release() override;

		virtual void Clear() override;
		virtual void Clear(ColorF _color) override;
		virtual void BeginRender() override;
		virtual void EndRender() override;
	private:
		static Engine::WindowCore*& m_ownerWindow;
		//static ID2D1Factory* m_factory;
		//static IDWriteFactory* m_writeFactory;
		//static IWICImagingFactory* m_imgFactory;
		//static ID2D1HwndRenderTarget* m_renderTarget;
		//static IDWriteTextFormat* m_textFormat;
		//static ID2D1SolidColorBrush* m_brush;
		//static ID2D1DeviceContext* m_deviceContext;
	};
}
