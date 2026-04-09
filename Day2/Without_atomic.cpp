#include<iostream>
#include<thread>

// Shared counter accessed by both threads.
// Because it is a plain int, updates are not synchronized.
int counter = 0;

void increment()
{
    // Each thread tries to increment the counter 100000 times.
    for(int i = 0; i< 100000; i++)
    {
        // This is not thread-safe:
        // multiple threads can read, modify, and write counter at the same time.
        counter++;
    }
}

int main()
{
    // Start two threads that run increment() in parallel.
    std::thread t1(increment);
    std::thread t2(increment);

    // Wait for both threads to finish before reading counter.
    t1.join();
    t2.join();

    // The expected value is 200000, but without atomic synchronization
    // the result may be smaller because of a race condition.
    std::cout << "Counter :" << counter << "\n";
    
    return 0;
}
