#include "input_file_check.h"

int main() {
    /*
        this part just checks if thy files exist
        if you get a number in the one digit you effed up
        if you get a number in the tens digit just rerun it.
    */
    int checkfile = filecheck();
    if (checkfile >= 1) {
        std::cout << (checkfile);
        std::exit(0);
    }
    if (checkfile == 0) {
        std::cout << "Inputs Exist\n";
    }

     std::vector<std::string> ListofFilePath = {
         "./inputs/ambient pressure {pa}.txt",
         "./inputs/chamber pressure {pa}.txt",
         "./inputs/chamber temp.txt",
         "./inputs/characteristic chamber length {m}.txt",
         "./inputs/gamma.txt",
         "./inputs/Molecular weight.txt",
         "./inputs/O-F ratio.txt",
         "./inputs/thrust wanted {n}.txt"
        };

        
    double ambient_pressure = numbercheck(std::string(ListofFilePath[0]));
    double chamber_pressure = numbercheck(std::string(ListofFilePath[1]));
    double chamber_temperature = numbercheck(std::string(ListofFilePath[2]));
    double characteristic_chamber_length = numbercheck(std::string(ListofFilePath[3]));
    double gamma = numbercheck(std::string(ListofFilePath[4]));
    double molecular_weight = numbercheck(std::string(ListofFilePath[5]));
    double of_ratio = numbercheck(std::string(ListofFilePath[6]));
    double thrust_wanted = numbercheck(std::string(ListofFilePath[7]));
    std::cout << "Ambient_Pressure: " << ambient_pressure << "\n";
    std::cout << "Chamber_Pressure: " << chamber_pressure << "\n";
    std::cout << "Chamber_Temperature: " << chamber_temperature << "\n";
    std::cout << "Characteristic_Chamber_Length: " << characteristic_chamber_length << "\n";
    std::cout << "Gamma: " << gamma << "\n";   
    std::cout << "Molecular_Weight: " << molecular_weight << "\n";
    std::cout << "O-F Ratio: " << of_ratio << "\n";
    std::cout << "Thrust Wanted: " << thrust_wanted << "\n"; 
    return 0;

}
