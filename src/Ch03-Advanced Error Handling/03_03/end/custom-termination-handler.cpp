#include <iostream>
#include <exception>
#include <typeinfo>
#include <cstring>
#include <cerrno>

int main()
{
    // Establish the custom termination handler
    std::set_terminate([]() -> void
                       {
        std::cerr << "std::terminate() called after an exception escaped unnoticed. Details: ";
        try {
            // Attempt to identify and handle the rogue exception
            std::rethrow_exception(std::current_exception());
        } catch (const std::exception& ex) {
            // Provide information for standard exceptions
            std::cerr << typeid(ex).name() << "\n  what(): " << ex.what() << std::endl;
        } catch (...) {
            // Address non-standard or unknown exceptions
            std::cerr << "Unknown or non-standard exception caught." << std::endl;
        }
        // Report system errors that might relate to the exception
        std::cerr << "System errno: " << errno << " (" << std::strerror(errno) << ")." << std::endl;
        // Abruptly terminate the program to prevent further issues
        std::abort(); });

    // Example usage that leads to the termination handler being invoked
    throw std::runtime_error("Example of a rogue exception");
    return 0; // Note: This line is unreachable due to the throw above
}
