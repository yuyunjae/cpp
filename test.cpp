#include <iostream>
#include <string>

int main(void) {
    std::string str;

    str = "0123456789";
    std::cout << str.substr(0, 9);
}