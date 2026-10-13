#include <iostream>
#include "array.h"
using namespace std;

int main() {
    int pertama[UKURAN][UKURAN] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int kedua[UKURAN][UKURAN] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int baris, kolom;
    int nilaiPertama = 100;
    int nilaiKedua = 200;
    int *pointerPertama = &nilaiPertama;
    int *pointerKedua = &nilaiKedua;

    cout << "Sebelum pertukaran:\n";
    tampilkanArray(pertama, "Array pertama");
    tampilkanArray(kedua, "Array kedua");

    cout << "\nMasukkan posisi yang akan ditukar (baris kolom, 1-3): ";
    cin >> baris >> kolom;
    if (baris < 1 || baris > 3 || kolom < 1 || kolom > 3) {
        cout << "Posisi tidak valid." << endl;
        return 0;
    }
    tukarElemenArray(pertama, kedua, baris - 1, kolom - 1);
    tukarPointer(pointerPertama, pointerKedua);

    cout << "\nSetelah pertukaran:\n";
    tampilkanArray(pertama, "Array pertama");
    tampilkanArray(kedua, "Array kedua");
    cout << "Nilai pertama setelah pertukaran pointer: " << nilaiPertama << endl;
    cout << "Nilai kedua setelah pertukaran pointer: " << nilaiKedua << endl;
    return 0;
}
