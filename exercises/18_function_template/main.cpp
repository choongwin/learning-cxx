#include "../exercise.h"
#include <cmath> // For std::abs

// Function template for plus
template<typename T>
T plus(T a, T b) {
    return a + b;
}

int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");

    // Use a tolerance-based check for floating-point equality
    double epsilon = 1e-10; // Tolerance for floating-point comparison
    ASSERT(std::abs(plus(0.1, 0.2) - 0.3) < epsilon, "How to make this pass?");

    return 0;
}
