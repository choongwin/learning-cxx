#include "../exercise.h"
#include <array>
#include <cstring>

// READ: std::array <https://zh.cppreference.com/w/cpp/container/array>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::array<int, 5> arr{{1, 2, 3, 4, 5}};
        ASSERT(arr.size() == 5, "Fill in the correct value."); // Size is 5
        ASSERT(sizeof(arr) == sizeof(int) * 5, "Fill in the correct value."); // Size of the array object in bytes
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(arr.data(), ans, sizeof(ans)) == 0, "Fill in the correct values."); // Compare array data to array data
    }
    {
        std::array<double, 8> arr{};
        ASSERT(arr.size() == 8, "Fill in the correct value."); // Size is 8
        ASSERT(sizeof(arr) == sizeof(double) * 8, "Fill in the correct value."); // Size of the array object in bytes
    }
    {
        std::array<char, 21> arr{"Hello, InfiniTensor!"};
        ASSERT(arr.size() == 21, "Fill in the correct value."); // Size is 21, including null terminator
        ASSERT(sizeof(arr) == sizeof(char) * 21, "Fill in the correct value."); // Size of the array object in bytes
        ASSERT(std::strcmp(arr.data(), "Hello, InfiniTensor!") == 0, "Fill in the correct value."); // Compare array data to string literal
    }
    return 0;
}
