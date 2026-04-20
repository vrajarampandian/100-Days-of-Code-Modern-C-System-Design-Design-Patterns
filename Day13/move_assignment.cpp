#include<iostream>
using namespace std;

class Resource
{
    int *data;
    public:
    Resource(int v)
    {
        data = new int(v);
    }
    Resource(const Resource &r)
    {
        data = new int(*r.data);
        cout << "Copy consturctor" << "\n";
    }
    Resource(Resource && r)
    {
        cout << "Move Constructor"<<"\n";
        data = r.data;
        r.data = nullptr;
    }
    Resource& operator=(Resource&& r)
    {
        cout << "Move Assignment" << "\n";
        if(this != &r)
        {
            delete data;
            data = r.data;
            r.data = nullptr;
        }
        return *this;
    }

    ~Resource()
    {
        delete data;
    }
};

int main()
{
    Resource R1(10);
    Resource R2(20);
    R1 = move(R2);
}