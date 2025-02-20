
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
  std::cout << "ScalarConverter default constructor called\n";
}

ScalarConverter::~ScalarConverter() {
  std::cout << "ScalarConverter destructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  std::cout << "ScalarConverter copy constructor called\n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  std::cout << "ScalarConverter copy assignment operator called\n";
  return *this;
}

std::string ScalarConverter::trim(const std::string &str) {
  std::string::size_type start = 0, end = str.length();
  while (start < end && std::isspace(str[start])) start++;
  while (end > start && std::isspace(str[end - 1])) end--;
  if (start > end) return "";
  return str.substr(start, end - start);
}

void ScalarConverter::convert(const std::string str) {
  std::string substr = trim(str);
  std::string::size_type dot;
  std::string::size_type f;
  char ch;
  int ivalue;
  float fvalue;
  double dvalue;

  if (substr.length() < 1) {  // 빈공간만 있을 때
    std::cerr << "Not a value!\n";
    return;
  }
  dot = str.find('.');
  f = str.find('f', str.length() - 1);

  if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" ||
      str == "+inf" || str == "nan" || str == "inf" || str == "inff") {
    if (str == "nan" || str == "nanf") {
      c
    }
  }
}
