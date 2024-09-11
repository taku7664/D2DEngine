#pragma once
#include "Window.h"
#include "Renderer/D3DRenderer.h"

class Window;
class Renderer::D3DRenderer;

namespace Engine
{
    class WindowSystem;

    class WindowCore final
        : public ::Window
    {
    public:
        WindowCore() = default;
        virtual ~WindowCore();

        virtual void Render() override;

        Renderer::D3DRenderer* GetRenderer() const { return m_renderer; }
    private:
        WNDCLASS             m_class = {};
        Renderer::D3DRenderer* m_renderer = nullptr;

        friend class Engine::WindowSystem;
    };
}
