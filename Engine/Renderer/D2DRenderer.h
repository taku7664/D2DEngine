#pragma once
#include "IRenderer.h"

namespace Renderer
{
	class D2DRenderer : public IRenderer
	{
	public:
		virtual bool Initialize(Engine::WindowCore* _window) override;
		virtual void Release() override;

		virtual void Clear() override;
		virtual void Clear(ColorF _color) override;
		virtual void BeginRender() override;
		virtual void EndRender() override;
	private:
		Engine::WindowCore* m_ownerWindow;

		ID2D1Factory* m_factory;
		IDWriteFactory* m_writeFactory;
		IWICImagingFactory* m_imgFactory;
		ID2D1DeviceContext* m_deviceContext;
		IDWriteTextFormat* m_textFormat;
		ID2D1SolidColorBrush* m_defaultBrush;
	};
}
