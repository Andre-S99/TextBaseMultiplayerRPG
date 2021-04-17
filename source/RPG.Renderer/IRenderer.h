#pragma once

class IRenderer
{
public:
	virtual ~IRenderer() = default;

	virtual void InitScreenBuffer(uint16_t width, uint16_t height) = 0;
	virtual void Clear() = 0;
	virtual void Draw(std::vector<wchar_t> buffer) = 0;
	virtual void NewFrame() = 0;
};