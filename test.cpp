#include <stdio.h>

#include <iostream>
#include <string>

int main(void) {
  std::string str;

  str = "0123456789";
  int num1 = 10;
  int num2 = -10;
  float num = 1.5;
  unsigned char *cNum1 = (unsigned char *)&num1;
  unsigned char *cNum = (unsigned char *)&num;
  printf("%p %p: %d %d %d %d\n", &cNum, cNum1, cNum[0], cNum[1], cNum[2],
         cNum[3]);
  //   std::cout << str.substr(0, 9);
  //   printf("Byte %d: 0x%02X\n", 0, cNum[0]);
}
