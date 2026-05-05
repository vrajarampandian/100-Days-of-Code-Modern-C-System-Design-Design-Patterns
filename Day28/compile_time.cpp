#include <iostream>
#include <type_traits>
using namespace std;

template<typename T>
void func(T x) {
    if constexpr (is_integral_v<T>) {
        cout << x << " is an Integer\n";
    } else {
        cout << x << " is Other\n";
    }
}

int main() {
    func(42);
    func(3.14);
    func("hello");
}
