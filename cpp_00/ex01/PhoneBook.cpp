#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : top(-1), phoneBookSize(0) {
    //   std::cout << "make phonebook!\n";
}

PhoneBook::~PhoneBook() {
    // std::cout << "phonebook instance destroyed!\n";
}

void PhoneBook::addContact() {
    Contact newContact;

    if (!newContact.setContact()) {
        std::cin.clear();
        std::cout << "fail to add contact: format error!\n";
        return;
    }
    std::cout << "contact added successfully!\n";
    this->contacts[(++(this->top)) % 8] = newContact;
    (this->phoneBookSize)++;
}

void PhoneBook::searchContact() {
    int searchIndex = -1;
    if (this->phoneBookSize == 0) {
        std::cout << "no contact in this phonebook!\n";
        return;
    }
    std::cout << "\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "|";
    std::cout << std::setw(10) << "index";
    std::cout << "|";
    std::cout << std::setw(10) << "first name";
    std::cout << "|";
    std::cout << std::setw(10) << "last name";
    std::cout << "|";
    std::cout << std::setw(10) << "nickname";
    std::cout << "|\n";
    std::cout << "--------------------------------------------\n";

    for (int i = 1; i <= std::min(8, this->phoneBookSize); i++) {
        this->phoneBookSize < 8 ? printSimple(i - 1, i)
                                : printSimple((this->top + i) % 8, i);
        std::cout << "--------------------------------------------\n";
    }
    std::cout << "\n";
    std::cout << "enter index: ";
    while (true) {
        if (std::cin >> searchIndex && searchIndex > 0 &&
            searchIndex <= std::min(8, this->phoneBookSize))
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "re enter index: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    printContactAll(this->phoneBookSize < 8 ? searchIndex - 1
                                            : (this->top + searchIndex) % 8);
}

void PhoneBook::printSimpleForm(const std::string &str) {
    if (str.length() > 10) {
        std::cout << str.substr(0, 9) << ".";
    } else
        std::cout << std::setw(10) << str;
}

void PhoneBook::printSimple(int contactIndex, int index) {
    std::cout << "|";
    std::cout << std::setw(10) << index;
    std::cout << "|";
    printSimpleForm(this->contacts[contactIndex].getFirstName());
    std::cout << "|";
    printSimpleForm(this->contacts[contactIndex].getLastName());
    std::cout << "|";
    printSimpleForm(this->contacts[contactIndex].getNickname());
    std::cout << "|\n";
}

void PhoneBook::printContactAll(int contactIndex) {
    std::cout << "first name: " << this->contacts[contactIndex].getFirstName()
              << std::endl;
    std::cout << "last name: " << this->contacts[contactIndex].getLastName()
              << std::endl;
    std::cout << "nickname: " << this->contacts[contactIndex].getNickname()
              << std::endl;
    std::cout << "phone number: "
              << this->contacts[contactIndex].getPhoneNumber() << std::endl;
    std::cout << "darkest secret: "
              << this->contacts[contactIndex].getDarkestSecret() << std::endl;
    std::cout << "\n";
}

bool PhoneBook::program(PhoneBook &phoneBook) {
    std::string command;
    while (true) {
        std::cout << "command$ ";
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
    return true;
}