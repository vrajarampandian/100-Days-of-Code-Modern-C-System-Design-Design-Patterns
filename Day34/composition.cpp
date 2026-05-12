#include<iostream>
using namespace std;

class Engine
{
    public:
    void start()
    {
        cout << "Engine Started\n";
    }
};

class Car
{
    private:
    Engine engine; // composition
    public:
    void drive()
    {
        engine.start();
        cout << "car driving\n";
    }
};

int main()
{
    Car c;
    c.drive();
    return 0;
}