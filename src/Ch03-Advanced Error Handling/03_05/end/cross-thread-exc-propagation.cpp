#include <future>
#include <thread>
#include <iostream>

void threadTask(std::promise<void>& prom) {
    try {
        // Potentially throwing code
        throw std::runtime_error("Error in child thread");
    } catch (...) {
        prom.set_exception(std::current_exception());
    }
}

int main() {
    std::promise<void> prom;
    std::future<void> fut = prom.get_future();
    std::thread t(threadTask, std::ref(prom));
    t.join();

    try {
        fut.get();
    } catch (const std::exception& e) {
        std::cerr << "Caught thread exception in main: " << e.what() << std::endl;
    }
}
