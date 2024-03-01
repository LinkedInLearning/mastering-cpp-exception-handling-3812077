#include <iostream>
#include <stdexcept>
//
// Warning! This approach is outdated and not recommended in modern C++ practices.
// For educational purposes only.
// 
// Function declared to throw both std::runtime_error and std::logic_error
// Deprecated in C++11, removed in C++17
void riskyFunction(bool triggerLogicError) throw(std::runtime_error, std::logic_error) 
{
    if (triggerLogicError) 
    {
        // Simulate a condition that leads to a logic error
        throw std::logic_error("A logic error occurred");
    } 
    else 
    {
        // Simulate a condition that leads to a runtime error
        throw std::runtime_error("A runtime error occurred");
    }
}

int main() 
{
    try 
    {
        // Change this to true to trigger a logic error instead
        riskyFunction(false);
    } 
    catch (const std::runtime_error& e) 
    {
        std::cerr << "Caught a runtime error: " << e.what() << std::endl;
    } 
    catch (const std::logic_error& e) 
    {
        std::cerr << "Caught a logic error: " << e.what() << std::endl;
    } 
    catch (...) 
    {
        std::cerr << "Caught an unknown exception" << std::endl;
    }
    return 0;
}
