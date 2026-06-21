#ifndef FORMULAE_H
#define FORMULAE_H

#include "math_tools.h"

class Formulae
{
    public:

    static double find_velocity_exit(double chamber_temperature, double gamma, double exit_pressure, double chamber_pressure, double molecular_weight);

    static double find_mass_flow(double thrust, double velocity_exit);

    static double find_local_mach(double velocity, double temperature, double gamma);

    static double find_throat_area(double mass_flow, double chamber_pressure, double gamma, double chamber_temperature);

    static double find_epsilon(double velocity_exit, double exit_mach, double gamma);

    static double find_exit_area(double epsilon, double throat_area);

    static double find_length_diverging(double R_exit, double R_throat, double alpha);




}

#endif