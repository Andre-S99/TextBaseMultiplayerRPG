#pragma once

class IRenderer
{
public:
	virtual ~IRenderer() = default;

	virtual void InitScreenBuffer(uint16_t width, uint16_t height) = 0;
	virtual void Clear(wchar_t character) = 0;
	virtual void Draw(const std::vector<wchar_t>& buffer) = 0;
	virtual void NewFrame() = 0;
};