// If the future DB changes to PostgreSQL, you must modify Application.
// That means the high-level module depends on low-level details,
// which violates the Dependency Inversion Principle (DIP).
//
// Disadvantages of this approach:
// 1. Tight coupling between Application and MySQLDatabase.
// 2. Harder to switch to another database implementation.
// 3. Testing becomes difficult because you cannot easily replace the database with a mock.
// 4. Code is less flexible and harder to maintain as the project grows.

#include<iostream>
using namespace std;

// Low-level module: a concrete database implementation.
class MySQLDatabase
{
    public:
    void connect()
    {
        cout << "Connect to MySQl" << "\n";
    }
};

class Application
{
    // High-level module directly depends on a concrete class.
    // This is the "without DIP" part: no abstraction is used here.
    MySQLDatabase db; // tightly coupled
    public:
    void start()
    {
        // Application can only work with MySQLDatabase as written.
        db.connect();
    }

};

int main()
{
    // Application creates and uses the fixed database dependency.
    Application app;
    app.start();
    return 0;
}
