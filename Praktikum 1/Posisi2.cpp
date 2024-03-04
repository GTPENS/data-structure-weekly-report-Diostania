#include <iostream>
using namespace std;

struct Koordinat {
  int x;
  int y;
};

void tukar_xy(Koordinat* pos_xy) {
  int temp;
  temp = pos_xy->x;
  pos_xy->x = pos_xy->y;
  pos_xy->y = temp;
}

int main() {
  Koordinat posisi;
  cout << "Masukkan koordinat posisi (x, y) : ";
  cin >> posisi.x >> posisi.y;
  cout << "x, y semula = " << posisi.x << ", " << posisi.y << endl;
  tukar_xy(&posisi);
  cout << "x, y sekarang = " << posisi.x << ", " << posisi.y << endl;
  return 0;
}
