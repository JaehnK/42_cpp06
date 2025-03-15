#ifndef BASE_HPP
#define BASE_HPP

#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <iostream>

class   A;
class   B;
class   C;
class   Base
{
    private:

    public:
                Base() {};
        virtual ~Base();

        Base    *generate(void);
        void    identify(Base*p);
        void    identify(Base& p);
};



#endif