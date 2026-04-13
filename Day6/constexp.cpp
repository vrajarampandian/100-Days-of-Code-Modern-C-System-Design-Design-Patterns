/*
Day 6: constexpr example
*/

#include <iostream>
#include <type_traits>
using namespace std;

// constexpr allows this function to run at compile time
// when the input is known during compilation.
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

template <typename T>
void printType(T value) {
    // if constexpr checks the condition at compile time.
    // For integral types like int, long, char it prints "Integer".
    // For non-integral types like float or double it prints "Other".
    if constexpr (is_integral<T>::value) {
        cout << value << " is an Integer\n";
    } else {
        cout << value << " is Other\n";
    }
}

int main() {
    // factorial(5) is evaluated at compile time because
    // the argument is a constant expression.
    constexpr int val = factorial(5);

    cout << "Factorial: " << val << endl;
    
    // Calling printType with different values to show
    // how if constexpr selects the correct branch.
    printType(42);
    printType(3.14);

    return 0;
}
