#include "Contact.hpp"

Contact::Contact()
    : firstName(""),
      lastName(""),
      nickname(""),
      phoneNumber(""),
      darkestSecret("") {
  //   std::cout << "make contact!\n";
}

Contact::Contact(std::string firstName, std::string lastName,
                 std::string nickname, std::string phoneNumber,
                 std::string darkestSecret) {
  //   std::cout << "make contact!\n";
  if (!setContact(firstName, lastName, nickname, phoneNumber, darkestSecret))
    std::cout << "fail to set contact: format error!\n";
}

Contact::~Contact() {
  //  std::cout << "contact instance destroyed!\n";
}

bool Contact::checkIsPrint(const std::string &str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (!std::isprint(str[i])) return false;
  }
  return true;
}

bool Contact::checkInput(const std::string &str) {
  if (str.length() < 1 || !checkIsPrint(str)) return false;
  return true;
}

// bool Contact::checkCin() {
//   if (std::cin.fail() || std::cin.eof() || std::cin.bad()) return false;
//   return true;
// }

Contact &Contact::operator=(const Contact &other) {
  if (this != &other) {
    this->firstName = other.firstName;
    this->lastName = other.lastName;
    this->nickname = other.nickname;
    this->phoneNumber = other.phoneNumber;
    this->darkestSecret = other.darkestSecret;
  }
  return *this;
}

bool Contact::setContact() {
  std::cout << "first name: ";
  if (!std::getline(std::cin, this->firstName) || !checkInput(this->firstName))
    return false;
  std::cout << "last name: ";
  if (!std::getline(std::cin, this->lastName) || !checkInput(this->lastName))
    return false;
  std::cout << "nick name: ";
  if (!std::getline(std::cin, this->nickname) || !checkInput(this->nickname))
    return false;
  std::cout << "phone number: ";
  if (!std::getline(std::cin, this->phoneNumber) ||
      !checkInput(this->phoneNumber))
    return false;
  std::cout << "darkest secret: ";
  if (!std::getline(std::cin, this->darkestSecret) ||
      !checkInput(this->darkestSecret))
    return false;
  return true;
}

bool Contact::setContact(std::string firstName, std::string lastName,
                         std::string nickname, std::string phoneNumber,
                         std::string darkestSecret) {
  if (!checkInput(firstName) || !checkInput(lastName) ||
      !checkInput(nickname) || !checkInput(phoneNumber) ||
      !checkInput(darkestSecret)) {
    return false;
  }
  this->firstName = firstName;
  this->lastName = lastName;
  this->nickname = nickname;
  this->phoneNumber = phoneNumber;
  this->darkestSecret = darkestSecret;
  return true;
}

const std::string &Contact::getFirstName() { return this->firstName; }

const std::string &Contact::getLastName() { return this->lastName; }

const std::string &Contact::getNickname() { return this->nickname; }

const std::string &Contact::getPhoneNumber() { return this->phoneNumber; }

const std::string &Contact::getDarkestSecret() { return this->darkestSecret; }
