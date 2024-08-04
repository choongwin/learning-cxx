#include "../exercise.h"
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

int main(int argc, char **argv) {
    std::vector<bool> vec(100, true); // Initialize a vector of 100 bools, all set to true
    ASSERT(vec[0], "Make this assertion pass."); // First element should be true
    ASSERT(vec[99], "Make this assertion pass."); // Last element should be true
    ASSERT(vec.size() == 100, "Make this assertion pass."); // Size should be 100

    // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    ASSERT(sizeof(vec) == sizeof(std::vector<bool>), "Fill in the correct value."); // The size of the vector object itself (platform dependent)

    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`."); // The 20th element should be false
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value."); // Size should be 101 after push_back
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`."); // The newly added element should be false
    }
    {
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`"); // The 30th element should be true initially
        ref = false;
        ASSERT(!ref, "Fill in `ref` or `!ref`"); // ref should be false after assignment
        // THINK: WHAT and WHY?
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`."); // The 30th element should also be false in the vector
    }
    return 0;
}
