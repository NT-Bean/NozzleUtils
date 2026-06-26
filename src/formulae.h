#ifndef FORMULAE_H
#define FORMULAE_H

#include "math_tools.h"

class Formulae
{
    public:

    // equations only apply if the combustion chamber velocity is negligible (i.e. the combustion chamber is significantly larger than the throat)
    static double find_velocity_exit(double chamber_temperature, double gamma, double exit_pressure, double chamber_pressure, double molecular_weight);

    static double find_mass_flow(double thrust, double velocity_exit);
    
    static double find_speed_of_sound(double temperature, double gamma, double molecular_weight);

    static double find_local_mach(double velocity, double temperature, double gamma, double molecular_weight);
    static double find_local_mach(double velocity, double speed_of_sound);

    static double find_throat_area(double mass_flow, double chamber_pressure, double gamma, double chamber_temperature, double specific_gas_constant);
    static double find_throat_area(double force, double thrust_coefficient, double chamber_pressure);

    static double find_epsilon(double exit_mach, double gamma);
    static double find_epsilon(double ambient_pressure, double chamber_pressure, double gamma);

    static double find_exit_area(double epsilon, double throat_area);

    static double find_conical_length(double R_exit, double R_throat, double alpha);

    static double find_thrust_coefficient(double gamma, double ambient_pressure, double chamber_pressure);




};

#endif