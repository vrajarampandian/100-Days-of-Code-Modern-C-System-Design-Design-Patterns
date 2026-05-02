#include<iostream>
using namespace std;

class Test
{
    public:
    //explicit prevents - unintended object creation
    //hidden performance cost
    //confusing code
    explicit Test(int x)
    {
        cout << "Constructor: " << x << "\n";
    }
};

int main()
{
    //Test t = 10;
    Test t(10);
    Test t1{50};
    return 0;
}