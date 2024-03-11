#include <iostream>

class Resource
{
public:
    Resource(const std::string &id) : id_(id)
    {
        std::cout << "Resource " << id_ << " acquired.\n";
    }
    ~Resource()
    {
        std::cout << "Resource " << id_ << " released.\n";
    }

private:
    std::string id_;
};

void funcC()
{
    Resource resC("C");
    std::cout << "In funcC, about to throw an exception.\n";
    throw std::runtime_error("Exception from funcC");
}

void funcB()
{
    Resource resB("B");
    funcC();
    std::cout << "This won't print.\n";
}

void funcA()
{
    try
    {
        Resource* resA = new Resource("A");
        funcB();
        delete resA;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    funcA();

    return 0;
}