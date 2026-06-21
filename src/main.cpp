#include <stdexcept>


#include "input_file_check.h"
#include "math_tools.h"
#include <iostream>
#include <cmath>
#include <fstream>
int main() {

    /*
        this part just checks if thy files exist
        if you get a number in the one digit you effed up
        if you get a number in the tens digit just rerun it.
    */
    int checkfile = filecheck();
    std::cout << "filecheck returned code " << checkfile << ": ";
    int errorCode = handleFileErrors(checkfile);
    if (errorCode != 0) { return errorCode; }    

        // take files from list and turn them into numbers
    double ambient_pressure = numbercheck(std::string(ListofFilePaths[0]));
    double chamber_pressure = numbercheck(std::string(ListofFilePaths[1]));
    double chamber_temperature = numbercheck(std::string(ListofFilePaths[2]));
    double characteristic_chamber_length = numbercheck(std::string(ListofFilePaths[3]));
    double gamma = numbercheck(std::string(ListofFilePaths[4]));
    double molecular_weight = numbercheck(std::string(ListofFilePaths[5]));
    double of_ratio = numbercheck(std::string(ListofFilePaths[6]));
    double thrust_wanted = numbercheck(std::string(ListofFilePaths[7]));
    std::cout << "Ambient_Pressure: " << ambient_pressure << "\n";
    std::cout << "Chamber_Pressure: " << chamber_pressure << "\n";
    std::cout << "Chamber_Temperature: " << chamber_temperature << "\n";
    std::cout << "Characteristic_Chamber_Length: " << characteristic_chamber_length << "\n";
    std::cout << "Gamma: " << gamma << "\n";   
    std::cout << "Molecular_Weight: " << molecular_weight << "\n";
    std::cout << "O-F Ratio: " << of_ratio << "\n";
    std::cout << "Thrust Wanted: " << thrust_wanted << "\n"; 


    MathTools::setStdOutPrecision(8);

    // now we do the meth
    long double integralTest = MathTools::integrate<double(*)(double)>(sin, 0.0, 3.14, 10000, true);
    std::cout << "integral of sin(x) from 0 to 3.14 equals " << integralTest; 

    return 0;
}
