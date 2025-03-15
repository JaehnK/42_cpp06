#include "Serializer.hpp"

int main()
{
    Data        *ptr = new Data;
    Data        *ptr2;
    uintptr_t   raw;

    ptr->var = 30;
    raw = Serializer::serialize(ptr);
    std::cout << raw << std::endl;
    raw++;
    std::cout << raw << std::endl;
    
    ptr2 = Serializer::deserialize(raw - 1);
    std::cout << ptr2->var << std::endl;
    delete ptr;
}