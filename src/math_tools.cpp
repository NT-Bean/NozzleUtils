#include "math_tools.h"

double MathTools::universalGasConstant = 8.31446261815324;
double MathTools::pi = 3.14159265358979323846264338;

void MathTools::setStdOutPrecision(int decimalPlaces)
{
    std::cout << std::fixed << std::setprecision(decimalPlaces);
}

double MathTools::find_radius(double area) {
    return sqrt(area / MathTools::pi);
}

double MathTools::to_radians(double degrees) {
    return (MathTools::pi * degrees) / 180.0;
}
double MathTools::to_degrees(double radians) {
    return (180.0 * radians) / MathTools::pi;
}