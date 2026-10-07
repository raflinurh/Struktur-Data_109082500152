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
