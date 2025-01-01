#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Contact {
 private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

  bool checkIsPrint(const std::string &str);
  bool checkInput(const std::string &str);
  //   bool checkCin();

 public:
  Contact();
  Contact(std::string firstName, std::string lastName, std::string nickname,
          std::string phoneNumber, std::string darkestSecret);
  ~Contact();
  Contact &operator=(const Contact &other);

  bool setContact();
  bool setContact(std::string firstName, std::string lastName,
                  std::string nickname, std::string phoneNumber,
                  std::string darkestSecret);
  const std::string &getFirstName();
  const std::string &getLastName();
  const std::string &getNickname();
  const std::string &getPhoneNumber();
  const std::string &getDarkestSecret();
};

#endif
