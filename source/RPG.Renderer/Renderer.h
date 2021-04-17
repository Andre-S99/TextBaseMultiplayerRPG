#pragma once

#include "IRenderer.h"

class Renderer : public IRenderer
{
public:
	virtual void InitScreenBuffer(uint16_t width, uint16_t height) override;
	virtual void Clear() override;
	virtual void Draw(std::vector<wchar_t> buffer) override;
	virtual void NewFrame() override;

private:
	Renderer() = default;
	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) = delete;
	Renderer& operator=(const Renderer&) = delete;
	Renderer& operator=(Renderer&&) = delete;

	std::vector<wchar_t> screenBuffer;

	uint16_t screenWidth = 0;
	uint16_t screenHeight = 0;
	uint32_t totalScreenSize = 0;

	HANDLE screenBufferHandle = nullptr;

	friend IRenderer* GetRenderer();

	FRIEND_TEST(Renderer, InitScreenBuffer_Should_Be_Ok);
};