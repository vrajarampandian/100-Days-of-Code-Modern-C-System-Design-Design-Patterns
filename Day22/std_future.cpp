#include<iostream>
#include<future>
using namespace std;

/*
Notes:
- std::future stores the result of an asynchronous operation.
- std::async starts a callable, such as a function or lambda, and returns a future.
- The main thread can continue doing other work while the async task runs.
- future.get() waits until the result is ready, then returns the value.
- get() can be called only once because it moves the stored result out of the future.
- If the async function throws an exception, get() rethrows that exception in the calling thread.
*/
int add(int a, int b)
{
    //cout << "Call add" << "\n";
    return a + b;
}

int main()
{
    cout << "call Main" << "\n";
    future<int> result = async(add, 2,4);

    for(int i = 0 ;i < 10; i++)
    {
        cout << add(i, i+1) << "\n";
    }
    cout << result.get() << "\n";
    cout << "end" << "\n";
    return 0;
}
