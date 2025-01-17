#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  std::string str;
  std::string temp;
  std::string::size_type strPos = 0;
  if (argc != 4) {
    std::cout << "should enter three parameter!\n";
    return 1;
  }
  std::string fileName = std::string(argv[1]);
  std::string sBefore = std::string(argv[2]);
  std::string sAfter = std::string(argv[3]);

  std::fstream ifs(fileName.c_str(), std::fstream::in | std::fstream::binary);
  if (ifs.is_open()) {
    ifs.seekg(0, std::ios::end);
    long long size = ifs.tellg();
    if (size < 0) {
      std::cout << "file " << fileName << " error!\n";
      ifs.close();
      return 1;
    }
    ifs.seekg(0, std::ios::beg);
    str.resize(size);
    ifs.read(&str[0], size);
    if ((ifs.fail() || ifs.bad()) && !ifs.eof()) {
      std::cout << "file " << fileName << " read error! file size: " << size
                << ", read size: " << ifs.gcount() << std::endl;
      ifs.close();
      return 1;
    }
    str.resize(ifs.gcount());

  } else {
    std::cout << "file: " << fileName << " open error!\n";
    return 1;
  }
  ifs.close();
  std::string::size_type it;
  while ((it = str.find(sBefore, strPos)) != std::string::npos) {
    str.erase(it, sBefore.length());
    str.insert(it, sAfter);
    strPos = it + sAfter.length();
  }

  fileName += ".replace";
  std::fstream ofs(fileName.c_str(), std::fstream::out | std::fstream::trunc);
  if (ofs.is_open()) {
    ofs << str;
  } else {
    std::cout << "file: " << fileName << " open error!\n";
    return 1;
  }
  ofs.close();
  std::cout << "complete!\n";
  return 0;
}
