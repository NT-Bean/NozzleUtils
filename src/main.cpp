#include <stdexcept>
#include <iostream>
#include <fstream>

#include "input_file_check.h"
#include "math_tools.h"
#include "formulae.h"
using namespace std;

int main() {
    //check if you want to get the inputs from  file or new inputs straight from cmd
  int check = 0;;
    std::cout << "1 load from file, 2 load from input: ";
    std::cin >> check;
    std::cout << check << "\n";
    // take files from list and turn them into numbers

    // case if user wants to load from file
    std::vector<Input> inputs;
    if (check == 1){
    
        for (int i = 0; i < 9; i++) {
           inputs.push_back(Input((Input::InputType)i));
          inputs[i].value = numbercheck(inputs[i].filepath);

          std::cout << inputs[i].name << ": " << inputs[i].value << "\n";
          }
          /*
             this part just checks if thy files exist
                if you get a number in the one digit you effed up
               if you get a number in the tens digit just rerun it.
          */
        int checkfile = filecheck(inputs);
        std::cout << "filecheck returned code " << checkfile << ": ";
        int errorCode = handleFileErrors(checkfile);
        if (errorCode != 0) { return errorCode; }    

    MathTools::setStdOutPrecision(8);

    }
    // case if user wants to input from cmd
    if (check == 2){
            
        for (int i = 0; i < 9; i++) {
           inputs.push_back(Input((Input::InputType)i));
           std::cout << inputs[i].name << ": ";
           std::cin >> inputs[i].value;
          } 
         MathTools::setStdOutPrecision(8);
    }
   
    // check the edge cases of not 1 or 2
    if (check != 1){
        if (check !=2){
            std::cout << "skill issue";
            return 1;
        }
    }




    // now we do the math
    long double integralTest = MathTools::integrate<double(*)(double)>(sin, 0.0, 3.14, 10000, true);
    std::cout << "integral of sin(x) from 0 to 3.14 equals " << std::endl << integralTest; 

    // we do the velocity exit
   double velocity_exit = Formulae::find_velocity_exit(
    inputs[Input::CHAMBER_TEMP].value,
    inputs[Input::GAMMA].value,
    inputs[Input::AMBIENT_PRESSURE].value,
    inputs[Input::CHAMBER_PRESSURE].value,
    inputs[Input::MOLECULAR_WEIGHT].value
    );
    // we do da mass flow
    double mass_flow = Formulae::find_mass_flow(inputs[Input::THRUST].value, velocity_exit);
    // find exit mach for finding ratio
     double exit_mach = Formulae::find_local_mach(velocity_exit, inputs[Input::CHAMBER_TEMP].value, inputs[Input::GAMMA].value);
        // find epsilon aka the optimim expansion ratio from throat to exit
     double epsilon = Formulae::find_epsilon(velocity_exit, exit_mach, inputs[Input::GAMMA].value); 
     //find throat area
        double throat_area = Formulae::find_throat_area(mass_flow, inputs[Input::CHAMBER_PRESSURE].value, inputs[Input::GAMMA].value, inputs[Input::CHAMBER_TEMP].value);
     // find the exit area
     double exit_area = Formulae::find_exit_area(epsilon, throat_area);



     // we print the results
    std::cout << double(mass_flow) << std::endl << " The mass flow\n";
    std::cout << double(velocity_exit) << std::endl << " The exit velocity in m/s\n";
    std::cout << double(exit_mach) << std::endl << " The local Mach at the exit\n";
    std::cout << double(epsilon) << std::endl << " The expansion ratio from throat to exit\n";
    std::cout << double(throat_area) << std::endl << " The throat area in m^2\n"  << std::endl ;
    std::cout << double(exit_area) << " The exit area in m^2\n"  << std::endl ;





    system("pause");
system("pause");
    return 0;
}