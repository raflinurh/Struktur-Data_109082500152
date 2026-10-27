#include "Singlylist.h"

#include <iostream>

using namespace std;

bool isEmpty(List L) {
    return L.first == Nil;
}

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype info) {
    address P = new ElmList;
    P->info = info;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

address findElm(List L, infotype X) {
    address P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}

address findBefore(List L, address P) {
    if (P == Nil || L.first == Nil || L.first == P) {
        return Nil;
    }

    address Prec = L.first;
    while (Prec->next != Nil && Prec->next != P) {
        Prec = Prec->next;
    }

    return Prec->next == P ? Prec : Nil;
}

void insertFirst(List &L, address P) {
    if (P != Nil) {
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter(List &, address P, address Prec) {
    if (P != Nil && Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (P == Nil) {
        return;
    }

    if (isEmpty(L)) {
        L.first = P;
        return;
    }

    address Last = L.first;
    while (Last->next != Nil) {
        Last = Last->next;
    }
    Last->next = P;
}

void delFirst(List &L, address &P) {
    P = Nil;
    if (!isEmpty(L)) {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
    }
}

void delLast(List &L, address &P) {
    P = Nil;
    if (isEmpty(L)) {
        return;
    }

    if (L.first->next == Nil) {
        P = L.first;
        L.first = Nil;
        return;
    }

    address Prec = L.first;
    while (Prec->next->next != Nil) {
        Prec = Prec->next;
    }

    P = Prec->next;
    Prec->next = Nil;
}

void delAfter(List &L, address &P, address Prec) {
    P = Nil;
    if (!isEmpty(L) && Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

void delP(List &L, infotype X) {
    address P = findElm(L, X);
    if (P == Nil) {
        return;
    }

    address Prec = findBefore(L, P);
    if (Prec == Nil) {
        delFirst(L, P);
    } else {
        delAfter(L, P, Prec);
    }
    dealokasi(P);
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        ++count;
        P = P->next;
    }
    return count;
}

void delAll(List &L) {
    address P;
    while (!isEmpty(L)) {
        delFirst(L, P);
        dealokasi(P);
    }
}

void invertList(List &L) {
    address Previous = Nil;
    address Current = L.first;

    while (Current != Nil) {
        address Next = Current->next;
        Current->next = Previous;
        Previous = Current;
        Current = Next;
    }

    L.first = Previous;
}

bool isEqual(List L1, List L2) {
    address P1 = L1.first;
    address P2 = L2.first;

    while (P1 != Nil && P2 != Nil) {
        if (P1->info != P2->info) {
            return false;
        }
        P1 = P1->next;
        P2 = P2->next;
    }

    return P1 == Nil && P2 == Nil;
}

List fCopyList(List L) {
    List Copy;
    createList(Copy);

    address P = L.first;
    while (P != Nil) {
        address NewNode = alokasi(P->info);
        insertLast(Copy, NewNode);
        P = P->next;
    }

    return Copy;
}
