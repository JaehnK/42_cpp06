#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

typedef struct s_data
{
    int    var;
} Data;


class Serializer
{
    private:
        Serializer();
        Serializer(Serializer &rhs);
        Serializer *operator=(Serializer &rhs);
        ~Serializer();
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data         *deserialize(uintptr_t raw);
};

#endif