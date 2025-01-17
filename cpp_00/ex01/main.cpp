#include "PhoneBook.hpp"

int main(void) {
  PhoneBook phoneBook;
  if (phoneBook.program(phoneBook))
    return 0;
  else
    return 1;
}
