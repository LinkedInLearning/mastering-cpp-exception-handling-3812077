#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <stdexcept>

std::mutex cerrMutex; // Global mutex for synchronizing std::cerr access

void workerFunction(int id)
{
    try
    {
        // Simulate an error in some threads
        if (id % 2 == 0)
        { // Even-numbered threads throw an exception
            throw std::runtime_error("Thread " + std::to_string(id) + " encountered an error.");
        }
    }
    catch (const std::exception &e)
    {
        // The std::lock_guard ensures that only one thread writes to std::cerr at any given time
        //std::lock_guard<std::mutex> guard(cerrMutex);
        std::cerr << "Exception in thread " << id << ": " << e.what() << std::endl;
    }
}

int main()
{
    // Total number of threads to spawn
    const int numThreads = 50;     
    // Vector to hold the threads
    std::vector<std::thread> threads; 

    // Spawn threads
    for (int i = 0; i < numThreads; ++i)
    {
        threads.emplace_back(workerFunction, i);
    }

    // Wait for all threads to complete
    for (auto &t : threads)
    {
        t.join();
    }

    std::cout << "All threads have completed." << std::endl;

    return 0;
}