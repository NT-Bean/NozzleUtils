#include <iostream>
#include <fstream>
#include <vector>

int inputFileCheck() {

    int value = 0;

    std::vector<const char*> inputFilepaths =
    {
        "gamma.txt",
        "chamber pressure {pa}.txt",
        "chamber temp.txt",
        "thrust wanted {n}.txt",
        "Molecular weight.txt",
        "ambient pressure {pa}.txt",
        "O-F ratio.txt",
        "characteristic chamber length {m}.txt"
    };

    for(int i = 0; i < inputFilepaths.size(); i++)
    {
        std::ifstream gfile(inputFilepaths[i]);
        if (!gfile.is_open()) {
            std::cout << "File doesn't exist. Creating it.\n";
            std::ofstream createFile(inputFilepaths[i]);
            value += 10;
            if (!createFile.is_open()) {
                std::cout << "Failed to create the file.\n";
                value++;
            }
        }
    }

    return value;
}