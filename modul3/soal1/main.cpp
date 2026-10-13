#include <iomanip>
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    Mahasiswa data[10];
    int jumlah;

    cout << "Jumlah mahasiswa (maksimal 10): ";
    cin >> jumlah;
    if (jumlah < 1 || jumlah > 10) {
        cout << "Jumlah mahasiswa harus berada pada rentang 1 sampai 10." << endl;
        return 0;
    }

    for (int indeks = 0; indeks < jumlah; indeks++) {
        cout << "\nData mahasiswa ke-" << indeks + 1 << endl;
        cout << "Nama: ";
        cin >> data[indeks].nama;
        cout << "NIM: ";
        cin >> data[indeks].nim;
        cout << "Nilai UTS: ";
        cin >> data[indeks].uts;
        cout << "Nilai UAS: ";
        cin >> data[indeks].uas;
        cout << "Nilai tugas: ";
        cin >> data[indeks].tugas;
        data[indeks].nilaiAkhir = hitungNilaiAkhir(data[indeks].uts, data[indeks].uas, data[indeks].tugas);
    }

    cout << fixed << setprecision(2);
    cout << "\nDaftar nilai mahasiswa\n";
    for (int indeks = 0; indeks < jumlah; indeks++) {
        cout << indeks + 1 << ". " << data[indeks].nama
             << " (" << data[indeks].nim << ")"
             << " - Nilai akhir: " << data[indeks].nilaiAkhir << endl;
    }
    return 0;
}
