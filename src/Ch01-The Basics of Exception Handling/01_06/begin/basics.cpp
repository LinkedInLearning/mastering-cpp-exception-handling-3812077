#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string readConfigFile(const string& filename) {
    ifstream file(filename);
    if (!file.good()) 
    {
        throw std::runtime_error("Failed to open configuration file.");
    }

    string line;
    string text;
    while (getline(file, line)) 
    {
        text += line;
        text += '\n';
    }

    return text;
}

int main() 
{    
    cout << "Reading configuration:" << endl;
    string text = readConfigFile("configuration.txt");
    cout << text;
    
    try 
    {
        // Code that might throw exception
        cout << "Reading configuration:" << endl;
        string text = readConfigFile("configuration.txt");
        cout << text;
    } 
    catch (const std::exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
        // Handle the error, like providing a default configuration
        return -1; // Or exit if the file is critical
    }

    // Proceed with the rest of the program
    return 0;
}

