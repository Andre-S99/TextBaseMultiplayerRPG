#include "pch.h"
#include "..\RPG.Renderer\RPG_Renderer.h"

int main()
{
    auto renderer = GetRenderer();

    renderer->NewFrame();

    return 0;
}

