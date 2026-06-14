#ifndef MATH_TOOLS_H
#define MATH_TOOLS_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <iomanip>

void setStdOutPrecision(int decimalPlaces);

template<typename F>
long double integrate(F function, double start, double end, int iterations, bool verbose)
{
    long double sum = 0;
    long double step = (end - start) / iterations;
    if (step > 0.001 && verbose)
        std::cout << "\n!!! WARNING: step (" << step << ") may be too high for accurate calculations" << "\n";
    
    std::chrono::high_resolution_clock::time_point t1;
    if (verbose)
        t1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
    {
        sum += step * (function(start + i * step) + function(start + (i+1) * step)) / 2;
    }

    std::chrono::high_resolution_clock::time_point t2;
    if (verbose)
    {
        t2 = std::chrono::high_resolution_clock::now();
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        std::cout << "Integration took " << microseconds << " microseconds to run.\n";
    }

    return sum;
}

template<typename F>
long double integrate(F function, double start, double end, int iterations) { return integrate(function, start, end, iterations, false); }

#endif