#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
   private:
    static const std::string str[4];
    std::string debugMsg;
    std::string infoMsg;
    std::string warningMsg;
    std::string errorMsg;
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

   public:
    Harl();
    Harl(std::string debugMsg, std::string infoMsg, std::string warningMsg,
         std::string errorMsg);
    ~Harl();
    void complain(std::string level);
};

#endif