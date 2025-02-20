
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

void ScalarConverter::printLiterals(char ch, int ivalue, float fvalue,
                                    double dvalue, int flag) {
  if (flag & (1 << 11) || flag & 1) {
    std::cout
        << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
    return;
  }

  std::cout << "char: ";
  if (flag & (1 << 3) || flag & (1 << 1))
    std::cout << "overflow\n";
  else if (flag & (1 << 4) || flag & (1 << 2))
    std::cout << "underflow\n";
  else if (std::isprint(ch))
    std::cout << "'" << ch << "'" << std::endl;
  else
    std::cout << "Non displayable\n";

  std::cout << "int: ";
  if (flag & (1 << 5) || flag & (1 << 1))
    std::cout << "overflow\n";
  else if (flag & (1 << 6) || flag & (1 << 2))
    std::cout << "underflow\n";
  else
    std::cout << ivalue << std::endl;

  std::cout << "float: ";
  if (flag & (1 << 7))
    std::cout << "overflow\n";
  else if (flag & (1 << 8))
    std::cout << "underflow\n";
  else
    std::cout << fvalue << std::endl;

  std::cout << "double: ";
  if (flag & (1 << 9))
    std::cout << "overflow\n";
  else if (flag & (1 << 10))
    std::cout << "underflow\n";
  else
    std::cout << dvalue << std::endl;
}

void ScalarConverter::convert(const std::string str) {
  std::string substr = trim(str);
  std::string::size_type dot;
  std::string::size_type f;
  char ch = 0;
  int ivalue = 0;
  float fvalue = 0;
  double dvalue = 0;
  int flag = 0;
  /*
  1      nan
  1 << 1 Inf
  1 << 2 -Inf
  1 << 3 char overflow
  1 << 4 char underflow
  1 << 5 int overflow
  1 << 6 int underflow
  1 << 7 float overflow
  1 << 8 float underflow
  1 << 9 double overflow
  1 << 10 double underflow
  1 << 11 Not a value error
  1 << 12 char's Non displayable // 이건 printLiterals에서 체크하는게 맞을 듯
  */

  if (substr.length() < 1) {  // 빈공간만 있을 때
    if (str.length() == 1 && str[0] == ' ')
      substr == " ";
    else {
      flag += 1 << 11;
      return printLiterals(ch, ivalue, fvalue, dvalue, flag);
    }
  }
  dot = substr.find('.');
  f = substr.find('f', substr.length() - 1);
  // if (substr.find('.', dot + 1) != std::string::npos) {
  //   flag += 1 << 11;
  //   return printLiterals(ch, ivalue, fvalue, dvalue, flag);
  // }

  // inf or nan
  if (substr == "-inff" || substr == "+inff" || substr == "nanf" ||
      substr == "-inf" || substr == "+inf" || substr == "nan" ||
      substr == "inf" || substr == "inff") {
    if (substr == "nan" || substr == "nanf") {
      fvalue = std::nanf("");
      dvalue = std::nan("");
      flag += 1;
    } else if (substr[0] == '-') {
      fvalue = -std::numeric_limits<float>::infinity();
      dvalue = -std::numeric_limits<double>::infinity();
      flag += 1 << 1;
    } else {
      fvalue = std::numeric_limits<float>::infinity();
      dvalue = std::numeric_limits<double>::infinity();
      flag += 1 << 2;
    }
    return printLiterals(ch, ivalue, fvalue, dvalue, flag);
  }

  // 숫자만으로 이루어져있는지 체크
  for (std::string::size_type i = 0; i < substr.length(); i++) {
    if (!std::isdigit(substr[i])) {
      if (i == 0 && (substr[i] == '-' || substr[i] == '+')) continue;
      if (i == dot && substr[i] == '.') continue;
      if (i == f && substr[i] == 'f') continue;
      flag += 1 << 11;
      return printLiterals(ch, ivalue, fvalue, dvalue, flag);
    }
  }

  // char
  if (substr.length() == 1 && !std::isdigit(substr[0])) {
    ch = static_cast<char>(substr[0]);
    ivalue = static_cast<int>(ch);
    fvalue = static_cast<float>(ch);
    dvalue = static_cast<double>(ch);
  }

  // int
  else if (dot == std::string::npos && f == std::string::npos) {
    std::stringstream ss;
    std::string check;
    ivalue = atoi(substr.c_str());
    ss << ivalue;
    ss >> check;
    if (substr == check || (substr[0] == '+' && substr.substr(1) == check)) {
      if (ivalue >= -128 && ivalue <= 127)
        ch = static_cast<char>(ivalue);
      else if (ivalue > 0)
        flag += 1 << 3;
      else
        flag += 1 << 4;
      fvalue = static_cast<float>(ivalue);
      dvalue = static_cast<double>(ivalue);
    } else if (substr[0] == '-') {
      flag += 1 << 4;
      flag += 1 << 6;
      // float double overflow 여부 체크해야함.
    }
  }
  // float
  else if (dot != std::string::npos && f != std::string::npos) {
    //
  }
  // double
  else if (dot != std::string::npos && f == std::string::npos) {
    std::stringstream ss;
    std::string check;
    char *endptr = 0;

    dvalue = std::strtod(substr.c_str(), &endptr);
    if (*endptr != '\0' && *endptr != 'f') {
      flag += 1 << 11;
      return printLiterals(ch, ivalue, fvalue, dvalue, flag);
    }
    // 오버플로우..
  }
}
