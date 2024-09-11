#pragma once
#include "Window.h"
#ifdef _D2D1_H_
#include "Renderer/D2DRenderer.h"
#endif
#ifdef _D3D1_H_
#include "Renderer/D3DRenderer.h"
#endif
class Window;

namespace Engine
{
    class WindowSystem;

    class WindowCore final
        : public ::Window
    {
    public:
        WindowCore() = default;
        virtual ~WindowCore();

        void Initialize();
        virtual void Render() override;

        Renderer::IRenderer* GetRenderer() const { return m_renderer; }
    private:
        WNDCLASS             m_class = {};
        Renderer::IRenderer* m_renderer = nullptr;

        friend class Engine::WindowSystem;
    };
}
