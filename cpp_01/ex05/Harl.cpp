#include "Harl.hpp"

const std::string Harl::str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl() {
    this->debugMsg =
        "I love having extra bacon for my "
        "7XL-double-cheese-triple-pickle-specialketchup burger.\nI "
        "really do!";
    this->infoMsg =
        "I cannot believe adding extra bacon costs more money.\nYou "
        "didn't put enough bacon in my burger!\nIf you did, I wouldn't "
        "be asking for more!";
    this->warningMsg =
        "I think I deserve to have some extra bacon for free.\nI've been "
        "coming for years whereas you started working here since last month.";
    this->errorMsg =
        "This is unacceptable!\nI want to speak to the manager now.";
}

Harl::Harl(std::string debugMsg, std::string infoMsg, std::string warningMsg,
           std::string errorMsg)
    : debugMsg(debugMsg),
      infoMsg(infoMsg),
      warningMsg(warningMsg),
      errorMsg(errorMsg) {
}

Harl::~Harl() {
}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\n";
    std::cout << this->debugMsg << "\n\n";
}

void Harl::info(void) {
    std::cout << "[ INFO ]\n";
    std::cout << this->infoMsg << "\n\n";
}
void Harl::warning(void) {
    std::cout << "[ WARNING ]\n";
    std::cout << this->warningMsg << "\n\n";
}
void Harl::error(void) {
    std::cout << "[ ERROR ]\n";
    std::cout << this->errorMsg << "\n\n";
}

void Harl::complain(std::string level) {
    void (Harl::* callFunction[4])() = {};
    callFunction[0] = &Harl::debug;
    callFunction[1] = &Harl::info;
    callFunction[2] = &Harl::warning;
    callFunction[3] = &Harl::error;

    for (int i = 0; i < 4; i++) {
        if (!str[i].compare(level)) {
            (this->*callFunction[i])();
            // std::cout << "okaY!" << std::endl;
            return;
        }
    }
    std::cout << level << " : There is no corresponding level!\n";
}
