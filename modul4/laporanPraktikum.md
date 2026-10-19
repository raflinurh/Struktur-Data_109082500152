<div align="center">

# **Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)**

Rafli Nurhidayat - 109082500152

</div>

## Dasar Teori

Linked list adalah struktur data yang terdiri dari beberapa node yang saling terhubung menggunakan pointer. Setiap node menyimpan data dan alamat node berikutnya. Berbeda dengan array yang memiliki ukuran tetap dan elemen berurutan di memori, linked list bersifat dinamis sehingga dapat bertambah atau berkurang sesuai kebutuhan [1].

### A. Singly Linked List

Singly linked list adalah linked list yang setiap nodenya hanya memiliki satu pointer `next`. Pointer tersebut menunjuk ke node berikutnya. Node terakhir menunjuk ke `NULL` atau `nullptr`. Pointer `first` digunakan untuk menyimpan alamat node pertama dalam list.

Komponen utama singly linked list adalah:

1. **Info**, yaitu data yang disimpan pada node.
2. **Next**, yaitu pointer yang menunjuk ke node berikutnya.
3. **First**, yaitu pointer yang menunjuk node pertama.
4. **Nil**, yaitu penanda bahwa pointer tidak menunjuk node mana pun.

### B. Operasi Dasar Linked List

Operasi dasar pada singly linked list meliputi pembuatan list kosong, alokasi node, dealokasi node, penyisipan node, penghapusan node, penelusuran list, pencarian, dan pengubahan data. Penyisipan dapat dilakukan pada awal list (`insertFirst`), setelah node tertentu (`insertAfter`), atau pada akhir list (`insertLast`).

Penghapusan juga dapat dilakukan pada awal list (`deleteFirst`), setelah node tertentu (`deleteAfter`), atau pada akhir list (`deleteLast`). Penelusuran list dilakukan dengan memulai pointer dari `first`, kemudian berpindah menggunakan `next` sampai pointer bernilai `Nil`.

### C. Alokasi dan Dealokasi Memori

Node baru dibuat secara dinamis menggunakan operator `new`. Setelah node tidak digunakan, memori harus dikembalikan menggunakan `delete`. Proses pembuatan node disebut alokasi, sedangkan proses membebaskan memori disebut dealokasi. Dealokasi penting untuk mencegah kebocoran memori.

## Guided

### 1. Implementasi Linked List Mahasiswa

**`list.h`**

```cpp
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct Node *address;

struct student {
    int age;
    string name, id;
};

struct Node {
    student data;
    address next;
};

struct LinkedList {
    address first;
};

bool isEmpty(LinkedList L);
void createList(LinkedList &L);
address alokasi(int age, string name, string id);
void dealokasi(address &P);
void printList(LinkedList L);
void insertFirst(LinkedList &L, address P);
void insertAfter(LinkedList &L, address Prev, address P);
void insertLast(LinkedList &L, address P);
void delfirst(LinkedList &L);
void delAfter(LinkedList &L, address Prev, address P);
void delLast(LinkedList &L);
int nbList(LinkedList L);
void delList(LinkedList &L);

#endif
```

**`list.cpp`**

```cpp
#include "List.h"
#include <iostream>
using namespace std;

bool isEmpty(LinkedList L) {
    return L.first == Nil;
}

void createList(LinkedList &L) {
    L.first = Nil;
}

address alokasi(int age, string name, string id) {
    address P = new Node;
    if (P != Nil) {
        P->data.age = age;
        P->data.name = name;
        P->data.id = id;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    P->next = Nil;
    delete P;
}

void printList(LinkedList L) {
    address P = L.first;
    while (P != Nil) {
        cout << "Name: \t" << P->data.name
             << ", ID: \t" << P->data.id
             << ", Age: " << P->data.age << endl;
        P = P->next;
    }
}

void insertFirst(LinkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter(LinkedList &L, address Prev, address P) {
    if (Prev != Nil) {
        P->next = Prev->next;
        Prev->next = P;
    }
}

void insertLast(LinkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) Q = Q->next;
        Q->next = P;
    }
}

void delfirst(LinkedList &L) {
    if (isEmpty(L)) {
        cout << "List is empty, cannot delete." << endl;
    } else {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

void delAfter(LinkedList &L, address Prev, address P) {
    if (isEmpty(L)) {
        cout << "List is empty, cannot delete." << endl;
    } else if (Prev != Nil && Prev->next != Nil) {
        P = Prev->next;
        Prev->next = P->next;
        P->next = Nil;
        dealokasi(P);
    } else {
        cout << "Previous node is not valid, cannot delete." << endl;
    }
}

void delLast(LinkedList &L) {
    if (isEmpty(L)) {
        cout << "List is empty, cannot delete." << endl;
    } else {
        address P = L.first;
        address Q = Nil;
        while (P->next != Nil) {
            Q = P;
            P = P->next;
        }
        if (Q != Nil) Q->next = Nil;
        else L.first = Nil;
        dealokasi(P);
    }
}

int nbList(LinkedList L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void delList(LinkedList &L) {
    while (!isEmpty(L)) delfirst(L);
}
```

**`main.cpp`**

```cpp
#include <iostream>
#include "List.h"
using namespace std;

int main() {
    LinkedList L;
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil;
    createList(L);

    nodeA = alokasi(20, "Dhimas", "2311102151");
    nodeB = alokasi(21, "Arvin", "2311102152");
    nodeC = alokasi(20, "Budi", "2311102153");
    nodeD = alokasi(22, "Citra", "2311102154");
    nodeE = alokasi(19, "Dina", "2311102155");

    insertFirst(L, nodeA);
    insertLast(L, nodeB);
    insertAfter(L, nodeA, nodeC);
    insertFirst(L, nodeD);
    insertLast(L, nodeE);

    cout << "Isi list:" << endl;
    printList(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    delfirst(L);
    delLast(L);
    delAfter(L, L.first, Nil);

    cout << "\nSetelah penghapusan:" << endl;
    printList(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    delList(L);
    cout << "\nSetelah delList, jumlah node: " << nbList(L) << endl;
    return 0;
}
```

Program membuat list mahasiswa, melakukan penyisipan pada awal, akhir, dan setelah node tertentu, kemudian menampilkan jumlah node. Setelah itu dilakukan penghapusan node dan seluruh list dikosongkan menggunakan `delList()`.

## Unguided

### 1. ADT Singly Linked List

Buat ADT singly linked list dengan `infotype` bertipe integer, `address` sebagai pointer ke `ElmList`, serta operasi `createList`, `alokasi`, `dealokasi`, `printInfo`, dan `insertFirst`.

**`Singlylist.h`**

```cpp
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

```

**`Singlylist.cpp`**

```cpp
#include <iostream>
#include "Singlylist.h"
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
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

```

**`main.cpp`**

```cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi list: ";
    printInfo(L);
    return 0;
}

```

### Output Unguided 1
![Screenshot Output Unguided 1_1](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul4/output/1.png)


List dimulai dalam keadaan kosong. Setiap nilai dialokasikan sebagai node baru, kemudian dimasukkan menggunakan `insertFirst()`. Karena setiap node baru selalu diletakkan di depan node sebelumnya, urutan output menjadi terbalik dari urutan alokasi, yaitu `9 12 8 0 2`. Pointer `next` pada node terakhir bernilai `Nil`, sehingga penelusuran berhenti setelah seluruh data ditampilkan.

## Kesimpulan

Praktikum Modul 4 memperkenalkan singly linked list sebagai struktur data dinamis yang tersusun dari node-node yang saling terhubung menggunakan pointer. Operasi create, alokasi, insert, view, delete, dan dealokasi dapat dipisahkan ke dalam ADT melalui file header, file implementasi, dan program utama. Penyisipan menggunakan `insertFirst()` menunjukkan bahwa urutan data dapat berubah karena node baru ditempatkan di awal list. Penggunaan `new` dan `delete` juga menunjukkan pentingnya pengelolaan memori pada linked list.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4.
