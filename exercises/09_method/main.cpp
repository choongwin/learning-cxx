#include "../exercise.h"
#include <iostream>

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // Constructor to initialize the cache and the cached index
    Fibonacci() : cached(1) {
        cache[0] = 0;
        cache[1] = 1;
    }

    // Method to calculate Fibonacci numbers with caching
    unsigned long long get(int i) {
        // Update the cache up to the required Fibonacci number
        for (; cached < i; ++cached) {
            cache[cached + 1] = cache[cached] + cache[cached - 1];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // Initialize the Fibonacci structure
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
