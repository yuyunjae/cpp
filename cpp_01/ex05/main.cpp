#include "Harl.hpp"

int main(void) {
    const std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Harl harl1;
    Harl harl2("debug msg", "info msg", "warning msg", "error msg");

    std::cout << "harl1 complain\n";
    for (int i = 0; i < 4; i++) {
        harl1.complain(str[i]);
    }
    std::cout << "harl2 complain\n";
    for (int i = 0; i < 4; i++) {
        harl2.complain(str[i]);
    }
    harl2.complain("F");
    return 0;
}