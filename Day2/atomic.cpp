#include<iostream>
#include<thread>
#include<atomic>

// Atomic counter shared by both threads.
// Atomic operations prevent the race condition seen with a plain int.
std::atomic<int> counter(0);

void increment()
{
    // Each thread increments the counter 100000 times.
    for(int i = 0; i< 100000; i++)
    {
        // Atomic increment is thread-safe, so updates are not lost.
        counter++;
    }
}

int main()
{
    // Launch two threads that update the same atomic counter.
    std::thread t1(increment);
    std::thread t2(increment);

    // Wait for both threads to finish.
    t1.join();
    t2.join();

    // Because counter is atomic, the final value should be 200000.
    std::cout << counter << "\n";
    return 0;
}
