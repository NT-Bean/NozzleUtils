#include "math_tools.h"

void MathTools::setStdOutPrecision(int decimalPlaces)
{
    std::cout << std::fixed << std::setprecision(decimalPlaces);
}

double MathTools::find_radius(double area) {
    return sqrt(area / MathTools::pi);
}