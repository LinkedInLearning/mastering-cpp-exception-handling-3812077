#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string readConfigFile(const string& filename) 
{
    ifstream file(filename);
    if (!file.good()) 
    {
        throw runtime_error("Failed to open configuration file.");
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
    
    return 0;
}

