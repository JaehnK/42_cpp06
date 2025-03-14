#ifndef SCARLERCONVERTER_HPP
#define SCARLERCONVERTER_HPP
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>

class ScalarConverter
{
    private:
        std::string     _input;
        unsigned int    demicalLength;
        bool            isFloat;
        bool            isInf;
        bool            isNan;

        ScalarConverter();
    public:
        ScalarConverter(std::string input);
        ~ScalarConverter();

        bool    validateInput();
        void    printChar();
        void    printInt();
        void    printFloat();
        void    printDouble();
        void    printValues();

        class NotNumberInputException:public std::exception
        {
            public:
                const char* what() const throw();
        };
};
#endif