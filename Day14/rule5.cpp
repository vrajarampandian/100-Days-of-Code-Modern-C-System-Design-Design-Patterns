#include<iostream>
using namespace std;

class Resource
{
    int *data;   
    public:
    // Constructor
    Resource(int v)
    {
        data = new int(v);
    }

    // Destructor
    ~Resource()
    {
        delete data;
    }

    // Copy Constructor (Deep Copy)
    Resource(const Resource &r)
    {
        cout << "copy constructor" << "\n";
        data = new int(*r.data); 
    }

    // Copy Assignment Operator (Deep Copy)
    Resource& operator=(const Resource &r)
    {
        if(this != &r)  // self-assignment check
        {
            delete data;                  // free existing memory
            data = new int(*r.data);      // allocate new memory and copy
        }
        return *this;
    }

    // Move Constructor
    // Transfers ownership from temporary object
    Resource(Resource && r)
    {
        data = r.data;   
        r.data = nullptr;     // prevent double delete
    }

    // Move Assignment Operator
    Resource& operator=(Resource &&r)
    {
        if(this != &r)  // self-assignment check
        {
            delete data;        // free existing resource

            data = r.data;      // take ownership
            r.data = nullptr;   // reset source
        }
        return *this;
    }

    void print()
    {
        if(data)
            cout << "Data:" << *data << "\n";
        else
            cout << "Nullptr" << "\n";
    }
};

int main()
{
    Resource R1(10);

    // Copy Constructor called
    Resource R2 = R1;

    Resource R3(40);
    Resource R4(50);

    // Copy Assignment (R3 gets copy of R4)
    R3 = R4;

    // Move Constructor (R1 to R5)
    Resource R5 = std::move(R1);

    Resource R6(30);

    // Copy Assignment (R6 gets copy of R2)
    R6 = R2;

    // Print all objects
    R1.print();  // should be nullptr (moved-from)
    R2.print();  // valid
    R3.print();  // copied from R4
    R4.print();  // unchanged
    R5.print();  // moved value from R1
    R6.print();  // copied from R2

    return 0;
}