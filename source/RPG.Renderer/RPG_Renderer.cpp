#include "pch.h"
#include "RPG_Renderer.h"
#include "Renderer.h"

IRenderer* GetRenderer()
{
    static Renderer renderer;

    return &renderer;
}
