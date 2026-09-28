# **Laporan Praktikum Modul 1 \- Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)**

Rafli Nurhidayat - 109082500152

## Dasar Teori

C++ adalah bahasa pemrograman yang dikembangkan oleh Bjarne Stroustrup di AT&T Bell Laboratories pada awal tahun 1980-an. C++ dikembangkan dari bahasa C dengan menambahkan fitur seperti class, fungsi, operator, tipe data, dan pemrograman berorientasi objek [1].

### A. Bahasa Pemrograman C++

C++ merupakan bahasa pemrograman yang dikembangkan dari bahasa C oleh Bjarne Stroustrup. C++ mendukung pemrograman prosedural dan berorientasi objek. Setiap program C++ memiliki fungsi `main()` sebagai fungsi utama. Library `<iostream>` digunakan untuk operasi input dan output menggunakan `cin` dan `cout` [1].

### B. Konsep Dasar C++

1. Program C++ memiliki fungsi utama `main()`. Header seperti `<iostream>` digunakan untuk operasi input dan output.
2. Variabel menyimpan nilai yang dapat berubah, sedangkan konstanta menyimpan nilai tetap. Contoh tipe data dasar adalah `int`, `float`, `double`, dan `char`.
3. `cin` digunakan untuk membaca input, sedangkan `cout` digunakan untuk menampilkan output. Operator aritmatika meliputi `+`, `-`, `*`, `/`, dan `%` [2].
4. Percabangan `if`, `if-else`, dan `switch` digunakan untuk mengambil keputusan berdasarkan kondisi.
5. Perulangan `for`, `while`, dan `do-while` digunakan untuk menjalankan statement berulang kali. Perulangan harus mempunyai kondisi berhenti.
6. `struct` digunakan untuk mengelompokkan beberapa data yang dapat memiliki tipe berbeda. Elemen struct diakses menggunakan operator titik (`.`).

## Guided

### 1. Operator Aritmatika dan Casting

```cpp
#include <iostream>
using namespace std;

int main() {
	int W, X, Y; float Z;
    X = 7; Y = 3; W = 1;
    Z = (X + Y)/(Y + W);
    cout<< "Nilai z = " << Z << endl;
    return 0;
}
```

Program menggunakan operator penjumlahan dan pembagian. `static_cast<float>` membuat hasil pembagian menjadi bilangan pecahan, sehingga outputnya adalah `2.5`.

### 2. Percabangan `if-else`

```cpp
#include <iostream>
using namespace std;

int main(){
    double tot_pembelian, diskon;
    cout<<"total pembelian: Rp";
    cin>>tot_pembelian;
    diskon = 0;
    if(tot_pembelian >= 100000)
    diskon = 0.05*tot_pembelian;
    cout<<"besar diskon = Rp" <<diskon;
}
```

Jika total pembelian minimal Rp100.000, program memberikan diskon sebesar 5%. Jika kurang dari jumlah tersebut, diskon bernilai nol.

### 3. Perulangan dan Struktur Data

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Siswa {
	string nama;
	int nilai;
};

int main() {
	Siswa siswa[2];
	for (int i = 0; i < 2; i++) {
		cout << "Nama siswa ke-" << i + 1 << ": ";
		cin >> siswa[i].nama;
		cout << "Nilai siswa ke-" << i + 1 << ": ";
		cin >> siswa[i].nilai;
	}

	cout << "\nData siswa\n";
	for (int i = 0; i < 2; i++) {
		cout << siswa[i].nama << " - " << siswa[i].nilai << endl;
	}
	return 0;
}
```

Program menggunakan array berisi `struct Siswa`. Perulangan `for` digunakan untuk menerima dan menampilkan data setiap siswa.

## Unguided

### 1. Operasi Dua Bilangan Float

Buat program yang menerima dua bilangan bertipe `float`, kemudian menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian.

```cpp
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	float bilanganPertama, bilanganKedua;
	cout << "Bilangan pertama: ";
	cin >> bilanganPertama;
	cout << "Bilangan kedua: ";
	cin >> bilanganKedua;

	cout << fixed << setprecision(2);
	cout << "Penjumlahan = " << bilanganPertama + bilanganKedua << endl;
	cout << "Pengurangan = " << bilanganPertama - bilanganKedua << endl;
	cout << "Perkalian = " << bilanganPertama * bilanganKedua << endl;
	if (bilanganKedua != 0) {
		cout << "Pembagian = " << bilanganPertama / bilanganKedua << endl;
	} else {
		cout << "Pembagian tidak dapat dilakukan dengan nol." << endl;
	}
	return 0;
}
```

### Output Unguided 1
![Screenshot Output Unguided 1_1](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul1/output/1.png)

Program melakukan validasi pembagian dengan nol agar tidak terjadi kesalahan saat runtime.

### 2. Mengubah Angka Menjadi Tulisan

Buat program yang menerima bilangan bulat positif dari 0 sampai 100 dan menampilkan angka tersebut dalam bentuk tulisan.

```cpp
#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

string angkaKeTulisan(int angka) {
	if (angka < 10) return satuan[angka];
	if (angka == 10) return "sepuluh";
	if (angka == 11) return "sebelas";
	if (angka < 20) return satuan[angka - 10] + " belas";
	if (angka < 100) {
		int puluhan = angka / 10;
		int sisa = angka % 10;
		return satuan[puluhan] + " puluh" + (sisa == 0 ? "" : " " + satuan[sisa]);
	}
	return "seratus";
}

int main() {
	int angka;
	cout << "Masukkan angka (0-100): ";
	cin >> angka;

	if (angka < 0 || angka > 100) {
		cout << "Angka harus berada pada rentang 0 sampai 100." << endl;
	} else {
		cout << angka << " = " << angkaKeTulisan(angka) << endl;
	}
	return 0;
}
```

### Output Unguided 2
![Screenshot Output Unguided 1_2](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul1/output/2.png)


Program menggunakan array kata dasar dan percabangan untuk menangani satuan, belasan, puluhan, serta angka 100.

### 3. Program Pola Mirror

Buat program yang menerima input bilangan bulat, kemudian menampilkan pola angka mirror. Untuk input `3`, pola yang dihasilkan adalah angka yang menurun menuju `1`, lalu kembali naik pada setiap baris.

```cpp
#include <iostream>
using namespace std;

int main() {
	int input;
	cout << "input: ";
	cin >> input;
	cout << endl;

	cout << "output:" << endl;
	for (int baris = input; baris >= 1; baris--) {
		for (int spasi = input; spasi > baris; spasi--) {
			cout << "  ";
		}
		for (int angka = baris; angka >= 1; angka--) {
			cout << angka << " ";
		}
		cout << "* ";
		for (int angka = 1; angka <= baris; angka++) {
			cout << angka << " ";
		}
		cout << endl;
	}
	for (int spasi = 0; spasi < input; spasi++) {
		cout << "  ";
	}
	cout << "*" << endl;
	return 0;
}
```

### Output Unguided 3
![Screenshot Output Unguided 1_3](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul1/output/3.png)


Perulangan luar menentukan jumlah baris. Pada setiap baris, angka dicetak menurun menuju `1`, kemudian tanda `*` sebagai sumbu mirror, lalu angka dicetak menaik. Setelah semua baris selesai, program mencetak satu tanda `*` di bagian bawah.

## Kesimpulan

Praktikum ini meningkatkan pemahaman mengenai dasar-dasar bahasa C++. Materi yang dipelajari meliputi tipe data, variabel, input-output, operator aritmatika, percabangan, perulangan, fungsi, array, dan struktur. Konsep-konsep tersebut dapat digunakan untuk membuat program yang menerima input, mengolah data, dan menghasilkan output sesuai kebutuhan. Melalui latihan operasi bilangan, konversi angka menjadi tulisan, dan pola mirror, setiap konsep dapat diterapkan dalam program C++ sederhana.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4.