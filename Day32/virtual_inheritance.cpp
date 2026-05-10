#include<iostream>
using namespace std;

class A {
public:
    // Shared base data.
    int x = 10;
};

// Virtual inheritance avoids duplicate A objects.
class B : virtual public A {
};

// C also shares the same A object.
class C : virtual public A {
};

// D inherits from both paths.
class D : public B, public C {
};

int main() {
    D obj;

    // Not ambiguous because A is virtual.
    cout << obj.x << endl; // ✅ OK
}
