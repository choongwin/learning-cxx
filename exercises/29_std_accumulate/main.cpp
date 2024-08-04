#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};

    // Calculate the total number of elements in the tensor
    int num_elements = std::accumulate(std::begin(shape), std::end(shape), 1, std::multiplies<int>());

    // Calculate the size of each element in bytes
    int element_size = sizeof(DataType);

    // Calculate the total size in bytes
    int size = num_elements * element_size;

    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
