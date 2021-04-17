#include "pch.h"
#include "..\..\source\RPG.Renderer\Renderer.h"

TEST(Renderer, InitScreenBuffer_Should_Be_Ok)
{
	Renderer renderer;

	renderer.InitScreenBuffer(20, 20);
}