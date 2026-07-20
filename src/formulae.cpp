#include "formulae.h"

// Velocity Exit
double Formulae::find_velocity_exit(double chamber_temperature, double gamma, double exit_pressure, double chamber_pressure, double molecular_weight) {
    return sqrt(((chamber_temperature * MathTools::universalGasConstant) / molecular_weight) * ((2.0 * gamma) / (gamma - 1.0)) * (1.0 - pow((exit_pressure   / chamber_pressure), ((gamma - 1.0) / gamma))));
}

// Mass flow
double Formulae::find_mass_flow(double thrust, double velocity_exit){
    return (thrust / velocity_exit);
}

//Locate local speed of sound
double Formulae::find_speed_of_sound(double temperature, double gamma, double molecular_weight) {
    return sqrt((gamma * MathTools::universalGasConstant * temperature) / molecular_weight);
}

double Formulae::find_local_mach(double velocity, double speed_of_sound) {
    return velocity / speed_of_sound;
}

//optimum expansions
double Formulae::find_throat_area(double force, double thrust_coefficient, double chamber_pressure) {
    return force / (thrust_coefficient * chamber_pressure);
}

double Formulae::find_epsilon(double ambient_pressure, double chamber_pressure, double gamma) {
    return 1.0 / ( pow((gamma + 1.0) / 2.0, 1.0 / (gamma - 1.0)) * pow(ambient_pressure / chamber_pressure, 1.0 / gamma) * sqrt( ((gamma + 1) / (gamma - 1)) * (1 - pow(ambient_pressure / chamber_pressure, (gamma - 1.0) / gamma)) ) );
}

//Find exit area
double Formulae::find_exit_area(double epsilon, double throat_area) {
    return (epsilon * throat_area);
}

//I forgot what this one is
double Formulae::find_thrust_coefficient(double gamma, double ambient_pressure, double chamber_pressure){
    return sqrt(((2.0 * gamma * gamma) / (gamma - 1.0)) * pow(2.0 / (gamma + 1.0), (gamma + 1.0) / (gamma - 1.0)) * (1.0 - pow(ambient_pressure / chamber_pressure, (gamma - 1.0) / gamma)) );
}

double Formulae::find_chamber_length(double characteristic_chamber_length, double throat_area, double chamber_radii) {
    return (characteristic_chamber_length * throat_area) / (MathTools::pi * pow(chamber_radii, 2));
}

double Formulae::convergent_length(double R_chamber, double R_throat) {
    return (R_chamber - R_throat) / tan(MathTools::to_radians(30)); // tan(30) is the half anglem currently 30 degrees because industry standard
}

// find divergent length
double Formulae::find_divergent_length(double R_exit, double R_throat) {
    return (R_exit - R_throat) / tan(MathTools::to_radians(15)); // tan(15) is the half angle currently 15 degrees because industry standard
}