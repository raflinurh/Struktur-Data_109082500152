#include <iomanip>
#include <iostream>
using namespace std;

const int JUMLAH_DATA = 10;

int nilaiMaksimum(const int data[], int jumlah) {
    int maksimum = data[0];
    for (int indeks = 1; indeks < jumlah; indeks++) {
        if (data[indeks] > maksimum) {
            maksimum = data[indeks];
        }
    }
    return maksimum;
}

int nilaiMinimum(const int data[], int jumlah) {
    int minimum = data[0];
    for (int indeks = 1; indeks < jumlah; indeks++) {
        if (data[indeks] < minimum) {
            minimum = data[indeks];
        }
    }
    return minimum;
}

void hitungRataRata(const int data[], int jumlah, double &rataRata) {
    int total = 0;
    for (int indeks = 0; indeks < jumlah; indeks++) {
        total += data[indeks];
    }
    rataRata = static_cast<double>(total) / jumlah;
}

void tampilkanArray(const int data[], int jumlah) {
    for (int indeks = 0; indeks < jumlah; indeks++) {
        cout << data[indeks] << (indeks == jumlah - 1 ? '\n' : ' ');
    }
}

int main() {
    const int data[JUMLAH_DATA] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int pilihan;
    double rataRata = 0;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tampilkanArray(data, JUMLAH_DATA);
            break;
        case 2:
            cout << "Nilai maksimum = " << nilaiMaksimum(data, JUMLAH_DATA) << endl;
            break;
        case 3:
            cout << "Nilai minimum = " << nilaiMinimum(data, JUMLAH_DATA) << endl;
            break;
        case 4:
            hitungRataRata(data, JUMLAH_DATA, rataRata);
            cout << fixed << setprecision(2);
            cout << "Nilai rata-rata = " << rataRata << endl;
            break;
        case 0:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
