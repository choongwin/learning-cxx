#include "../exercise.h"
#include <algorithm> // For std::copy

class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // Dynamic capacity constructor
    DynFibonacci(int capacity) : cache(new size_t[capacity]()), cached(0) {
        if (capacity > 0) {
            cache[0] = 0;
            if (capacity > 1) {
                cache[1] = 1;
            }
            for (int i = 2; i < capacity; ++i) {
                cache[i] = cache[i - 1] + cache[i - 2];
            }
            cached = capacity;
        }
    }

    // Copy constructor
    DynFibonacci(DynFibonacci const &other) 
        : cache(new size_t[other.cached]), cached(other.cached) {
        std::copy(other.cache, other.cache + other.cached, cache);
    }

    // Destructor
    ~DynFibonacci() {
        delete[] cache;
    }

    // Accessor with computation (if needed)
    size_t get(int i) {
        if (i >= cached) {
            // Expand cache if necessary
            size_t *new_cache = new size_t[i + 1];
            std::copy(cache, cache + cached, new_cache);
            delete[] cache;
            cache = new_cache;
            cached = i + 1;

            for (int j = cached; j <= i; ++j) {
                cache[j] = cache[j - 1] + cache[j - 2];
            }
        }
        return cache[i];
    }

    // Const accessor
    size_t get(int i) const {
        if (i <= cached) {
            return cache[i];
        }
        ASSERT(false, "i out of range");
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    DynFibonacci const fib_ = fib;
    ASSERT(fib_.get(10) == fib.get(10), "Object cloned");
    return 0;
}
