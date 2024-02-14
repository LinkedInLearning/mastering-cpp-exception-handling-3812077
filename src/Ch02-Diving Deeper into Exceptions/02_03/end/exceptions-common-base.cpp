#include <stdexcept>
#include <iostream>
#include <string>

enum ErrorType
{
    None,
    Disk,
    Permission,    
    FileIO
};

class DiskAccessException : public std::runtime_error
{
public:
    DiskAccessException(const std::string &msg) : std::runtime_error(msg) {}
};

class FilePermissionException : public std::runtime_error
{
public:
    FilePermissionException(const std::string &msg) : std::runtime_error(msg) {}
};

class FileIOException : public std::runtime_error
{
public:
    FileIOException(const std::string &msg) : std::runtime_error(msg) {}
};

void triggerException(ErrorType error)
{
    switch (error)
    {
    case ErrorType::Disk:
        throw DiskAccessException("Disk access error.");
    case ErrorType::Permission:
        throw FilePermissionException("Permission denied.");
    case ErrorType::FileIO:
        throw FileIOException("File IO error.");
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
    catch (const FileIOException &e)
    {
        std::cerr << "FileIOException: " << e.what() << std::endl;
    }
    catch (const FilePermissionException &e)
    {
        std::cerr << "FilePermissionException: " << e.what() << std::endl;
    }
    catch (const DiskAccessException &e)
    {
        std::cerr << "DiskAccessException: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "std::exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred." << std::endl;
    }
    return 0;
}