#include "../exercise.h"
#include <utility> // For std::move

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

    // Move constructor
    DynFibonacci(DynFibonacci &&other) noexcept 
        : cache(other.cache), cached(other.cached) {
        other.cache = nullptr;
        other.cached = 0;
    }

    // Move assignment operator
    DynFibonacci &operator=(DynFibonacci &&other) noexcept {
        if (this != &other) {
            delete[] cache; // Release current resource
            cache = other.cache;
            cached = other.cached;
            other.cache = nullptr;
            other.cached = 0;
        }
        return *this;
    }

    // Destructor
    ~DynFibonacci() {
        delete[] cache;
    }

    // Accessor
    size_t operator[](int i) {
        ASSERT(i < cached, "Index out of bounds");
        return cache[i];
    }

    // Const accessor
    size_t operator[](int i) const {
        ASSERT(i <= cached, "i out of range");
        return cache[i];
    }

    // Check if the object is alive
    bool is_alive() const {
        return cache != nullptr;
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci const fib_ = std::move(fib);
    ASSERT(!fib.is_alive(), "Object moved");
    ASSERT(fib_[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci fib0(6);
    DynFibonacci fib1(12);

    fib0 = std::move(fib1);
    fib0 = std::move(fib0);
    ASSERT(fib0[10] == 55, "fibonacci(10) should be 55");

    return 0;
}
