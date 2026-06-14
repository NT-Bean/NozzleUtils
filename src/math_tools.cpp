#include "math_tools.h"

template<typename F>
double integrate(F function, double start, double end, int iterations)
{
    double sum = 0;
    double step = (end - start) / iterations;

    for (int i = 0; i < iterations; i++)
    {
        sum += step * (function(start + i * step) + function(start + (i+1) * step)) / 2;
    }

    return sum;
}