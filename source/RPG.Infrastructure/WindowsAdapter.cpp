#include "pch.h"
#include "WindowsAdapter.h"

HANDLE WindowsAdapter::CreateConsoleScreenBuffer(DWORD dwDesiredAccess, DWORD dwShareMode, SECURITY_ATTRIBUTES* lpSecurityAttributes, DWORD dwFlags, LPVOID lpScreenBufferData)
{
	return ::CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFlags, lpScreenBufferData);
}

BOOL WindowsAdapter::SetConsoleActiveScreenBuffer(HANDLE hConsoleOutput)
{
	return ::SetConsoleActiveScreenBuffer(hConsoleOutput);
}

BOOL WindowsAdapter::WriteConsoleOutputCharacterW(HANDLE hConsoleOutput, LPCWSTR lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten)
{
	return ::WriteConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten);
}
