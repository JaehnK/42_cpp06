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
        static unsigned int    demicalLength;
        static bool            isFloat;
        static bool            isInf;
        static bool            isNan;

        ScalarConverter();
        ScalarConverter(ScalarConverter &rhs);
        ScalarConverter &operator=(ScalarConverter &rhs);
        ~ScalarConverter();

        static bool    validateInput(std::string input);
        static void    printChar(std::string input);
        static void    printInt(std::string input);
        static void    printFloat(std::string input);
        static void    printDouble(std::string input);
    
    public:
        static void    printValues(std::string input);

        class NotNumberInputException:public std::exception
        {
            public:
                const char* what() const throw();
        };
};
#endif