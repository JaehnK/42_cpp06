#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{

}

Base    *Base::generate(void)
{

    std::srand(static_cast<unsigned int> (std::time(NULL)));
    switch (std::rand() % 3)
    {
        case (0):
        {
            return (new A);
        }
        case (1):
        {
            return (new B);
        }
        case (2):
        {
            return (new C);
        }
    }

    return (NULL);
}

void    Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
    else
        std::cout << "Class Not Defined" << std::endl;
    return ;
}

void    Base::identify(Base& p)
{
    try
    {
        if (dynamic_cast<A*>(&p))
            std::cout << "class A" << std::endl;
        else if (dynamic_cast<B*>(&p))
            std::cout << "Class B" << std::endl;
        else if (dynamic_cast<C*>(&p))
            std::cout << "Class C" << std::endl;
        else
            std::cout << "Class Not Defined" << std::endl;
    }
    catch(const std::exception& e)
    {}
    
}



