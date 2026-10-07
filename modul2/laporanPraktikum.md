<div align="center">

# **Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)**

Rafli Nurhidayat - 109082500152

</div>

## Dasar Teori

C++ menyediakan berbagai struktur untuk menyimpan data dan mengatur proses program. Pada Modul 2 dibahas array, pointer, fungsi, prosedur, serta cara melewatkan parameter ke dalam fungsi. Konsep-konsep tersebut membantu program menjadi lebih terstruktur, mudah digunakan kembali, dan mampu memproses data secara lebih efisien [1].

### A. Array

Array adalah kumpulan elemen yang memiliki nama sama dan tipe data yang sama. Setiap elemen array diakses menggunakan indeks. Indeks array dalam C++ dimulai dari `0`, sehingga array dengan 5 elemen memiliki indeks `0` sampai `4`.

Array satu dimensi digunakan untuk menyimpan data dalam bentuk deret, misalnya `int nilai[10]`. Array dua dimensi menggunakan dua indeks dan dapat digunakan untuk merepresentasikan tabel atau matriks, misalnya `int matriks[3][3]`. Array juga dapat memiliki lebih dari dua dimensi.

### B. Pointer dan Alamat Memori

Setiap variabel disimpan pada lokasi tertentu di memori dan memiliki alamat. Operator `&` digunakan untuk mendapatkan alamat variabel, sedangkan operator `*` digunakan untuk mengakses nilai yang ditunjuk oleh pointer. Pointer dideklarasikan dengan menuliskan tanda `*` pada tipe datanya, contohnya `int *penunjuk`.

Pointer menyimpan alamat variabel lain. Jika `penunjuk = &nilai`, maka `penunjuk` berisi alamat dari `nilai` dan `*penunjuk` berisi nilai yang terdapat pada alamat tersebut. Pointer juga berhubungan erat dengan array karena nama array dapat digunakan sebagai alamat elemen pertamanya.

### C. Fungsi dan Prosedur

Fungsi adalah blok kode yang dibuat untuk menjalankan tugas tertentu. Fungsi dapat menerima parameter dan mengembalikan nilai menggunakan `return`. Contohnya adalah fungsi bertipe `int` yang mengembalikan hasil perhitungan bilangan bulat.

Prosedur dalam C++ biasanya dibuat menggunakan fungsi bertipe `void`. Prosedur menjalankan tugas tertentu tetapi tidak mengembalikan nilai secara langsung. Penggunaan fungsi dan prosedur membuat program lebih terstruktur serta mengurangi pengulangan kode.

### D. Parameter Fungsi

Parameter formal adalah variabel yang ditulis pada deklarasi fungsi, sedangkan parameter aktual adalah nilai atau variabel yang dikirim ketika fungsi dipanggil. Parameter dapat dikirim dengan beberapa cara:

1. **Pass by value**, yaitu nilai parameter disalin sehingga perubahan pada parameter formal tidak mengubah variabel asal.
2. **Pass by pointer**, yaitu alamat variabel dikirim menggunakan operator `&` dan nilai diubah melalui dereference `*`.
3. **Pass by reference**, yaitu parameter formal menjadi referensi langsung terhadap variabel asal menggunakan tanda `&` pada deklarasi parameter [2].

## Guided

### 1. Array Satu Dimensi dan Dua Dimensi

```cpp
#include <iostream>
#define MAX 5
using namespace std;

int main() {
	int i, j;
	float nilai[MAX];
	static int nilai_tahun[MAX][MAX] = {
		{0, 2, 2, 0, 0},
		{0, 1, 1, 1, 0},
		{0, 3, 3, 3, 0},
		{4, 4, 0, 0, 4},
		{5, 0, 0, 0, 5}
	};

	for (i = 0; i < MAX; i++) {
		cout << "masukkan nilai ke-" << i + 1 << endl;
		cin >> nilai[i];
	}
	cout << "\ndata nilai siswa :\n";
	for (i = 0; i < MAX; i++) {
		cout << "nilai ke-" << i + 1 << " = " << nilai[i] << endl;
	}
	cout << "\nnilai tahunan :\n";
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) cout << nilai_tahun[i][j];
		cout << "\n";
	}
	return 0;
}
```

Program menerima lima nilai ke dalam array satu dimensi `nilai`. Program juga menampilkan array dua dimensi `nilai_tahun` menggunakan dua perulangan bersarang. Indeks `i` digunakan untuk baris dan `j` digunakan untuk kolom.

### 2. Pointer dan Alamat Memori

```cpp
#include <iostream>
using namespace std;

int main() {
	int x, y;
	int *px;
	x = 87;
	px = &x;
	y = *px;
	cout << "Alamat x = " << &x << endl;
	cout << "Isi px = " << px << endl;
	cout << "Isi x = " << x << endl;
	cout << "Nilai yang ditunjuk px = " << *px << endl;
	cout << "Nilai y = " << y << endl;
	return 0;
}
```

Pointer `px` menyimpan alamat dari variabel `x` melalui pernyataan `px = &x`. Operator `*px` digunakan untuk mengambil nilai yang berada pada alamat tersebut. Oleh karena itu, nilai `*px` dan `y` sama dengan nilai `x`, yaitu `87`, sedangkan alamat yang dicetak dapat berbeda pada setiap komputer.

### 3. Fungsi Mencari Nilai Maksimum

```cpp
#include <iostream>
using namespace std;

int maks3(int a, int b, int c);

int main() {
	int x, y, z;
	cout << "masukkan nilai bilangan ke-1 = ";
	cin >> x;
	cout << "masukkan nilai bilangan ke-2 = ";
	cin >> y;
	cout << "masukkan nilai bilangan ke-3 = ";
	cin >> z;
	cout << "nilai maksimumnya adalah = " << maks3(x, y, z);
	return 0;
}

int maks3(int a, int b, int c) {
	int maksimum = a;
	if (b > maksimum) maksimum = b;
	if (c > maksimum) maksimum = c;
	return maksimum;
}
```

Fungsi `maks3()` menerima tiga parameter bertipe integer. Nilai pertama dijadikan nilai maksimum sementara, kemudian dibandingkan dengan nilai kedua dan ketiga. Nilai terbesar dikembalikan ke fungsi `main()` menggunakan `return`.

### 4. Prosedur Menampilkan Baris

```cpp
#include <iostream>
using namespace std;

void tulis(int jumlah);

int main() {
	int jumlah;
	cout << "jumlah baris kata = ";
	cin >> jumlah;
	tulis(jumlah);
	return 0;
}

void tulis(int jumlah) {
	for (int i = 0; i < jumlah; i++) {
		cout << "baris ke-" << i + 1 << endl;
	}
}
```

`tulis()` merupakan prosedur karena bertipe `void` dan tidak mengembalikan nilai. Prosedur menerima jumlah baris sebagai parameter, kemudian menggunakan perulangan `for` untuk menampilkan baris sesuai input.

### 5. Pertukaran dengan Pointer dan Reference

```cpp
#include <iostream>
using namespace std;

void tukarValue(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void tukarPointer(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void tukarReference(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int main() {
	int a = 5, b = 10;
	cout << "Sebelum tukarValue: a = " << a << ", b = " << b << endl;
	tukarValue(a, b);
	cout << "Setelah tukarValue: a = " << a << ", b = " << b << endl;
	cout << "Sebelum tukarPointer: a = " << a << ", b = " << b << endl;
	tukarPointer(&a, &b);
	cout << "Setelah tukarPointer: a = " << a << ", b = " << b << endl;
	cout << "Sebelum tukarReference: a = " << a << ", b = " << b << endl;
	tukarReference(a, b);
	cout << "Setelah tukarReference: a = " << a << ", b = " << b << endl;
	return 0;
}
```

Program memperlihatkan dua cara pertukaran nilai. Fungsi `tukarValue()` pada source ini sebenarnya menggunakan parameter reference karena deklarasinya memakai `int &`, meskipun nama fungsinya mengandung kata `Value`. Fungsi `tukarPointer()` menerima alamat variabel dengan `&` dan mengakses nilai melalui operator dereference `*`. Fungsi `tukarReference()` menerima alias langsung dari variabel sehingga pemanggilannya tidak memerlukan operator tambahan. Ketiga fungsi tersebut dapat mengubah nilai variabel asli karena menggunakan reference atau pointer.

## Unguided

### 1. Operasi Matriks 3x3

Buat program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks berukuran 3x3.

```cpp
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
```

### Output Unguided 1
![Screenshot Output Unguided 1_1](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul2/output/1.png)

Program menerima dua matriks berukuran 3x3, kemudian langsung menampilkan hasil penjumlahan, pengurangan, dan perkalian tanpa menu pilihan. Pada penjumlahan dan pengurangan, setiap elemen matriks pertama dipasangkan dengan elemen matriks kedua yang memiliki posisi baris dan kolom sama. Pada perkalian, tiga perulangan digunakan untuk mengalikan setiap baris matriks pertama dengan setiap kolom matriks kedua. Fungsi `tampilkanMatriks()` kemudian mencetak hasil setiap operasi dalam bentuk tabel.


### 2. Pertukaran Tiga Variabel dengan Pointer dan Reference

Berdasarkan guided pointer dan reference, buat program yang dapat menukar nilai dari tiga variabel.

```cpp
#include <iostream>
using namespace std;

void tukarDenganPointer(int *pertama, int *kedua, int *ketiga) {
    int sementara = *pertama;
    *pertama = *kedua;
    *kedua = *ketiga;
    *ketiga = sementara;
}

void tukarDenganReference(int &pertama, int &kedua, int &ketiga) {
    int sementara = pertama;
    pertama = kedua;
    kedua = ketiga;
    ketiga = sementara;
}

void tampilkanNilai(const char *judul, int pertama, int kedua, int ketiga) {
    cout << judul << " a = " << pertama
         << ", b = " << kedua << ", c = " << ketiga << endl;
}

int main() {
    int a = 5, b = 10, c = 15;
    tampilkanNilai("Nilai awal:", a, b, c);

    tukarDenganPointer(&a, &b, &c);
    tampilkanNilai("Setelah pertukaran dengan pointer:", a, b, c);

    tukarDenganReference(a, b, c);
    tampilkanNilai("Setelah pertukaran dengan reference:", a, b, c);
    return 0;
}
```

### Output Unguided 2
![Screenshot Output Unguided 1_1](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul2/output/2.png)

Pada pertukaran pertama, alamat tiga variabel dikirim ke fungsi pointer sehingga perubahan dilakukan melalui operator dereference. Pada pertukaran kedua, reference digunakan sebagai alias langsung. Nilai dipindahkan secara berputar: nilai `a` masuk ke `c`, nilai `b` masuk ke `a`, dan nilai `c` masuk ke `b`.

### 3. Menu Program Array

Diketahui array `arrA = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1}`. Buat function untuk mencari nilai maksimum dan minimum, procedure untuk menghitung rata-rata dengan pass by reference atau pointer, serta menu sederhana.

```cpp
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
```

### Output Unguided 3
![Screenshot Output Unguided 1_1](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul2/output/3.png)

Array berisi sepuluh nilai dan dapat ditampilkan melalui menu pertama. Function `nilaiMaksimum()` dan `nilaiMinimum()` mengembalikan hasil pencarian nilai terbesar dan terkecil. Procedure `hitungRataRata()` menghitung jumlah seluruh data, membaginya dengan jumlah elemen, lalu mengirimkan hasilnya ke `main()` melalui parameter reference `rataRata`. Jumlah seluruh data adalah `200`, sehingga rata-ratanya adalah `200 / 10 = 20.00`.

## Kesimpulan

Praktikum Modul 2 memperdalam pemahaman tentang array, pointer, alamat memori, fungsi, prosedur, dan parameter. Array dapat digunakan untuk menyimpan data satu dimensi maupun matriks dua dimensi. Pointer memungkinkan program mengakses alamat dan nilai suatu variabel, sedangkan reference dapat digunakan untuk mengubah data asli melalui fungsi. Fungsi dan prosedur juga membuat program lebih terstruktur. Penerapan konsep tersebut terlihat pada operasi matriks, pertukaran tiga variabel, serta pencarian nilai minimum, maksimum, dan rata-rata menggunakan menu.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4.
