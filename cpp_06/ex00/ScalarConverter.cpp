
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
  std::cout << "ScalarConverter default constructor called\n";
}

ScalarConverter::~ScalarConverter() {
  std::cout << "ScalarConverter destructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  std::cout << "ScalarConverter copy constructor called\n";
  (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  std::cout << "ScalarConverter copy assignment operator called\n";
  (void)other;
  return *this;
}

std::string ScalarConverter::trim(const std::string &str) {
  std::string::size_type start = 0, end = str.length();
  while (start < end && std::isspace(str[start])) start++;
  while (end > start && std::isspace(str[end - 1])) end--;
  if (start >= end) {
    if (str.length() == 1 && str[0] == ' ') return " ";
    return "";
  }
  return str.substr(start, end - start);
}

void ScalarConverter::printNan() {
  std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
}

void ScalarConverter::printLiterals(char ch, int ivalue, float fvalue,
                                    double dvalue, int flag) {
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
  std::cout << fvalue << ((fvalue - ivalue) ? "f\n" : ".0f\n");

  std::cout << "double: ";
  std::cout << dvalue << ((fvalue - ivalue) ? "\n" : ".0\n");
}

int ScalarConverter::checkType(const std::string &str) {
  std::string::size_type dot;
  std::string::size_type f;

  dot = str.find('.');
  f = str.find('f', str.length() - 1);

  // inf or nan
  if (str == "nan" || str == "nanf")
    return NOTYPE;
  else if (str == "+inff" || str == "inff" || str == "-inff")
    return FLOATTYPE;
  else if (str == "-inf" || str == "+inf" || str == "inf")
    return DOUBLETYPE;

  // 문자
  if (str.length() == 1 && !std::isdigit(str[0])) return CHARTYPE;

  // 숫자만으로 이루어져있는지 체크
  for (std::string::size_type i = 0; i < str.length(); i++) {
    if (!std::isdigit(str[i])) {
      if (i == 0 && (str[i] == '-' || str[i] == '+')) continue;
      if (i == dot && str[i] == '.') continue;
      if (i == f && str[i] == 'f') continue;
      return NOTYPE;
    }
  }

  if (dot == std::string::npos && f == std::string::npos)
    return INTTYPE;
  else if (dot != std::string::npos && f == std::string::npos)
    return DOUBLETYPE;
  else if (dot != std::string::npos && f != std::string::npos)
    return FLOATTYPE;
  return NOTYPE;
}

void ScalarConverter::convertChar(const std::string &str) {
  char ch = 0;
  int ivalue = 0;
  float fvalue = 0;
  double dvalue = 0;

  ch = static_cast<char>(str[0]);
  ivalue = static_cast<int>(ch);
  fvalue = static_cast<float>(ch);
  dvalue = static_cast<double>(ch);
  printLiterals(ch, ivalue, fvalue, dvalue, 0);
}

void ScalarConverter::convertInt(const std::string &str) {
  char ch = 0;
  int ivalue = 0;
  float fvalue = 0;
  double dvalue = 0;
  char flag = 0;
  /*
  1      nan
  1 << 1 Inf
  1 << 2 -Inf
  1 << 3 char overflow
  1 << 4 char underflow
  1 << 5 int overflow
  1 << 6 int underflow
  */
  char *endptr = 0;
  std::stringstream ss;
  std::string check;
  errno = 0;

  ivalue = atoi(str.c_str());
  ss << ivalue;
  ss >> check;
  if (str == check || (str[0] == '+' && str.substr(1) == check) ||
      (ivalue == 0 && str[0] == '-' && str[1] == '0')) {  // common case
    if (ivalue > 127)
      flag |= 1 << 3;
    else if (ivalue < -128)
      flag |= 1 << 4;
    fvalue = static_cast<float>(ivalue);
    dvalue = static_cast<double>(ivalue);
  } else {
    if (str[0] == '-') {  // underflow
      flag |= 1 << 4;
      flag |= 1 << 6;
    } else {  // overflow
      flag |= 1 << 3;
      flag |= 1 << 5;
    }
    dvalue = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0' && *endptr != 'f') return printNan();
    fvalue = static_cast<float>(dvalue);
  }
  ch = static_cast<char>(ivalue);
  printLiterals(ch, ivalue, fvalue, dvalue, flag);
}

void ScalarConverter::convertFloat(const std::string &str) {
  char ch = 0;
  int ivalue = 0;
  float fvalue = 0;
  double dvalue = 0;
  char flag = 0;
  char *endptr = 0;

  // inf 처리
  if (str == "+inff" || str == "inff") {
    fvalue = std::numeric_limits<float>::infinity();
    dvalue = std::numeric_limits<double>::infinity();
    flag |= 1 << 1;
    return printLiterals(ch, ivalue, fvalue, dvalue, flag);
  } else if (str == "-inff") {
    fvalue = -std::numeric_limits<float>::infinity();
    dvalue = -std::numeric_limits<double>::infinity();
    flag |= 1 << 2;
    return printLiterals(ch, ivalue, fvalue, dvalue, flag);
  }
  errno = 0;
  fvalue = std::strtof(str.c_str(), &endptr);
  if (*endptr != '\0' && *endptr != 'f') return printNan();

  if (errno == ERANGE) {  // overflow occur
    if (str[0] == '-') {
      flag |= 1 << 4;
      flag |= 1 << 6;
    } else {
      flag |= 1 << 3;
      flag |= 1 << 5;
    }
    dvalue = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0' && *endptr != 'f') return printNan();
  } else {  // common case
    if (fvalue > CHAR_MAX) {
      flag |= 1 << 3;
      if (fvalue > INT_MAX) flag |= 1 << 5;
    } else if (fvalue < CHAR_MIN) {
      flag |= 1 << 4;
      if (fvalue < INT_MIN) flag |= 1 << 6;
    }
    dvalue = static_cast<double>(fvalue);
  }
  ch = static_cast<char>(fvalue);
  ivalue = static_cast<int>(fvalue);

  printLiterals(ch, ivalue, fvalue, dvalue, flag);
}

void ScalarConverter::convertDouble(const std::string &str) {
  char ch = 0;
  int ivalue = 0;
  float fvalue = 0;
  double dvalue = 0;
  char flag = 0;
  char *endptr = 0;

  if (str == "+inf" || str == "inf") {
    fvalue = std::numeric_limits<float>::infinity();
    dvalue = std::numeric_limits<double>::infinity();
    flag |= 1 << 1;
    return printLiterals(ch, ivalue, fvalue, dvalue, flag);
  } else if (str == "-inf") {
    fvalue = -std::numeric_limits<float>::infinity();
    dvalue = -std::numeric_limits<double>::infinity();
    flag |= 1 << 2;
    return printLiterals(ch, ivalue, fvalue, dvalue, flag);
  }

  errno = 0;
  dvalue = std::strtod(str.c_str(), &endptr);
  if (*endptr != '\0' && *endptr != 'f') return printNan();

  if (errno == ERANGE) {
    if (str[0] == '-') {
      flag |= 1 << 4;
      flag |= 1 << 6;
    } else {
      flag |= 1 << 3;
      flag |= 1 << 5;
    }
  } else {
    if (dvalue > CHAR_MAX) {
      flag |= 1 << 3;
      if (dvalue > INT_MAX) flag |= 1 << 5;
    } else if (dvalue < CHAR_MIN) {
      flag |= 1 << 4;
      if (dvalue < INT_MIN) flag |= 1 << 6;
    }
  }
  ch = static_cast<char>(dvalue);
  ivalue = static_cast<int>(dvalue);
  fvalue = static_cast<float>(dvalue);
  printLiterals(ch, ivalue, fvalue, dvalue, flag);
}

void ScalarConverter::convert(const std::string str) {
  std::string substr = trim(str);

  // trim이후 어떤 문자도 없음.
  if (substr.length() < 1) return printNan();
  int literalType = checkType(substr);
  switch (literalType) {
    case CHARTYPE:
      convertChar(substr);
      break;
    case INTTYPE:
      convertInt(substr);
      break;
    case FLOATTYPE:
      convertFloat(substr);
      break;
    case DOUBLETYPE:
      convertDouble(substr);
      break;
    case NOTYPE:
      printNan();
      break;
    default:
      printNan();
  }
}
