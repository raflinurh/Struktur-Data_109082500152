#ifndef ARRAY_H
#define ARRAY_H

const int UKURAN = 3;

void tampilkanArray(const int matriks[UKURAN][UKURAN], const char *nama);
void tukarElemenArray(int pertama[UKURAN][UKURAN], int kedua[UKURAN][UKURAN], int baris, int kolom);
void tukarPointer(int *pertama, int *kedua);

#endif
