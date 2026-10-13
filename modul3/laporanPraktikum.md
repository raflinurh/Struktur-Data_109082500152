<div align="center">

# **Laporan Praktikum Modul 3 - Abstract Data Type (ADT)**

Rafli Nurhidayat - 109082500152

</div>

## Dasar Teori

Abstract Data Type (ADT) adalah tipe data yang didefinisikan bersama sekumpulan operasi atau primitif untuk mengolah tipe tersebut. ADT memisahkan spesifikasi tipe dan operasi dari implementasinya. Dengan pemisahan ini, pengguna program cukup mengetahui interface yang tersedia tanpa harus mengetahui detail kode di dalamnya [1].

### A. Komponen ADT

ADT dapat terdiri dari beberapa komponen berikut:

1. Konstruktor atau kreator untuk membentuk nilai awal suatu tipe.
2. Selector untuk mengambil nilai komponen dari suatu data.
3. Mutator untuk mengubah nilai komponen.
4. Validator untuk memeriksa apakah suatu nilai memenuhi aturan tipe.
5. Prosedur input dan output untuk berinteraksi dengan pengguna.
6. Fungsi atau prosedur lain yang dibutuhkan untuk mengolah tipe tersebut.

### B. Pemisahan Modul ADT

Implementasi ADT biasanya dipisahkan menjadi file header (`.h`), file implementasi (`.cpp`), dan program utama atau driver (`main.cpp`). File header berisi deklarasi `struct`, prototype fungsi, dan interface. File implementasi berisi realisasi fungsi. File `main.cpp` menggunakan interface tersebut untuk menjalankan program. Pemisahan ini membuat kode lebih rapi, mudah diuji, dan dapat digunakan kembali.

### C. Array dan Struktur

Array digunakan untuk menyimpan beberapa data dengan tipe yang sama. Array dapat dikombinasikan dengan `struct` untuk menyimpan data yang memiliki beberapa field, misalnya data mahasiswa yang terdiri dari nama, NIM, nilai UTS, nilai UAS, dan nilai tugas. Fungsi dapat digunakan untuk menghitung nilai akhir berdasarkan field tersebut.

### D. Pointer dalam ADT

Pointer menyimpan alamat memori suatu variabel. Operator `&` digunakan untuk mendapatkan alamat, sedangkan operator `*` digunakan untuk mengakses nilai pada alamat tersebut. Pointer dapat digunakan untuk mengubah data asli melalui fungsi serta melakukan pertukaran nilai antarvariabel.

## Guided

### 1. ADT Buku

**`buku.h`**

```cpp
#ifndef BUKU_H
#define BUKU_H
#include <iostream>

using namespace std;

struct Buku
{
    string judul;
    int halaman;
    string penulis;
};

void editIsi(string judul, int halaman, string penulis, Buku &buku);
void tampilkanIsiBuku(Buku buku);
bool checkPenulis(Buku buku);

#endif
```

**`buku.cpp`**

```cpp
#include "buku.h"

void editIsi(string judul, int halaman, string penulis, Buku &buku)
{
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilkanIsiBuku(Buku buku)
{
    cout << "Judul: " << buku.judul << endl;
    cout << "Halaman: " << buku.halaman << endl;
    cout << "Penulis: " << buku.penulis << endl;
}

bool checkPenulis(Buku buku)
{
    return buku.penulis == "";
}
```

**`main.cpp`**

```cpp
#include <iostream>
#include "buku.h"

using namespace std;

int main()
{
    Buku novel;
    string judul, penulis;
    int halaman;

    cout << "Masukkan judul buku: ";
    cin >> judul;
    cout << "Masukkan jumlah halaman: ";
    cin >> halaman;
    cout << "Masukkan nama penulis: ";
    cin >> penulis;

    editIsi(judul, halaman, penulis, novel);
    tampilkanIsiBuku(novel);

    cout << checkPenulis(novel) << endl;

    return 0;

}
```

Program menggunakan `struct Buku` sebagai type ADT. Deklarasi type dan prototype fungsi berada pada header, sedangkan realisasi fungsi berada pada file `.cpp`. Fungsi `editIsi()` berperan sebagai mutator, `tampilkanIsiBuku()` sebagai prosedur output, dan `checkPenulis()` sebagai validator sederhana.

## Unguided

### 1. Data Mahasiswa

Buat program yang menyimpan maksimal 10 data mahasiswa dalam array dengan field nama, NIM, UTS, UAS, tugas, dan nilai akhir. Nilai akhir dihitung dengan rumus `0.3 * UTS + 0.4 * UAS + 0.3 * tugas`.


**`mahasiswa.h`**

```cpp
#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double uts;
    double uas;
    double tugas;
    double nilaiAkhir;
};

double hitungNilaiAkhir(double uts, double uas, double tugas);

#endif
```

**`mahasiswa.cpp`**

```cpp
#include "mahasiswa.h"

double hitungNilaiAkhir(double uts, double uas, double tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}
```

**`main.cpp`**

```cpp
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
```

### Output Unguided 1
![Screenshot Output Unguided 1_1](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul3/output/1.png)


Program menggunakan array `data` dengan kapasitas maksimal 10 elemen. Setiap data mahasiswa menyimpan identitas dan tiga nilai. Fungsi `hitungNilaiAkhir()` menghitung nilai akhir dengan bobot UTS 30%, UAS 40%, dan tugas 30%. Pada contoh, nilai akhirnya adalah `0.3(80) + 0.4(90) + 0.3(85) = 85.50`.

### 2. ADT Pelajaran

Buat ADT `Pelajaran` yang memiliki `namaMapel` dan `kodeMapel`, kemudian buat fungsi kreator dan prosedur untuk menampilkan data.

Source code tersedia dalam folder [soal2](soal2): [pelajaran.h](soal2/pelajaran.h), [pelajaran.cpp](soal2/pelajaran.cpp), dan [main.cpp](soal2/main.cpp).

**`pelajaran.h`**

```cpp
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran createPelajaran(string namaMapel, string kodeMapel);
void tampilkanPelajaran(Pelajaran pelajaran);

#endif
```

**`pelajaran.cpp`**

```cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran createPelajaran(string namaMapel, string kodeMapel) {
    Pelajaran pelajaran;
    pelajaran.namaMapel = namaMapel;
    pelajaran.kodeMapel = kodeMapel;
    return pelajaran;
}

void tampilkanPelajaran(Pelajaran pelajaran) {
    cout << "Nama pelajaran: " << pelajaran.namaMapel << endl;
    cout << "Kode pelajaran: " << pelajaran.kodeMapel << endl;
}
```

**`main.cpp`**

```cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodeMapel = "STD";
    Pelajaran pelajaran = createPelajaran(namaMapel, kodeMapel);
    tampilkanPelajaran(pelajaran);
    return 0;
}
```

### Output Unguided 2
![Screenshot Output Unguided 1_2](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul3/output/2.png)


`Pelajaran` menjadi type ADT yang dideklarasikan pada file header. Fungsi `createPelajaran()` bertugas membuat dan mengisi objek pelajaran, sedangkan `tampilkanPelajaran()` menampilkan isi objek. `main.cpp` hanya menggunakan interface ADT tanpa mengatur detail pengisian field secara langsung.

### 3. Array 2D dan Pointer

Buat program dengan dua array integer 2D berukuran 3x3 dan dua pointer integer. Program harus dapat menampilkan array, menukar isi array pada posisi tertentu, dan menukar isi dua variabel yang ditunjuk pointer.

Source code tersedia dalam folder [soal3](soal3) pada file [array.h](soal3/array.h), [array.cpp](soal3/array.cpp), dan [main.cpp](soal3/main.cpp).

**`array.h`**

```cpp
#ifndef ARRAY_H
#define ARRAY_H

const int UKURAN = 3;

void tampilkanArray(const int matriks[UKURAN][UKURAN], const char *nama);
void tukarElemenArray(int pertama[UKURAN][UKURAN], int kedua[UKURAN][UKURAN], int baris, int kolom);
void tukarPointer(int *pertama, int *kedua);

#endif
```

**`array.cpp`**

```cpp
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
```

**`main.cpp`**

```cpp
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
```

### Output Unguided 3
![Screenshot Output Unguided 1_3](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul3/output/3.png)


Program menampilkan dua array 2D menggunakan dua perulangan bersarang. Fungsi `tukarElemenArray()` menukar elemen pada baris dan kolom yang dipilih. Pada contoh, elemen posisi baris 2 kolom 2 pada array pertama dan kedua, yaitu `5` dan `14`, berhasil ditukar. Selain itu, dua pointer menunjuk ke `nilaiPertama` dan `nilaiKedua`, kemudian fungsi `tukarPointer()` menukar isi variabel menggunakan operator dereference.

## Kesimpulan

Praktikum Modul 3 memperkenalkan konsep Abstract Data Type sebagai pemisahan antara type, interface, dan implementasi operasi. ADT dapat dibangun menggunakan `struct`, fungsi, prosedur, file header, file implementasi, dan program utama. Penerapan ADT terlihat pada pengelolaan data buku, data mahasiswa, data pelajaran, array 2D, serta pertukaran nilai menggunakan pointer. Pemisahan modul membuat program lebih terstruktur, mudah dipahami, dan dapat dikembangkan kembali.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4.
