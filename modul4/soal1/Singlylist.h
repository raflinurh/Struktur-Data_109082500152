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
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
