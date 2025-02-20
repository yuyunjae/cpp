#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  virtual ~ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  static std::string trim(const std::string &str);

 public:
  static void convert(const std::string str);
};

#endif
