#pragma once

#include "IWindowsAdapter.h"

class WindowsAdapter : public IWindowsAdapter
{
public:
	virtual HANDLE CreateConsoleScreenBuffer(DWORD dwDesiredAccess, DWORD dwShareMode, SECURITY_ATTRIBUTES* lpSecurityAttributes, DWORD dwFlags, LPVOID lpScreenBufferData) override;
	virtual BOOL SetConsoleActiveScreenBuffer(HANDLE hConsoleOutput) override;
	virtual BOOL WriteConsoleOutputCharacterW(HANDLE hConsoleOutput, LPCWSTR lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten) override;
};