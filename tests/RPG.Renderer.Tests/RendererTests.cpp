#include "pch.h"
#include "..\..\source\RPG.Renderer\Renderer.h"
#include "..\..\source\RPG.Infrastructure\IWindowsAdapter.h"

TEST(Renderer, InitScreenBuffer_Should_Be_Ok)
{
    Mock<IWindowsAdapter> windowsAdapterMock;
    auto windowsAdapter = make_shared_mock(windowsAdapterMock);

    HANDLE fakeHandle = (void*)90;
    When(Method(windowsAdapterMock, CreateConsoleScreenBuffer).Using(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr))
        .Return(fakeHandle);

    When(Method(windowsAdapterMock, SetConsoleActiveScreenBuffer).Using(fakeHandle))
        .Return(true);

    Renderer renderer(windowsAdapter);

    uint16_t width = 20;
    uint16_t height = 40;

	renderer.InitScreenBuffer(width, height);

    size_t expectedBufferSize = width * height;

    ASSERT_EQ(renderer.screenWidth, width);
    ASSERT_EQ(renderer.screenHeight, height);
    ASSERT_EQ(renderer.totalScreenSize, expectedBufferSize);
    ASSERT_EQ(renderer.screenBuffer.size(), expectedBufferSize);
    ASSERT_EQ(renderer.screenBufferHandle, fakeHandle);

    Verify(Method(windowsAdapterMock, CreateConsoleScreenBuffer).Using(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr))
        .Once();

    Verify(Method(windowsAdapterMock, SetConsoleActiveScreenBuffer).Using(fakeHandle))
        .Once();

    VerifyNoOtherInvocations(windowsAdapterMock);
}

TEST(Renderer, InitScreenBuffer_Should_Throw_Exception_When_It_Fails_To_Create_Console_Buffer)
{
    Mock<IWindowsAdapter> windowsAdapterMock;
    auto windowsAdapter = make_shared_mock(windowsAdapterMock);

    When(Method(windowsAdapterMock, CreateConsoleScreenBuffer).Using(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr))
        .Return(INVALID_HANDLE_VALUE);

    Renderer renderer(windowsAdapter);

    try
    {
        renderer.InitScreenBuffer(20, 20);
        FAIL();
    }
    catch (const std::exception&)
    {
    }
    catch(...)
    {
        FAIL();
    } 

    Verify(Method(windowsAdapterMock, CreateConsoleScreenBuffer).Using(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr))
        .Once();

    VerifyNoOtherInvocations(windowsAdapterMock);
}

TEST(Renderer, InitScreenBuffer_Should_Throw_Exception_When_It_Fails_To_Set_Console_Buffer)
{
    Mock<IWindowsAdapter> windowsAdapterMock;
    auto windowsAdapter = make_shared_mock(windowsAdapterMock);

    HANDLE fakeHandle = (void*)90;
    When(Method(windowsAdapterMock, CreateConsoleScreenBuffer).Using(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr))
        .Return(fakeHandle);

    When(Method(windowsAdapterMock, SetConsoleActiveScreenBuffer).Using(fakeHandle))
        .Return(false);

    Renderer renderer(windowsAdapter);

    try
    {
        renderer.InitScreenBuffer(20, 20);
        FAIL();
    }
    catch (const std::exception&)
    {
    }
    catch (...)
    {
        FAIL();
    }

    Verify(Method(windowsAdapterMock, CreateConsoleScreenBuffer).Using(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr))
        .Once();

    Verify(Method(windowsAdapterMock, SetConsoleActiveScreenBuffer).Using(fakeHandle))
        .Once();

    VerifyNoOtherInvocations(windowsAdapterMock);
}