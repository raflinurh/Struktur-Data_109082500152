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
