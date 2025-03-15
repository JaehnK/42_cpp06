#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main()
{
    Base b;
    Base *b1 = new A();
    Base *b2 = new B();
    Base *b3 = new C();
    Base *b4 = b.generate();
    A   a0;
    B   b0;
    C   c0;

    b.identify(b1);
    b.identify(b3);
    b.identify(b2);
    b.identify(b4);
    b.identify(a0);
    b.identify(b0);
    b.identify(c0);


    delete b1;
    delete b2;
    delete b3;
    delete b4;
    return (0);
}