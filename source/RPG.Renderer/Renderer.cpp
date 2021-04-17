#include "pch.h"
#include "Renderer.h"

Renderer::Renderer(std::shared_ptr<IWindowsAdapter> windowsAdapter)
    : windowsAdapter(windowsAdapter)
{
}

void Renderer::InitScreenBuffer(uint16_t width, uint16_t height)
{
    screenWidth = width;
    screenHeight = height;

    totalScreenSize = width * height;

    screenBuffer = std::vector<wchar_t>(totalScreenSize, ' ');

    screenBufferHandle = windowsAdapter->CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);

    if (screenBufferHandle == INVALID_HANDLE_VALUE)
        throw std::exception("Failed to init screen buffer");

    if (!windowsAdapter->SetConsoleActiveScreenBuffer(screenBufferHandle))
        throw std::exception("Failed to set active screen buffer");
}

void Renderer::Clear()
{
    throw std::exception(__FUNCTION__" not implemented");
}

void Renderer::Draw(std::vector<wchar_t> buffer)
{
    throw std::exception(__FUNCTION__" not implemented");
}

void Renderer::NewFrame()
{
    throw std::exception(__FUNCTION__" not implemented");
}