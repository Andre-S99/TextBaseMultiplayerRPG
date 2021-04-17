#pragma once

#include "IRenderer.h"
#include "..\RPG.Infrastructure\IWindowsAdapter.h"

class Renderer : public IRenderer
{
public:
	virtual void InitScreenBuffer(uint16_t width, uint16_t height) override;
	virtual void Clear(wchar_t character) override;
	virtual void Draw(const std::vector<wchar_t>& buffer) override;
	virtual void NewFrame() override;

private:
	std::vector<wchar_t> screenBuffer;

	uint16_t screenWidth = 0;
	uint16_t screenHeight = 0;
	uint32_t totalScreenSize = 0;

	HANDLE screenBufferHandle = nullptr;

	std::shared_ptr<IWindowsAdapter> windowsAdapter;

private:
	Renderer(std::shared_ptr<IWindowsAdapter> windowsAdapter);
	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) = delete;
	Renderer& operator=(const Renderer&) = delete;
	Renderer& operator=(Renderer&&) = delete;

	friend IRenderer* GetRenderer();

private:
	FRIEND_TEST(Renderer, InitScreenBuffer_Should_Be_Ok);
	FRIEND_TEST(Renderer, InitScreenBuffer_Should_Throw_Exception_When_It_Fails_To_Create_Console_Buffer);
	FRIEND_TEST(Renderer, InitScreenBuffer_Should_Throw_Exception_When_It_Fails_To_Set_Console_Buffer);
	FRIEND_TEST(Renderer, Clear_Should_Clear_RenderBuffer);
};