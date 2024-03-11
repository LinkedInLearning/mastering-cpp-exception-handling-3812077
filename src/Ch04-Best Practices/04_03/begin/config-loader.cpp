#include <iostream>
#include <stdexcept>

class ConfigLoader
{
private:
    std::string configuration;
    int *settingsBuffer;

public:
    ConfigLoader(const std::string &configName) : configuration(configName), settingsBuffer(new int[1024])
    {   
        // Simulate allocation for settings
        std::cout << "Constructing loader for config: " << configName << ".\n";
        memset(settingsBuffer, 0, sizeof(int) * 1024); // Initialize buffer with default settings

        if (configName == "invalid")
        {
            std::cout << "In ConfigLoader ctor, about to throw an exception due to invalid configuration" << std::endl;
            throw std::runtime_error("Failed to load configuration: " + configName);
        }
    }
    ~ConfigLoader()
    {
        std::cout << "Releasing settings buffer for config: " << configuration << ".\n";
        delete[] settingsBuffer;
    }
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