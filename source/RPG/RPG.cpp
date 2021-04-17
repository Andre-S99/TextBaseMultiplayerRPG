#include "pch.h"
#include "..\RPG.Renderer\RPG_Renderer.h"

int main()
{
    auto renderer = GetRenderer();

    renderer->InitScreenBuffer(20, 20);

    return 0;
}

