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