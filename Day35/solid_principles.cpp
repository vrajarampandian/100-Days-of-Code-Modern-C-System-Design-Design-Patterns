#include<iostream>
using namespace std;

// SOLID: Dependency Inversion Principle (DIP)
// High-level code should depend on abstractions, not concrete classes.
class Notification
{
    public:
    virtual void send() = 0;
};

// Concrete implementation of the Notification abstraction.
class EmailNotification : public Notification
{
    public:
    void send()
    {
        cout << "Email Notification" << "\n";
    }
};

// Another concrete implementation that can be swapped in without
// changing AlertService.
class SMSNotification :  public Notification
{
    public:
    void send()
    {
        cout << "Sms Notification" << "\n";
    }
};

class AlertService
{
    // AlertService depends on the Notification interface, not on
    // EmailNotification or SMSNotification directly.
    Notification* notify;
    public:
    AlertService(Notification *n) : notify(n) {}

    void alert()
    {
        // Runtime polymorphism chooses the correct send() implementation.
        notify->send();
    }
};

int main()
{
    SMSNotification s;
    // Injecting the dependency keeps AlertService flexible and reusable.
    AlertService A(&s);
    A.alert();
    return 0;
}
