#include <stdexcept>
#include <iostream>
#include <string>

enum class ErrorType
{
    None,
    Network,
    Authentication,
    DataIntegrity
};

class NetworkError : public std::runtime_error
{
public:
    NetworkError(const std::string &msg) : std::runtime_error(msg) {}
};

class AuthenticationError : public NetworkError
{
public:
    AuthenticationError(const std::string &msg) : NetworkError(msg) {}
};

class DataIntegrityError : public std::runtime_error
{
public:
    DataIntegrityError(const std::string &msg) : std::runtime_error(msg) {}
};

void accessAPI(ErrorType error)
{
    switch (error)
    {
    case ErrorType::Network:
        throw NetworkError("Network connectivity issue.");
    case ErrorType::Authentication:
        throw AuthenticationError("Invalid API credentials.");
    case ErrorType::DataIntegrity:
        throw DataIntegrityError("Corrupt data received.");
    default:
        std::cout << "API accessed successfully." << std::endl;
        break;
    }
}

int main()
{
    try
    {
        accessAPI(ErrorType::DataIntegrity);
    }
    catch (const AuthenticationError &e)
    {
        std::cerr << "AuthenticationError: " << e.what() << std::endl;
    }
    catch (const NetworkError &e)
    {
        std::cerr << "NetworkError: " << e.what() << std::endl;
    }
    catch (const DataIntegrityError &e)
    {
        std::cerr << "DataIntegrityError: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Standard exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred." << std::endl;
    }
    return 0;
}
