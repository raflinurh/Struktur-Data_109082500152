#include <iostream>
#include "array.h"
using namespace std;

void tampilkanArray(const int matriks[UKURAN][UKURAN], const char *nama) {
    cout << nama << ":\n";
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            cout << matriks[baris][kolom] << "\t";
        }
        cout << endl;
    }
}

void tukarElemenArray(int pertama[UKURAN][UKURAN], int kedua[UKURAN][UKURAN], int baris, int kolom) {
    int sementara = pertama[baris][kolom];
    pertama[baris][kolom] = kedua[baris][kolom];
    kedua[baris][kolom] = sementara;
}

void tukarPointer(int *pertama, int *kedua) {
    int sementara = *pertama;
    *pertama = *kedua;
    *kedua = sementara;
}
