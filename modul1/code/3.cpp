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