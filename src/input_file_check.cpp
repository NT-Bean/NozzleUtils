#include <iostream>
#include <fstream>

int filecheck() {
 int value = 0;
    // gamma in
    std::ifstream gfile("gamma.txt");
    if (!gfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("gamma.txt");
        value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
              value = value + 1;
        }
        
    }

 // chamber pressure in
    std::ifstream cpfile("chamber pressure {pa}.txt");
    if (!cpfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("chamber pressure {pa}.txt");
            value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
      
    }

// cumbustion chamber temp in
    std::ifstream ctfile("chamber temp.txt");
    if (!ctfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("chamber temp.txt");
            value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
  
    }

//thrust wanted in
    std::ifstream nfile("thrust wanted {n}.txt");
    if (!nfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("thrust wanted {n}.txt");
     value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }

//Molecular weight in
    std::ifstream mwfile("Molecular weight.txt");
    if (!mwfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("Molecular weight.txt");
         value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }

//ambient pressure
    std::ifstream apafile("ambient pressure {pa}.txt");
    if (!apafile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("ambient pressure {pa}.txt");
         value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }


//oxidizer to fuel ratio
    std::ifstream offile("O-F ratio.txt");
    if (!offile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("O-F ratio.txt");
         value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }
    //characteristic chamber length
    std::ifstream cclfile("characteristic chamber length {m}.txt");
    if (!cclfile.is_open()) {
        std::cout << "File doesn't exist. Creating it.\n";
        std::ofstream createFile("characteristic chamber length {m}.txt");
         value = value + 10;
        if (!createFile.is_open()) {
            std::cout << "Failed to create the file.\n";
            value = value + 1;
        }
        
    }
    return value;
}


int main() {
    /*
    this part just checks if thy files exist
    if you get a number in the one digit you effed up
    if you get a number in the tens digit just rerun it and give it an input.
     */
int checkfile = filecheck();
if (checkfile >= 1){
    std::cout << (checkfile);
    std::exit(0);
}
if (checkfile == 0){
    std::cout << "Inputs Exist\n";
}
    return 0;

//now this is the fun math yippie :
}