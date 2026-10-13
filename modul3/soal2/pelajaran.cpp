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
