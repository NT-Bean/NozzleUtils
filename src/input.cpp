#include "input.h"

Input::Input(InputType inputType)
{
    this->inputType = inputType;

    std::vector<std::string> filepathOptions =
    {
        "./inputs/ambient pressure {pa}.txt",
        "./inputs/chamber pressure {pa}.txt",
        "./inputs/chamber temp.txt",
        "./inputs/characteristic chamber length {m}.txt",
        "./inputs/gamma.txt",
        "./inputs/Molecular weight.txt",
        "./inputs/O-F ratio.txt",
        "./inputs/thrust wanted {n}.txt",
        "./inputs/exit temp.txt"
    };

    filepath = filepathOptions[(int)inputType];

    std::vector<std::string> nameOptions =
    {
        "Ambient Pressure",
        "Chamber Pressure",
        "Chamber Temperature",
        "Characteristic Chamber Length",
        "Gamma",   
        "Molecular Weight",
        "O-F Ratio",
        "Thrust",
        "Exit Temperature"
    };

    name = nameOptions[(int)inputType];

}