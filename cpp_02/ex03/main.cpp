#include <iostream>

#include "Point.hpp"

#define MAPX 100
#define MAPY 100

int main(void) {
  bool arr[MAPY][MAPX] = {};
  float i = 0.0f, j = 0.0f;
  Point st(1, 1);
  Point nd(4, 2);
  Point rd(2, 3);

  std::cout << "point (" << st.getX() << "," << st.getY() << "), \n";
  std::cout << "point (" << nd.getX() << "," << nd.getY() << "), \n";
  std::cout << "point (" << rd.getX() << "," << rd.getY() << ")\n";
  for (int y = 0; y < MAPY; y++) {
    j = 0.0f;
    for (int x = 0; x < MAPX; x++) {
      Point point(j, i);
      if (point.bsp(st, nd, rd, point)) {
        std::cout << "Point x: " << point.getX() << ", y: " << point.getY()
                  << " = " << "true\n";
        arr[y][x] = true;
      } else {
        std::cout << "Point x: " << point.getX() << ", y: " << point.getY()
                  << " = " << "false\n";
        arr[y][x] = false;
      }
      j += 0.1f;
    }
    i += 0.1f;
  }
  std::cout << "\n\npoint (" << st.getX() << "," << st.getY() << "), \n";
  std::cout << "point (" << nd.getX() << "," << nd.getY() << "), \n";
  std::cout << "point (" << rd.getX() << "," << rd.getY() << ")\n";
  for (int y = MAPY - 1; y >= 0; y--) {
    for (int x = 0; x < MAPX; x++) {
      if (arr[y][x])
        std::cout << "X";
      else
        std::cout << ".";
    }
    std::cout << std::endl;
  }
  return 0;
}
