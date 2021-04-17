#pragma once

template<class T> inline std::shared_ptr<T> make_shared_mock(fakeit::Mock<T>& mock)
{
	return std::shared_ptr<T>(&mock.get(), [](void* ptr) {});
}