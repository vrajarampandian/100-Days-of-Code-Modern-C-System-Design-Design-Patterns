#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() = 0;

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark\n";
    }
};

int main() {
    Animal* a = new Dog();

    a->sound();

    delete a;
}