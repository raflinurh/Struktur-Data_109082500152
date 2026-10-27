#include <iostream>

#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    createList(L);

    address P1 = alokasi(2);
    address P2 = alokasi(0);
    address P3 = alokasi(8);
    address P4 = alokasi(12);
    address P5 = alokasi(9);

    insertFirst(L, P1);
    insertFirst(L, P2);
    insertFirst(L, P3);
    insertFirst(L, P4);
    insertFirst(L, P5);

    cout << "Isi list: ";
    printInfo(L);

    address Found = findElm(L, 8);
    if (Found != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    cout << "Total dari kelima elemen adalah ";
    int total = 0;
    address Current = L.first;
    while (Current != Nil) {
        total += Current->info;
        Current = Current->next;
    }
    cout << total << endl;

    delAll(L);
    return 0;
}
