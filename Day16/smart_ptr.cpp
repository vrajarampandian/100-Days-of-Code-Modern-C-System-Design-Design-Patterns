#include<iostream>
#include<memory>
using namespace std;

int main()
{
    unique_ptr<int> a = make_unique<int>(10);
    shared_ptr<int> s = make_shared<int>(20);
    shared_ptr<int> s1 = s;

    cout << "Shared Pointer count" << s1.use_count() << "\n";
    
    weak_ptr<int> w = s1;

    if(auto t = w.lock())
    {
        cout << "Weak ptr:" << *t << "\n";
    }

    return 0;
}