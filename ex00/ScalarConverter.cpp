#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(std::string input)
{
    this->_input = input;
    this->demicalLength = 0;
    this->isFloat = false;
    this->isInf = false;
    this->isNan = false;
}

ScalarConverter::~ScalarConverter()
{}

bool    ScalarConverter::validateInput()
{
    int dot = 0;
    int numCnt = 0;

    if ((this->_input == "-inff") || (this->_input == "inff"))
    {
        this->isInf = true;
        return (true);
    }
    else if ((this->_input == "-inf") || (this->_input == "inf"))
    {
        this->isInf = true;
        return (true);
    }

    if (this->_input == "nan" || this->_input == "nanf")
    {
        if ((int) this->_input.length() == 4)
            this->isFloat = true;
        this->isNan = true;
        return (true);
    }

    for (int i = 0; i < (int) this->_input.length(); i++)
    {
        if (isdigit(this->_input[i]) == 0)
        {
            if (i == 0 &&( this->_input[i] == '-' || this->_input[i] == '+'))
            {
                if (this->_input.length() == 1)
                    return (false);
                else
                    continue ;
            }
            else if (i == (int) this->_input.length() - 1)
            {
                if (this->_input[i] != 'f')
                    return (false);
                if (this->_input[i - 1] == '.')
                    return (false);
                if (!numCnt || !this->demicalLength)
                    return (false);
                this->isFloat = true;
            }
            else if (this->_input[i] == '.' && !dot)
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
            this->demicalLength++;
    }
    return (true);
}

void    ScalarConverter::printChar()
{
    double value = strtod(this->_input.c_str(), NULL);

    if (this->isInf || this->isNan)
        std::cout << "char: impossible" << std::endl;
    else if (static_cast<char> (value) < 32 || static_cast<char> (value) > 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " <<  static_cast<char> (value) << std::endl;
}

void    ScalarConverter::printInt()
{
    double value = strtod(this->_input.c_str(), NULL);

    if (this->isInf || this->isNan)
        std::cout << "int: impossible" << std::endl;
    else if (value > INT_MAX)
        std::cout << "int: exceed INT_MAX" << std::endl;
    else if (value < INT_MIN)
        std::cout << "int: exceed INT_MIN" << std::endl;
    else
        std::cout << "int: " << static_cast<int> (value) << std::endl;
}

void    ScalarConverter::printFloat()
{
    int     precisionLen;
    double  value;
    
    if (this->isFloat)
        precisionLen = this->demicalLength - 1;
    else if (this->demicalLength == 0)
        precisionLen = 1;
    else
        precisionLen = this->demicalLength;
    value = strtod(this->_input.c_str(), NULL);
    
    std::cout << "float: " << std::fixed << std::setprecision(precisionLen) \
              << static_cast<float> (value);
    if (this->isFloat || precisionLen)
        std::cout << "f";
    
    std::cout << std::endl;
}

void    ScalarConverter::printDouble()
{
    double value = strtod(this->_input.c_str(), NULL);

    std::cout << "double: " << (double) value << std::endl;
}

void    ScalarConverter::printValues()
{
    if (validateInput() == false)
    {
        throw NotNumberInputException();
    }

    printChar();
    printInt();
    printFloat();
    printDouble();   
}

const char* ScalarConverter::NotNumberInputException::what() const throw()
{
    return "Converter: Not Number Input";
}