#include <iostream>
#include <stdexcept>

#include <iostream>
#include <stdexcept>
#include <memory> // For std::unique_ptr and std::make_unique

class ConfigLoader
{
private:
    std::string configuration;
    std::unique_ptr<int[]> settingsBuffer; // Use std::unique_ptr for RAII-based memory management

public:
    ConfigLoader(const std::string &configName)
        : configuration(configName),
          settingsBuffer(std::make_unique<int[]>(1024))
    { 
        // Use std::make_unique for safe memory allocation
        std::cout << "Constructing loader for config: " << configName << ".\n";
        memset(settingsBuffer.get(), 0, sizeof(int) * 1024);

        if (configName == "invalid")
        {
            std::cout << "In ConfigLoader ctor, about to throw an exception due to invalid configuration" << std::endl;
            throw std::runtime_error("Failed to load configuration: " + configName);
        }
    }
    // The custom destructor is no longer necessary as std::unique_ptr automatically deallocates memory
    /*
    ~ConfigLoader()
    {
        std::cout << "Releasing settings buffer for config: " << configuration << ".\n";
        delete[] settingsBuffer;
    }
    */
};

void simulateConfigLoading()
{
    try
    {
        ConfigLoader validLoader("default");
        ConfigLoader invalidLoader("invalid");
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    simulateConfigLoading();
    return 0;
}