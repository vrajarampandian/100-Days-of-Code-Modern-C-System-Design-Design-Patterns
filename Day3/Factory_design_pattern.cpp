#include<iostream>
using namespace std;

// Base interface for all game objects.
// Every game object must define how it updates and renders itself.
class IGameObject
{
    public:
        // Virtual destructor is needed when deleting derived objects
        // through a base-class pointer.
        virtual ~IGameObject() {}
        virtual void update() = 0;
        virtual void render() = 0;
};

// Concrete product representing a plane object.
class Plance : public IGameObject
{
    public:
        void update()
        {
            cout << "Plane Update" << "\n";
        }
        void render()
        {
            cout << "Plane ender " << "\n";
        }
};

// Concrete product representing a boat object.
class Boat : public IGameObject
{
    public:
    void update()
    {
        cout << "Boat Update" << "\n";
    }
    void render()
    {
        cout << "Boat Render" << "\n";
    }
};

// Factory function that creates objects based on the requested type.
// The caller works with the common interface instead of concrete classes.
IGameObject* createObjectFactory(const string type)
{
    // Create a plane object when the input type is "plane".
    if(type ==  "plane")
        return new Plance();
    // Create a boat object when the input type is "boat".
    else if(type == "boat")
        return new Boat;
    
        // Return nullptr if the type is not recognized.
        return nullptr;
}
int main()
{
    //Boat b;
    //Plance p;
    // Ask the factory to create the object instead of constructing it directly.
    IGameObject *b1 = createObjectFactory("boat");

    // Use the object through the interface pointer.
    b1->update();

    // Free the dynamically allocated memory.
    delete b1;

    return 0;
}
