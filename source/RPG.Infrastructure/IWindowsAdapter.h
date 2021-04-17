#pragma once

class IWindowsAdapter
{
public:
	virtual ~IWindowsAdapter() = 0;

	virtual HANDLE CreateConsoleScreenBuffer(DWORD dwDesiredAccess, DWORD dwShareMode, SECURITY_ATTRIBUTES* lpSecurityAttributes, DWORD dwFlags, LPVOID lpScreenBufferData) = 0;
	virtual BOOL SetConsoleActiveScreenBuffer(HANDLE hConsoleOutput) = 0;
};



