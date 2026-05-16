#include<iostream>
using namespace std;

// Existing class with an incompatible interface.
// It provides temperature in Fahrenheit.
class FahrenheitSensor 
{
    public:
    double getFahrenheit()
    {
        return 98.0;
    }
};

// Target interface expected by the client code.
// The adapter will implement this interface.
class CelsiusSensor 
{
    public:
    virtual double getFahrenheit() = 0;
    virtual ~CelsiusSensor() = default;
};

// Adapter converts the FahrenheitSensor output into Celsius
// while exposing the interface expected by CelsiusSensor.
class Adapter : public CelsiusSensor
{
    FahrenheitSensor sensor;
    public:
    double getFahrenheit() override
    {
        // Convert Fahrenheit to Celsius.
        return (sensor.getFahrenheit() - 32) * 5 /9;
    }
};

int main()
{
    // Client code works with the target interface.
    CelsiusSensor *sensor = new Adapter();

    // Internally, Adapter uses FahrenheitSensor and converts the result.
    cout << sensor->getFahrenheit() << "\n";

    delete sensor;
    return 0;
}
