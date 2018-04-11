#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#include <iostream>

void last() // called by third()
{
    std::cout << "Start last\n";
    std::cout << "last throwing int exception\n";
    throw -1L;
    std::cout << "End last\n";
}

void third() // called by second()
{
    std::cout << "Start third\n";
    last();
    std::cout << "End third\n";
}

void second() // called by first()
{
    std::cout << "Start second\n";
    try
    {
        third();
    }
    catch(double)
    {
        std::cerr << "second caught double exception\n";
    }
    std::cout << "End second\n";
}

void first() // called by main()
{
    std::cout << "Start first\n";
    try
    {
        second();
    }
    catch (long)
    {
        std::cerr << "first caught int exception\n";
    }
    catch (double)
    {
        std::cerr << "first caught double exception\n";
    }
    std::cout << "End first\n";
}

int main()
{
    std::cout << "Start main\n";
    try
    {
        first();
    }
    catch (long)
    {
        std::cerr << "main caught int exception\n";
    }
    std::cout << "End main\n";

    return 0;
}
