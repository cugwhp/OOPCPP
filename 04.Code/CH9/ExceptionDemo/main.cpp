#include <exception>
class Base : public std::exception
{
public:
    Base() {}
};

class Derived: public Base
{
public:
    Derived() {}
};

int main()
{
    try
    {
        throw Derived();
    }
    catch (std::exception& exception)
    {
        cerr << exception.what();
    }

    catch (Base &base)
    {
        cerr << "caught Base";
    }
    catch (Derived &derived)
    {
        cerr << "caught Derived";
    }

    return 0;
}
