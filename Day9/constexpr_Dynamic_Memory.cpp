#include<iostream>
using namespace std;

// C++20 allows dynamic memory inside a constexpr function.
// The allocation and deallocation must both happen during constant evaluation.
constexpr int compute()
{
    // `new` is allowed in constexpr evaluation starting in C++20.
    int *p = new int(20);
    int v = (*p) *2 ;
    // The memory must be released before the constexpr evaluation ends.
    delete p;
    return v;
}

int main()
{
    // This can be evaluated at compile time in C++20.
    constexpr int a = compute();
    cout << a << "\n";
    return 0;
}
