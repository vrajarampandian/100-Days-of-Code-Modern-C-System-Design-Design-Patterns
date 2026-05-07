#include<iostream>
using namespace std;

class Base
{
    public:
    // With virtual: the function call is decided at runtime.
    // Since b points to a Derived object, Derived::show() will run.
    // Without virtual: Base::show() would run because b is a Base pointer.
    virtual void show()
    {
        cout << "Call Base::SHOW" << "\n";
    }
};

class Derived : public Base
{
    public:
    // This overrides Base::show() when Base::show() is virtual.
    void show()
    {
        cout << "call Derived::SHow" << "\n"; 
    }
};

int main()
{
    Derived d;
    Base *b = &d;
    // Calls Derived::show() because show() is virtual in Base.
    // Try removing 'virtual' above: then this line calls Base::show().
    b->show();
    return 0;
}
