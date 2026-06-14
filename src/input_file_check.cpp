#include <iostream>
#include <fstream>

int filecheck() {
        /*
    this part just checks if thy files exist
    if you get a number in the one digit you effed up
    if you get a number in the tens digit just rerun it and give it an input.
     */
 int value = 0;
    // gamma in
    std::ifstream gfile("./inputs/gamma.txt");
    if (!gfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("./inputs/gamma.txt");
        value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
              value = value + 1;
        }
        
    }

 // chamber pressure in
    std::ifstream cpfile("./inputs/chamber pressure {pa}.txt");
    if (!cpfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("./inputs/chamber pressure {pa}.txt");
            value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
      
    }

// cumbustion chamber temp in
    std::ifstream ctfile("./inputs/chamber temp.txt");
    if (!ctfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("./inputs/chamber temp.txt");
            value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
  
    }

//thrust wanted in
    std::ifstream nfile("./inputs/thrust wanted {n}.txt");
    if (!nfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("./inputs/thrust wanted {n}.txt");
     value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }

//Molecular weight in
    std::ifstream mwfile("./inputs/Molecular weight.txt");
    if (!mwfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("./inputs/Molecular weight.txt");
         value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }

//ambient pressure
    std::ifstream apafile("./inputs/ambient pressure {pa}.txt");
    if (!apafile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("./inputs/ambient pressure {pa}.txt");
         value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }


//oxidizer to fuel ratio
    std::ifstream offile("./inputs/O-F ratio.txt");
    if (!offile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("./inputs/O-F ratio.txt");
         value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }
    //characteristic chamber length
    std::ifstream cclfile("./inputs/characteristic chamber length {m}.txt");
    if (!cclfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("./inputs/characteristic chamber length {m}.txt");
         value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }
    return value;
}

double numbercheck(c){
    std::string filename = c;
    std::ifstream file(filename);
    double value;
    file >> value;
    std::cout << value << "\n";
    return value;
    
}


