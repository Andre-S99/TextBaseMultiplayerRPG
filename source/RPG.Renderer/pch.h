#ifndef PCH_H
#define PCH_H

#include "framework.h"

#include <Windows.h>

#undef min
#undef max

#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstdint>
#include <exception>
#include <memory>

#define FRIEND_TEST(test_case_name, test_name)\
friend class test_case_name##_##test_name##_Test

#endif 
