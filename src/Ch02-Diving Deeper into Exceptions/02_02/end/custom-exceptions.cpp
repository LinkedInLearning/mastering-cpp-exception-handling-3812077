#include <iostream>
#include <stdexcept>
#include <string>

class InsufficientDiskSpaceException : public std::runtime_error 
{
    public:
    InsufficientDiskSpaceException(const std::string& msg) : std::runtime_error(msg) {}
};

void checkDiskSpace(unsigned long availableSpaceMB) 
{
    const unsigned long requiredSpaceMB = 100; // Minimum required space
    
    if (availableSpaceMB < requiredSpaceMB) 
    {
        throw InsufficientDiskSpaceException("Insufficient disk space.");
    }
}

int main() 
{
    unsigned long spaceToTest[] = {120, 100, 80}; // Different disk space scenarios in MB

    for (unsigned long space : spaceToTest) 
    {
        try 
        {
            checkDiskSpace(space);
            std::cout << "Sufficient disk space: " << space << "MB" << std::endl;
        } 
        catch (const InsufficientDiskSpaceException& e) 
        {
            std::cerr << "Error: " << e.what() << " Available space: " << space << "MB" << std::endl;
        }
    }

    return 0;
}