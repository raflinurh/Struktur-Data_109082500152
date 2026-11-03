#include "Doublylist.h"

#include <iostream>

using namespace std;

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << "Nomor polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun dibuat : " << P->info.thnBuat << endl;
        cout << "-------------------------------" << endl;
        P = P->next;
    }
}

void insertLast(List &L, address P) {
    if (P == Nil) {
        return;
    }

    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil && P->info.nopol != nopol) {
        P = P->next;
    }
    return P;
}

void deleteFirst(List &L, address &P) {
    P = Nil;
    if (L.first == Nil) {
        return;
    }

    P = L.first;
    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = Nil;
    if (L.last == Nil) {
        return;
    }

    P = L.last;
    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = P->prev;
        L.last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Nil;
    if (Prec == Nil || Prec->next == Nil) {
        return;
    }

    P = Prec->next;
    if (P == L.last) {
        deleteLast(L, P);
        return;
    }

    Prec->next = P->next;
    P->next->prev = Prec;
    P->next = Nil;
    P->prev = Nil;
}

void deleteByNopol(List &L, string nopol) {
    address Target = findElm(L, nopol);
    if (Target == Nil) {
        return;
    }

    address Deleted = Nil;
    if (Target == L.first) {
        deleteFirst(L, Deleted);
    } else if (Target == L.last) {
        deleteLast(L, Deleted);
    } else {
        deleteAfter(L, Target->prev, Deleted);
    }
    dealokasi(Deleted);
}

void deleteAll(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
