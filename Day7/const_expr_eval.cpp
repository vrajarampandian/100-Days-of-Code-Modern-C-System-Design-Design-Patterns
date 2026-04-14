#include<iostream>
using namespace std;

// Normal function: runs at runtime.
const int square(int a)
{
    return a * a;
}

// Can run at compile time or runtime.
constexpr int square1(int a)
{
    return a * a;
}

// Must run at compile time.
// consteval int square2(int a)
// {
//     return a * a;
// }

int main()
{
    // Normal runtime variable.
    int a = 5;

    // Runtime call.
    int normal = square(a);

    // Runtime: argument is not constant.
    int r1 = square1(a);

    // Also runtime.
    int r2 = square1(a);

    // Compile-time: constant argument.
    int r3 = square1(5);

    // Compile-time only.
    //int r4 = square2(5);

    // Error: runtime argument not allowed.
    // int r5 = square2(a);

    cout << " " << r1 << " " << r2 << " " << r3 << " ";
    return 0;
}
