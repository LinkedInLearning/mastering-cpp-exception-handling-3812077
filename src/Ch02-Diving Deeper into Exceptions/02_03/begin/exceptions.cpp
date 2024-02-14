#include <iostream>

enum ErrorType
{
    None,
    Disk,
    Permission,    
    FileIO
};

class DiskAccessException {};

class FilePermissionException {};

class FileIOException {};

void triggerException(ErrorType error)
{
    switch (error)
    {    
    case ErrorType::Disk:
        throw DiskAccessException();
    case ErrorType::Permission:
        throw FilePermissionException();
    case ErrorType::FileIO:
        throw FileIOException();
    default:
        break; // No exception thrown
    }
}

int main()
{
    try
    {
        triggerException(ErrorType::Disk);
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred." << std::endl;
    }
    return 0;
}