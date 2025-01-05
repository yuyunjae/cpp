#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
   private:
    int top;
    int phoneBookSize;
    Contact contacts[8];

    void addContact();
    void searchContact();
    void printSimpleForm(const std::string &str);
    void printSimple(int contactIndex, int index);
    void printContactAll(int contactIndex);

   public:
    PhoneBook();
    ~PhoneBook();

    static bool program(PhoneBook &phoneBook);
};

#endif
