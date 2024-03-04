#include <iostream>
#include <string>

struct Record {
  int id;
  std::string nama;
  float nilai;
  int loop; 
};

int main() {
    Record sample;
    sample.loop = 10;
    return 0;
}