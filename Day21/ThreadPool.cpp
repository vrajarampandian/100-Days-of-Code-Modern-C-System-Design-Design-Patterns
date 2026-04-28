#include<iostream>
#include<vector>
#include<thread>
#include<queue>
#include<functional>
#include<mutex>
#include<condition_variable>
using namespace std;

/*
Notes:
- A thread pool creates worker threads once and reuses them for many tasks.
- Tasks are stored in a queue as function<void()> objects.
- condition_variable puts workers to sleep until a task is available.
- mutex protects shared data: the task queue and stop flag.
- The destructor stops the pool, wakes all workers, and joins every thread.
*/
class ThreadPool
{
    private:
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex m;
    condition_variable cv;
    bool stop;
    public:
        ThreadPool(size_t numThreads) : stop(false)
        {
            for(size_t i = 0; i < numThreads; ++i)
            {
                workers.emplace_back([this]()
                    {
                        while(true)
                        {
                            function<void()> task;
                            {
                                unique_lock<mutex> lock(m);
                                cv.wait(lock, [this](){
                                   return stop || !tasks.empty();
                                });
                                if(stop && tasks.empty())
                                    return;
                                task = move(tasks.front());
                                tasks.pop();
                            }
                            task();
                        }
                    }
                );
            }
        }
        void enqueue(function<void()> task)
        {
            {
                unique_lock<mutex> lock(m);
                tasks.emplace(move(task));
            }
            cv.notify_one();
        }
        ~ThreadPool()
        {
            {
                unique_lock<mutex> lock(m);
                stop = true;
            }
            cv.notify_all();
            for(thread &t : workers)
            {
                t.join();
            }
        }

};

int main()
{
    ThreadPool Pool(3);
    mutex coutMutex;
    for(int i = 0; i<5;i++)
    {
        Pool.enqueue([i, &coutMutex](){
            lock_guard<mutex> lock(coutMutex);
            cout << "task " << i << " executed by thread " << this_thread::get_id() << endl;
        });
    }
    return 0;
}
