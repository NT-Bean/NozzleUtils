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
        "./inputs/subtotal.txt",
        "./inputs/thrust wanted {n}.txt",
        "./inputs/contraction ratio.txt"
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
        "Thank you for shopping at Costco",
        "Thrust",
        "Contraction Ratio"
    };

    name = nameOptions[(int)inputType];

}