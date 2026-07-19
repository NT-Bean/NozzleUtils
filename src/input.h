#ifndef INPUTS_H
#define INPUTS_H

#include <vector>
#include <string>

class Input
{
    public:

    enum InputType
    {
        AMBIENT_PRESSURE,
        CHAMBER_PRESSURE,
        CHAMBER_TEMP,
        CHARACTERISTIC_CHAMBER_LENGTH,
        GAMMA,
        MOLECULAR_WEIGHT, // MUST BE IN KG/MOL AS IS SI STANDARD, NOT G/MOL OR KG/KMOL
        insert_cash_or_select_payment_type,
        THRUST,
        CONTRACTION_RATIO
    };

    InputType inputType;
    std::string filepath = "unknown filepath";
    std::string name = "unknown name";

    double value = 0.0;

    Input(InputType inputType);

};

#endif