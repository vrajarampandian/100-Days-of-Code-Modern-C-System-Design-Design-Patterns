#include<iostream>
using namespace std;

class Base
{
    public:
    int x = 10;
};
class Derived : public Base
{
    public:
    int y = 20;
};

int main()
{
    Derived d;

    // A Base pointer can point to a Derived object.
    // But using Base*, only Base members are directly accessible.
    Base *b = &d;
    cout << b->x << "\n";

    // Not allowed: y belongs to Derived, not Base.
    // cout << b->y << "\n";

    // Cast back to Derived* only when the object is really Derived.
    Derived *db = static_cast<Derived*>(b);
    cout << db->y << "\n";
    return 0;
}
