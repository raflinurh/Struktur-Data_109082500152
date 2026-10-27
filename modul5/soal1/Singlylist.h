#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <string>

using namespace std;

#define Nil nullptr

typedef int infotype;

struct ElmList;
typedef ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

bool isEmpty(List L);
void createList(List &L);
address alokasi(infotype info);
void dealokasi(address &P);
address findElm(List L, infotype X);
address findBefore(List L, address P);
void insertFirst(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void insertLast(List &L, address P);
void delFirst(List &L, address &P);
void delLast(List &L, address &P);
void delAfter(List &L, address &P, address Prec);
void delP(List &L, infotype X);
void printInfo(List L);
int nbList(List L);
void delAll(List &L);
void invertList(List &L);
bool isEqual(List L1, List L2);
List fCopyList(List L);

#endif
