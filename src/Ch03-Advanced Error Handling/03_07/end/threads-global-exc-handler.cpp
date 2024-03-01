#include <iostream>
#include <thread>
#include <vector>
#include <stdexcept>

void globalExceptionHandler()
{
    try
    {
        // Attempt to rethrow the current exception
        std::rethrow_exception(std::current_exception());
    }
    catch (const std::exception &e)
    {
        // Catch and handle standard exceptions
        std::cerr << "Global Exception Handler: Unhandled exception of type '"
                  << typeid(e).name() << "' with message: '" << e.what() << "'" << std::endl;
    }
    catch (...)
    {
        // Catch any non-standard exceptions
        std::cerr << "Global Exception Handler: Unknown exception type" << std::endl;
    }

    std::abort(); // Terminate the program after handling the exception
}

void threadFunction(int id)
{
    // Simulate a task that might throw an exception
    if (id % 2 == 0)
    { // Threads with even IDs throw an exception
        throw std::runtime_error("Exception from thread " + std::to_string(id));
    }
}

int main()
{
    std::set_terminate(globalExceptionHandler);

    const int numThreads = 4;
    std::vector<std::thread> threads;

    // Spawn threads
    for (int i = 0; i < numThreads; ++i)
    {
        threads.emplace_back(threadFunction, i);
    }

    // Join threads
    for (auto &th : threads)
    {
        th.join();
    }

    std::cout << "All threads have completed." << std::endl;

    return 0;
}