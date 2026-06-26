#include "formulae.h"

double Formulae::find_velocity_exit(double chamber_temperature, double gamma, double exit_pressure, double chamber_pressure, double molecular_weight) {
    
    return sqrt(((chamber_temperature * MathTools::universalGasConstant) / (molecular_weight / 1000)) * ((2 * gamma) / (gamma - 1)) * (1 - pow((exit_pressure   / chamber_pressure), ((gamma - 1) / gamma))));

}

double Formulae::find_mass_flow(double thrust, double velocity_exit){

    return (thrust / velocity_exit);

}

double Formulae::find_local_mach(double velocity, double temperature, double gamma){

    return (velocity / sqrt(MathTools::universalGasConstant * temperature * gamma));    
}
//optimum expansions

double Formulae::find_throat_area(double mass_flow, double chamber_pressure, double gamma, double chamber_temperature) {

    return (mass_flow / (chamber_pressure * gamma * (sqrt(pow((2 / (gamma + 1)), ((gamma + 1) / (gamma - 1))))) / (sqrt(gamma * chamber_temperature * MathTools::universalGasConstant))));
}

double Formulae::find_epsilon(double velocity_exit, double exit_mach, double gamma) {

    return (1 / exit_mach) * (sqrt(pow( (1 + ((gamma - 1) / 2)* pow(exit_mach, 2)) / (1 + ((gamma - 1) / 2)), ((gamma + 1) / (gamma - 1)) )));
}

double Formulae::find_exit_area(double epsilon, double throat_area) {
    return (epsilon * throat_area);
}

double Formulae::find_length_diverging(double R_chamber, double R_throat, double alpha) {

    return (R_chamber - R_throat) / tan(alpha);
}


/*         // take files from list and turn them into numbers
    double ambient_pressure = numbercheck(std::string(ListofFilePaths[0]));
    double chamber_pressure = numbercheck(std::string(ListofFilePaths[1]));
    double chamber_temperature = numbercheck(std::string(ListofFilePaths[2]));
    double characteristic_chamber_length = numbercheck(std::string(ListofFilePaths[3]));
    double gamma = numbercheck(std::string(ListofFilePaths[4]));
    double molecular_weight = numbercheck(std::string(ListofFilePaths[5]));
    double of_ratio = numbercheck(std::string(ListofFilePaths[6]));
    double thrust = numbercheck(std::string(ListofFilePaths[7]));
    double exit_temperature
    */