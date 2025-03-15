#include "ScalarConverter.hpp"

unsigned int    ScalarConverter::demicalLength = 0;
bool            ScalarConverter::isFloat = false;
bool            ScalarConverter::isInf = false;
bool            ScalarConverter::isNan = false;

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter &rhs)
{}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs)
{}

ScalarConverter::~ScalarConverter()
{}

bool    ScalarConverter::validateInput(std::string input)
{
    int dot = 0;
    int numCnt = 0;

    if ((input == "-inff") || (input == "inff"))
    {
        isInf = true;
        return (true);
    }
    else if ((input == "-inf") || (input == "inf"))
    {
        isInf = true;
        return (true);
    }

    if (input == "nan" || input == "nanf")
    {
        if ((int) input.length() == 4)
            isFloat = true;
        isNan = true;
        return (true);
    }

    for (int i = 0; i < (int) input.length(); i++)
    {
        if (isdigit(input[i]) == 0)
        {
            if (i == 0 &&( input[i] == '-' || input[i] == '+'))
            {
                if (input.length() == 1)
                    return (false);
                else
                    continue ;
            }
            else if (i == (int) input.length() - 1)
            {
                if (input[i] != 'f')
                    return (false);
                if (input[i - 1] == '.')
                    return (false);
                if (!numCnt || !demicalLength)
                    return (false);
                isFloat = true;
            }
            else if (input[i] == '.' && !dot)
            {
                dot++;
                continue ;
            }
            else
            {
                return (false);
            }
        }
        if (!dot)
            numCnt++;
        else
            demicalLength++;
    }
    return (true);
}

void    ScalarConverter::printChar(std::string input)
{
    double value = strtod(input.c_str(), NULL);

    if (isInf || isNan)
        std::cout << "char: impossible" << std::endl;
    else if (static_cast<char> (value) < 32 || static_cast<char> (value) > 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " <<  static_cast<char> (value) << std::endl;
}

void    ScalarConverter::printInt(std::string input)
{
    double value = strtod(input.c_str(), NULL);

    if (isInf || isNan)
        std::cout << "int: impossible" << std::endl;
    else if (value > INT_MAX)
        std::cout << "int: exceed INT_MAX" << std::endl;
    else if (value < INT_MIN)
        std::cout << "int: exceed INT_MIN" << std::endl;
    else
        std::cout << "int: " << static_cast<int> (value) << std::endl;
}

void    ScalarConverter::printFloat(std::string input)
{
    int     precisionLen;
    double  value;
    
    if (isFloat)
        precisionLen = demicalLength - 1;
    else if (demicalLength == 0)
        precisionLen = 1;
    else
        precisionLen = demicalLength;
    value = strtod(input.c_str(), NULL);
    
    std::cout << "float: " << std::fixed << std::setprecision(precisionLen) \
              << static_cast<float> (value);
    if (isFloat || precisionLen)
        std::cout << "f";
    
    std::cout << std::endl;
}

void    ScalarConverter::printDouble(std::string input)
{
    double value = strtod(input.c_str(), NULL);

    std::cout << "double: " << (double) value << std::endl;
}

void    ScalarConverter::printValues(std::string input)
{
    if (ScalarConverter::validateInput(input) == false)
    {
        throw NotNumberInputException();
    }
    printChar(input);
    printInt(input);
    printFloat(input);
    printDouble(input);  
}

const char* ScalarConverter::NotNumberInputException::what() const throw()
{
    return "Converter: Not Number Input";
}