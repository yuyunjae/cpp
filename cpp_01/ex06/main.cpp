#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "please enter only one argument.\n";
        return 1;
    }
    Harl Harl1;
    Harl1.complain(std::string(argv[1]));
    return 0;
}