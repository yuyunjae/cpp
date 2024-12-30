#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
   private:
    int top;
    int phoneBookSize;
    Contact contacts[8];
    void addContact();
    void searchContact();

   public:
    PhoneBook();
    ~PhoneBook();
    static bool program(PhoneBook &phoneBook);
};

#endif