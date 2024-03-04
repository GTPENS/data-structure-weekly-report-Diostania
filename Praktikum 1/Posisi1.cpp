#include <iostream>
using namespace std;

struct Koordinat {
  int x;
  int y;
};

void tukar_xy(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  Koordinat posisi;
  cout << "Masukkan koordinat posisi (x, y) : ";
  cin >> posisi.x >> posisi.y;
  cout << "x, y semula = " << posisi.x << ", " << posisi.y << endl;
  tukar_xy(&posisi.x, &posisi.y);
  cout << "x, y sekarang = " << posisi.x << ", " << posisi.y << endl;
  return 0;
}
