#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> ListofFilePaths = {
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

int filecheck() {
        /*
    this part just checks if thy files exist and if not creates them
    if you get a number in the one digit you effed up
    if you get a number in the tens digit just rerun it and give it an input.
     */
    int value = 0;

    for (int i = 0; i < ListofFilePaths.size(); i++)
    {
        std::ifstream gfile(ListofFilePaths[i]);
        if (!gfile.is_open()) {
            std::cout << "File doesn't exist. Creating it.\n";
            std::ofstream createFile(ListofFilePaths[i]);
            value = value + 10;
            if (!createFile.is_open()) {
                std::cout << "Failed to create the file.\n";
                value = value + 1;
            }
            
        }
    }
    return value;
}

int handleFileErrors(int errorCode)
{
    switch (errorCode)
    {
        case 0:
            std::cout << "Inputs Exist\n";
            return 0;
            break;
        case 90:
            std::cout << "Input files did not exist. Fill out the generated input files and rerun the program\n";
            return -90;
            break;
        case 99:
            std::cout << "The input files could not be generated. Are you missing an `./inputs` directory?\n";
            return -99;
            break;
        default:
            std::cout << "An unknown error occurred.\n";
            return -1;
            break;
    }
}

// this part checks what the value of the file is and returns it 
double numbercheck(std::string c){
    std::string filename = c;
    std::ifstream file(filename);
    double value;
    file >> value;
    // std::cout << value << "\n";
    return value;
    
}