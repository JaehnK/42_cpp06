#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cerr << "Check Argv" << std::endl;
        return (1);
    }
    
    try
    {
        ScalarConverter converter(argv[1]);
        converter.printValues();

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}