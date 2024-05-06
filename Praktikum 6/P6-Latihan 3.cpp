#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Pegawai {
    int nip;
    string nama;
};
void tukar(Pegawai& a, Pegawai& b) {
    Pegawai temp = a;
    a = b;
    b = temp;
}
// Metode pengurutan: insertion sort
void insertionSort(Pegawai data[], int n, bool naik, string kriteria) {
    for (int i = 1; i < n; i++) {
        int j = i;
        Pegawai key = data[i];
        while (j > 0 && (naik ? (kriteria == "nip" ? data[j - 1].nip > key.nip : data[j - 1].nama > key.nama)
                                 : (kriteria == "nip" ? data[j - 1].nip < key.nip : data[j - 1].nama < key.nama))) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = key;
    }
}

int main() {
    const int MAX = 5;
    Pegawai data[MAX] = {
        {1, "Dio"},
        {5, "Nauval"},
        {3, "Rakha"},
        {2, "Jagur"},
        {4, "Rifath"}
    };

    int choice;
    bool naik;
    string kriteria;
    while (true) {
        cout << "Pilih metode pengurutan:\n";
        cout << "1. NIP naik\n";
        cout << "2. NIP turun\n";
        cout << "3. NAMA naik\n";
        cout << "4. NAMA turun\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (choice == 5) {
            break;
        }
        cout << "Masukkan pengurutan naik (true) atau turun (false): ";
        cin >> naik;
        if (choice == 1 || choice == 2) {
            kriteria = "nip";
        } else {
            kriteria = "nama";
        }
        insertionSort(data, MAX, naik, kriteria);
        cout << "Hasil pengurutan:\n";
        for (int i = 0; i < MAX; i++) {
            cout << "NIP: " << data[i].nip << ", NAMA: " << data[i].nama << endl;
        }
        cout << endl;
    }
    return 0;
}