#ifndef MATH_TOOLS_H
#define MATH_TOOLS_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <iomanip>

class MathTools
{
public:
    static void setStdOutPrecision(int decimalPlaces);

    template<typename F>
    static long double integrate(F function, double start, double end, int iterations, bool verbose)
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
            long long nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
            std::cout << "Integration took " << (nanoseconds >= 100000 ? nanoseconds / 1000 : nanoseconds) << (nanoseconds >= 100000 ? " microseconds" : " nanoseconds") << " to run.\n";
        }

        return sum;
    }

    template<typename F>
    static long double integrate(F function, double start, double end, int iterations) { return integrate(function, start, end, iterations, false); }

};

#endif
