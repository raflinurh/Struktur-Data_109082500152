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
