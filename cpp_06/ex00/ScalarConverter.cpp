
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
    std::cout << fvalue << 'f' << std::endl;

  std::cout << "double: ";
  if (flag & (1 << 9))
    std::cout << "overflow\n";
  else if (flag & (1 << 10))
    std::cout << "underflow\n";
  else
    std::cout << dvalue << std::endl;
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

  // 숫자만으로 이루어져있는지 체크
  for (std::string::size_type i = 0; i < str.length(); i++) {
    if (!std::isdigit(str[i])) {
      if (i == 0 && (str[i] == '-' || str[i] == '+')) continue;
      if (i == dot && str[i] == '.') continue;
      if (i == f && str[i] == 'f') continue;
      return NOTYPE;
    }
  }

  if (str.length() == 1 && !std::isdigit(str[0]))
    return CHARTYPE;
  else if (dot == std::string::npos && f == std::string::npos)
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

void ScalarConverter::convertDouble(const std::string &str) {
  char ch = 0;
  int ivalue = 0;
  float fvalue = 0;
  double dvalue = 0;
  char *endptr = 0;

  if (str == "+inf" || str == "inf") {
    fvalue = std::numeric_limits<float>::infinity();
    dvalue = std::numeric_limits<double>::infinity();
  } else if (str == "-inf") {
    fvalue = -std::numeric_limits<float>::infinity();
    dvalue = -std::numeric_limits<double>::infinity();
  }
  errno = 0;
  dvalue = std::strtod(str.c_str(), &endptr);
  if (*endptr != '\0' && *endptr != 'f') return printNan();

  if (errno == ERANGE) {
    if (str[0] == '-') {
      flag += 1 << 4;
      flag += 1 << 6;
      flag += 1 << 8;
      flag += 1 << 10;
    } else {
      flag += 1 << 3;
      flag += 1 << 5;
      flag += 1 << 7;
      flag += 1 << 9;
    }
  } else {
    if (dvalue > CHAR_MAX) {
      flag += 1 << 3;
      if (dvalue > INT_MAX) {
        flag += 1 << 5;
        if (dvalue > std::numeric_limits<float>::max())
          flag += 1 << 7;
        else
          fvalue = static_cast<float>(dvalue);
      } else
        ivalue = static_cast<int>(dvalue);
    } else if (dvalue < CHAR_MIN) {
      flag += 1 << 4;
      if (dvalue < INT_MIN) {
        flag += 1 << 6;
        if (dvalue < std::numeric_limits<float>::min())
          flag += 1 << 8;
        else
          fvalue = static_cast<float>(dvalue);
      } else
        ivalue = static_cast<int>(dvalue);
    } else {
      ch = static_cast<char>(dvalue);
      ivalue = static_cast<int>(dvalue);
      fvalue = static_cast<float>(dvalue);
    }
  }
}

void ScalarConverter::convert(const std::string str) {
  std::string substr = trim(str);

  // 빈공간만 있을 때
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

  std::string::size_type dot;
  std::string::size_type f;

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
      substr = " ";
    else {
      flag += 1 << 11;
      return printLiterals(ch, ivalue, fvalue, dvalue, flag);
    }
  }
  dot = substr.find('.');
  f = substr.find('f', substr.length() - 1);

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
    } else if (substr[0] == '-') {
      flag += 1 << 4;
      flag += 1 << 6;
      // float double underflow 여부 체크해야함.
    } else {  // overflow
      flag += 1 << 3;
      flag += 1 << 5;
    }
    fvalue = static_cast<float>(ivalue);
    dvalue = static_cast<double>(ivalue);
  }

  // float
  else if (dot != std::string::npos && f != std::string::npos) {
    errno = 0;
    char *endptr = 0;

    fvalue = std::strtof(substr.c_str(), &endptr);
    if (*endptr != '\0' && *endptr != 'f') {
      flag += 1 << 11;
      return printLiterals(ch, ivalue, fvalue, dvalue, flag);
    }
    if (errno == ERANGE) {
      if (substr[0] == '-') {
        flag += 1 << 4;
        flag += 1 << 6;
        flag += 1 << 8;
      } else {
        flag += 1 << 3;
        flag += 1 << 5;
        flag += 1 << 7;
      }
    } else {
      if (fvalue > CHAR_MAX) {
        flag += 1 << 3;
        if (fvalue > INT_MAX)
          flag += 1 << 5;
        else
          ivalue = static_cast<int>(fvalue);
      } else if (fvalue < CHAR_MIN) {
        flag += 1 << 4;
        if (fvalue < INT_MIN)
          flag += 1 << 6;
        else
          ivalue = static_cast<int>(fvalue);
      } else {
        ch = static_cast<char>(fvalue);
        ivalue = static_cast<int>(fvalue);
      }
    }
    dvalue = static_cast<float>(fvalue);
  }

  // double
  else if (dot != std::string::npos && f == std::string::npos) {
    errno = 0;
    char *endptr = 0;

    dvalue = std::strtod(substr.c_str(), &endptr);
    if (*endptr != '\0' && *endptr != 'f') {
      flag += 1 << 11;
      return printLiterals(ch, ivalue, fvalue, dvalue, flag);
    }

    if (errno == ERANGE) {
      if (substr[0] == '-') {
        flag += 1 << 4;
        flag += 1 << 6;
        flag += 1 << 8;
        flag += 1 << 10;
      } else {
        flag += 1 << 3;
        flag += 1 << 5;
        flag += 1 << 7;
        flag += 1 << 9;
      }
    } else {
      if (dvalue > CHAR_MAX) {
        flag += 1 << 3;
        if (dvalue > INT_MAX) {
          flag += 1 << 5;
          if (dvalue > std::numeric_limits<float>::max())
            flag += 1 << 7;
          else
            fvalue = static_cast<float>(dvalue);
        } else
          ivalue = static_cast<int>(dvalue);
      } else if (dvalue < CHAR_MIN) {
        flag += 1 << 4;
        if (dvalue < INT_MIN) {
          flag += 1 << 6;
          if (dvalue < std::numeric_limits<float>::min())
            flag += 1 << 8;
          else
            fvalue = static_cast<float>(dvalue);
        } else
          ivalue = static_cast<int>(dvalue);
      } else {
        ch = static_cast<char>(dvalue);
        ivalue = static_cast<int>(dvalue);
        fvalue = static_cast<float>(dvalue);
      }
    }
  }
  return printLiterals(ch, ivalue, fvalue, dvalue, flag);
}
