#include <iostream>
using namespace std;

const int UKURAN = 3;

void inputMatriks(int matriks[UKURAN][UKURAN], const char *nama) {
    cout << "Masukkan elemen matriks " << nama << ":\n";
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            cout << nama << "[" << baris + 1 << "][" << kolom + 1 << "] = ";
            cin >> matriks[baris][kolom];
        }
    }
}

void tampilkanMatriks(const int matriks[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            cout << matriks[baris][kolom] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(const int pertama[UKURAN][UKURAN], const int kedua[UKURAN][UKURAN], int hasil[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            hasil[baris][kolom] = pertama[baris][kolom] + kedua[baris][kolom];
        }
    }
}

void kurangMatriks(const int pertama[UKURAN][UKURAN], const int kedua[UKURAN][UKURAN], int hasil[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            hasil[baris][kolom] = pertama[baris][kolom] - kedua[baris][kolom];
        }
    }
}

void kaliMatriks(const int pertama[UKURAN][UKURAN], const int kedua[UKURAN][UKURAN], int hasil[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            hasil[baris][kolom] = 0;
            for (int indeks = 0; indeks < UKURAN; indeks++) {
                hasil[baris][kolom] += pertama[baris][indeks] * kedua[indeks][kolom];
            }
        }
    }
}

int main() {
    int pertama[UKURAN][UKURAN], kedua[UKURAN][UKURAN], hasil[UKURAN][UKURAN];

    inputMatriks(pertama, "A");
    inputMatriks(kedua, "B");

    cout << "\nHasil penjumlahan matriks:\n";
    jumlahMatriks(pertama, kedua, hasil);
    tampilkanMatriks(hasil);

    cout << "\nHasil pengurangan matriks:\n";
    kurangMatriks(pertama, kedua, hasil);
    tampilkanMatriks(hasil);

    cout << "\nHasil perkalian matriks:\n";
    kaliMatriks(pertama, kedua, hasil);
    tampilkanMatriks(hasil);
    return 0;
}
