#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <algorithm>
#include <cerrno>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  virtual ~ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  static std::string trim(const std::string &str);
  static void printLiterals(char ch, int ivalue, float fvalue, double dvalue,
                            int flag);

 public:
  static void convert(const std::string str);
};

#endif
