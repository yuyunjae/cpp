#include "PhoneBook.hpp"

int main(void) {
    PhoneBook phoneBook;
    if (phoneBook.program(phoneBook))
        exit(0);
    else
        exit(1);
}