#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <algorithm>
#include <cerrno>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#define CHARTYPE 1
#define INTTYPE 2
#define FLOATTYPE 3
#define DOUBLETYPE 4
#define NOTYPE 5

class ScalarConverter {
 private:
  ScalarConverter();
  virtual ~ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);

  static std::string trim(const std::string &str);
  static void printNan();
  static void printLiterals(char ch, int ivalue, float fvalue, double dvalue,
                            int flag);
  static int checkType(const std::string &str);
  static void convertChar(const std::string &str);
  static void convertInt(const std::string &str);
  static void convertFloat(const std::string &str);
  static void convertDouble(const std::string &str);

 public:
  static void convert(const std::string str);
};

#endif
