#include "math_tools.h"

void setStdOutPrecision(int decimalPlaces)
{
    std::cout << std::fixed << std::setprecision(decimalPlaces);
}