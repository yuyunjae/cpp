#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    public:
    // Contact();
    ~Contact();
    Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
    const std::string &getFirstName();
    const std::string &getLastName();
    const std::string &getNickname();
    const std::string &getPhoneNumber();
    const std::string &getDarkestSecret();
};


#endif