#include <iostream>
#include <string>
#include <algorithm>

#define MAX 10

using namespace std;

// Struktur data untuk Pegawai
struct Pegawai {
    string NIP;
    string NAMA;
    int UMUR;
    double GAJI;
};
// Fungsi untuk membandingkan Pegawai berdasarkan NIP secara naik
bool compareByNIPAsc(const Pegawai& a, const Pegawai& b) {
    return a.NIP < b.NIP;
}
// Fungsi untuk membandingkan Pegawai berdasarkan NIP secara turun
bool compareByNIPDesc(const Pegawai& a, const Pegawai& b) {
    return a.NIP > b.NIP;
}
// Fungsi untuk membandingkan Pegawai berdasarkan NAMA secara naik
bool compareByNamaAsc(const Pegawai& a, const Pegawai& b) {
    return a.NAMA < b.NAMA;
}
// Fungsi untuk membandingkan Pegawai berdasarkan NAMA secara turun
bool compareByNamaDesc(const Pegawai& a, const Pegawai& b) {
    return a.NAMA > b.NAMA;
}
int main()
{
    Pegawai dataPegawai[MAX] = {
        {"395", "Dio", 19, 5000},
        {"841", "Nauval", 22, 6000},
        {"611", "Rakha", 54, 5500},
        {"159", "Jagur", 26, 5200},
        {"048", "Lauresta", 18, 6500},
        {"753", "Febby", 24, 4800},
        {"479", "Adelia", 29, 5300},
        {"406", "Ryan Gosling", 48, 5800},
        {"124", "Jesse", 31, 5700},
        {"898", "Amanda", 27, 5100}
    };
    int choice;
    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Pengurutan berdasarkan NIP" << endl;
    cout << "2. Pengurutan berdasarkan NAMA" << endl;
    cout << "Pilih:" << endl;
    cin >> choice;

    int sortOrder;
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "1. Naik" << endl;
    cout << "2. Turun" << endl;
    cout << "Pilih:" << endl;
    cin >> sortOrder;
    // Memilih fungsi pembanding berdasarkan pilihan pengguna
    bool (*compareFunction)(const Pegawai&, const Pegawai&);
    if (choice == 1) {
        if (sortOrder == 1) {
            compareFunction = compareByNIPAsc;
        }
        else {
            compareFunction = compareByNIPDesc;
        }
    }
    else {
        if (sortOrder == 1) {
            compareFunction = compareByNamaAsc;
        }
        else {
            compareFunction = compareByNamaDesc;
        }
    }
    // Melakukan pengurutan menggunakan fungsi pembanding yang dipilih
    sort(dataPegawai, dataPegawai + MAX, compareFunction);
    // Menampilkan data setelah diurutkan
    cout << "\nDATA PEGAWAI SETELAH DIURUTKAN" << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << "NIP: " << dataPegawai[i].NIP << ", NAMA: " << dataPegawai[i].NAMA << endl;
    }
    return 0;
}