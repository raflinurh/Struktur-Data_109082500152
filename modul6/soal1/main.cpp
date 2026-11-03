#include <iostream>

#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    createList(L);

    insertLast(L, alokasi({"D001", "Merah", 2020}));
    insertLast(L, alokasi({"D002", "Hitam", 2021}));
    insertLast(L, alokasi({"D003", "Putih", 2019}));
    insertLast(L, alokasi({"D004", "Biru", 2022}));

    cout << "--- Data kendaraan ---" << endl;
    printInfo(L);

    address Found = findElm(L, "D001");
    if (Found != Nil) {
        cout << "Kendaraan dengan nomor polisi D001 ditemukan." << endl;
    }

    deleteByNopol(L, "D003");
    cout << endl << "--- Setelah menghapus D003 ---" << endl;
    printInfo(L);

    deleteAll(L);
    return 0;
}
