#include "formulae.h"

double Formulae::find_velocity_exit(double chamber_temperature, double gamma, double exit_pressure, double chamber_pressure, double molecular_weight) {
    
    return sqrt(((chamber_temperature * MathTools::universalGasConstant) / molecular_weight) * ((2.0 * gamma) / (gamma - 1.0)) * (1.0 - pow((exit_pressure   / chamber_pressure), ((gamma - 1.0) / gamma))));
}

double Formulae::find_mass_flow(double thrust, double velocity_exit){

    return (thrust / velocity_exit);

}


double Formulae::find_speed_of_sound(double temperature, double gamma, double molecular_weight) {
    return sqrt((gamma * MathTools::universalGasConstant * temperature) / molecular_weight);
}

double Formulae::find_local_mach(double velocity, double temperature, double gamma, double molecular_weight) {

    return (velocity / sqrt((gamma * MathTools::universalGasConstant * temperature) / molecular_weight));    
}
double Formulae::find_local_mach(double velocity, double speed_of_sound) {
    return velocity / speed_of_sound;
}
//optimum expansions

double Formulae::find_throat_area(double mass_flow, double chamber_pressure, double gamma, double chamber_temperature, double molecular_weight) {

    return (mass_flow / chamber_pressure) * sqrt( (MathTools::universalGasConstant * chamber_temperature) / (molecular_weight * gamma * pow(2.0 / (gamma + 1.0), (gamma + 1.0) / (gamma - 1.0))) );
}
double Formulae::find_throat_area(double force, double thrust_coefficient, double chamber_pressure)
{
    return force / (thrust_coefficient * chamber_pressure);
}

double Formulae::find_epsilon(double exit_mach, double gamma) {

    return (1.0 / exit_mach) * sqrt( pow( (1 + ((gamma - 1) / 2) * exit_mach * exit_mach) / (1 + ((gamma - 1) / 2)), (gamma + 1) / (gamma - 1) ) );
}
double Formulae::find_epsilon(double ambient_pressure, double chamber_pressure, double gamma) {
    return 1.0 / ( pow((gamma + 1.0) / 2.0, 1.0 / (gamma - 1.0)) * pow(ambient_pressure / chamber_pressure, 1.0 / gamma) * sqrt( ((gamma + 1) / (gamma - 1)) * (1 - pow(ambient_pressure / chamber_pressure, (gamma - 1.0) / gamma)) ) );
}

double Formulae::find_exit_area(double epsilon, double throat_area) {
    return (epsilon * throat_area);
}

double Formulae::find_conical_length(double R_exit, double R_throat, double alpha) {

    return (R_exit - R_throat) / tan(alpha);
}

double Formulae::find_thrust_coefficient(double gamma, double ambient_pressure, double chamber_pressure)
{
    return sqrt(((2.0 * gamma * gamma) / (gamma - 1.0)) * pow(2.0 / (gamma + 1.0), (gamma + 1.0) / (gamma - 1.0)) * (1.0 - pow(ambient_pressure / chamber_pressure, (gamma - 1.0) / gamma)) );
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