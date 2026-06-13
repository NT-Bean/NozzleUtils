#include "input_file_check.cpp"

int main() {
    /*
        this part just checks if thy files exist
        if you get a number in the one digit you effed up
        if you get a number in the tens digit just rerun it.
    */
    int checkfile = inputFileCheck();
    if (checkfile >= 1) {
        std::cout << (checkfile);
        std::exit(0);
    }
    if (checkfile == 0) {
        std::cout << "Inputs Exist\n";
    }
    return 0;

    // now this is the fun math:

}
