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
