#include<iostream>
#include<initializer_list>
#include<vector>
using namespace std;

/*
Notes:
- Brace initialization uses {} and helps avoid narrowing conversions.
- For a class, a matching initializer_list constructor is preferred when using braces.
- vector<int> v1(5) creates 5 elements, while vector<int> v2{5} creates 1 element with value 5.
- initializer_list is read-only; it is useful when a function or constructor accepts a variable number of values.
*/
class A
{
    public:
    A(int a)
    {
        cout << "Constructor:" << a << "\n";
    }
    A(initializer_list<int> values) {
        cout << "Initializer list:";
        for (int value : values)
        {
            cout << " " << value;
        }
        cout << "\n";
    }
};

int main()
{
    int a {10};
    cout << a << "\n";

    // Brace initialization catches narrowing conversions at compile time.
    //int b {30.5};

    vector<int> v1(5);
    cout << v1.size() << "\n";

    vector<int> v2{5};
    cout << v2.size() << "\n";

    A objA(10);
    A objB{30};
    A objC{10, 20, 30};

    return 0;
}
