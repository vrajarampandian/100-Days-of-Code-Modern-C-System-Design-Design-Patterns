#include<iostream>
using namespace std;

// Abstraction: high-level and low-level modules both depend on this interface.
class Database
{
    public:
    // Every database must provide its own connection logic.
    virtual void connect() = 0;
    virtual ~Database() {}
};

// Low-level module: concrete MySQL implementation.
class MySqlDatabase : public Database
{
    public:
    void connect()
    {
        cout << "connect My Sql DB" << "\n";
    }
};

// Another low-level module: concrete PostgreSQL implementation.
class PostgreSQLDB : public Database
{
    public:
    void connect()
    {
        cout << " connect PostreSQL DB" << "\n";
    }
};

class Application
{
    // High-level module depends on abstraction, not a concrete database class.
    Database *db;
    public:
    // Dependency is injected from outside through the constructor.
    Application(Database *db1) : db(db1) {}
    void start()
    {
        // Application works with any database that follows the Database interface.
        db->connect();
    }
};

int main()
{
    // We can choose any database implementation at runtime.
    MySqlDatabase sq;

    // Application receives the dependency instead of creating it directly.
    Application app(&sq);
    app.start();
    return 0;
}
