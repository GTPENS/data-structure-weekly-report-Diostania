#include <iostream>
#include <string>
using namespace std;

struct Zodiak {
  string nama;
  int tglAwal;
  int blnAwal;
  int tglAkhir;
  int blnAkhir;
};
int main() {
  Zodiak bintang = {"Sagitarius", 22, 11, 21, 12};
  int tglLhr, blnLhr, thnLhr;
  cout << "Masukkan tanggal lahir Anda (XX-XX-XXXX): ";
  cin >> tglLhr >> blnLhr >> thnLhr;
  if ((tglLhr >= bintang.tglAwal && blnLhr == bintang.blnAwal) ||
      (tglLhr <= bintang.tglAkhir && blnLhr == bintang.blnAkhir)) {
    cout << "Bintang Anda adalah " << bintang.nama << endl;
  } else {
    cout << "Bintang Anda bukan " << bintang.nama << endl;
  }
  return 0;
}