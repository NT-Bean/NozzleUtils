#include <stdexcept>
#include <iostream>
#include <fstream>

#include "input_file_check.h"
#include "math_tools.h"
#include "formulae.h"

int main() {

   //check if you want to get the inputs from  file or new inputs straight from cmd
   int check = 0;

   std::cout << "1 load from file, 2 load from input: ";
   std::cin >> check;
   std::cout << check << "\n";

   // take files from list and turn them into numbers
   int do_they_want_all = 0;;
   std::cout << "1 for just dimension, 2 FOR ALL: ";
   std::cin >> do_they_want_all;

   // case if user wants to load from file
   std::vector<Input> inputs;
   if (check == 1) {
   
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
   }
   // case if user wants to input from cmd
   if (check == 2){
         
      for (int i = 0; i < 9; i++) {
         inputs.push_back(Input((Input::InputType)i));
         std::cout << inputs[i].name << ": ";
         std::cin >> inputs[i].value;
         }
   }

   // check the edge cases of not 1 or 2
   if (check != 1 && check != 2) {
      std::cout << "skill issue";
      return -1;
   }


   // now we do the math
   //  long double integralTest = MathTools::integrate<double(*)(double)>(sin, 0.0, 3.14, 10000, true);
   //  std::cout << "integral of sin(x) from 0 to 3.14 equals " << std::endl << integralTest; 



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
   double exit_mach = Formulae::find_local_mach(velocity_exit, inputs[Input::CHAMBER_TEMP].value, inputs[Input::GAMMA].value, inputs[Input::MOLECULAR_WEIGHT].value);
   // find epsilon aka the optimim expansion ratio from throat to exit
   double epsilon = Formulae::find_epsilon(inputs[Input::AMBIENT_PRESSURE].value, inputs[Input::CHAMBER_PRESSURE].value, inputs[Input::GAMMA].value); 
   // find thrust coefficient
   double thrust_coefficient = Formulae::find_thrust_coefficient(inputs[Input::GAMMA].value, inputs[Input::AMBIENT_PRESSURE].value, inputs[Input::CHAMBER_PRESSURE].value);
   //find throat area
   double throat_area = Formulae::find_throat_area(inputs[Input::THRUST].value, thrust_coefficient, inputs[Input::CHAMBER_PRESSURE].value);
   // find the exit area
   double exit_area = Formulae::find_exit_area(epsilon, throat_area);

   if (exit_mach <= 1){
    std::cout << "\n Cant exist, exit velocity too low\n";
    system("pause");
    return 0;
    }

   std::cout << "\n";
   // we print the results
   // if = 1 then they get just dimensions
   if (do_they_want_all == 1) {
      std::cout << "The throat area (cm^2): " << 10000 * throat_area << "\n"; // note that these two areas are still stored as m^2; they are simply logged as cm^2 for reading's sake
      std::cout << "The exit area (cm^2): " << 10000 * exit_area << "\n";
      std::cout << "Throat diameter (cm): " << 200 * MathTools::find_radius(throat_area) << "\n"; // also stored as a radius and in meters
      std::cout << "Exit diameter (cm): " << 200 * MathTools::find_radius(exit_area) << "\n";
   }
   //if = 2 then they get armaggedon
   if (do_they_want_all == 2) {
      std::cout << "The mass flow: " << mass_flow << "\n"; // whatever the standard unit of mass flow rate is
      std::cout << "The exit velocity (m/s): " << velocity_exit << "\n";
      std::cout << "The thrust coefficient: " << thrust_coefficient << "\n";
      std::cout << "Speed of sound in the exhaust (m/s): " << Formulae::find_speed_of_sound(inputs[Input::CHAMBER_TEMP].value, inputs[Input::GAMMA].value, inputs[Input::MOLECULAR_WEIGHT].value) << "\n";
      std::cout << "The local Mach at the exit: " << exit_mach << "\n";
      std::cout << "The expansion ratio from throat to exit: " << epsilon << "\n";
      std::cout << "\n";
      std::cout << "The throat area (cm^2): " << 10000 * throat_area << "\n"; // note that these two areas are still stored as m^2; they are simply logged as cm^2 for reading's sake
      std::cout << "The exit area (cm^2): " << 10000 * exit_area << "\n";
      std::cout << "Throat diameter (cm): " << 200 * MathTools::find_radius(throat_area) << "\n"; // also stored as a radius and in meters
      std::cout << "Exit diameter (cm): " << 200 * MathTools::find_radius(exit_area) << "\n";
   }


   if (throat_area > 1) {
      std::cout << "that's a lil big there\n";
   }


   std::cout << "\n";
   system("pause");

   return 0;

   // i go take small nap
}