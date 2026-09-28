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