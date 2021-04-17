#include "pch.h"
#include "RPG_Renderer.h"
#include "Renderer.h"
#include "..\RPG.Infrastructure\WindowsAdapter.h"

IRenderer* GetRenderer()
{
    auto windowsAdapter = std::make_shared<WindowsAdapter>();

    static Renderer renderer(windowsAdapter);

    return &renderer;
}
