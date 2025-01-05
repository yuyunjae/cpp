#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : top(-1), phoneBookSize(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact() {
    Contact newContact;

    if (!newContact.setContact()) {
        std::cout << "fail to add contact: format error!\n";
        return;
    }
    std::cout << "contact added successfully!\n";
    this->contacts[(++(this->top)) % 8] = newContact;
    this->phoneBookSize++;
}

void PhoneBook::searchContact() {  // 미완
    //
}

bool PhoneBook::program(PhoneBook &phoneBook) {
    std::string command;
    while (true) {
        std::cout << "command$ ";  // 이거 조건 위반? : Unless specified
        // otherwise, every output messages must be ended by a new-line
        // character and displayed to the standard output
        if (!std::getline(std::cin, command)) return false;
        if (!command.compare("EXIT"))
            break;
        else if (!command.compare("ADD"))
            phoneBook.addContact();
        else if (!command.compare("SEARCH"))
            phoneBook.searchContact();
        else if (command.length() > 0)
            std::cout << command << ": command not found!\n";
    }
    return true;  // 정상 종료
}