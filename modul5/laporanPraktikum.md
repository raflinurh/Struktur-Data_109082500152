<div align="center">

# **Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)**

Rafli Nurhidayat - 109082500152

</div>

## Dasar Teori

Linked list merupakan struktur data linear yang terdiri atas sekumpulan node
yang saling terhubung menggunakan pointer. Setiap node menyimpan data dan
alamat node berikutnya. Berbeda dengan array yang menempatkan elemen secara
berurutan dan biasanya memiliki ukuran tertentu, linked list menggunakan
alokasi memori dinamis sehingga jumlah elemennya dapat berubah selama program
berjalan [1][2].

### A. Singly Linked List

Singly linked list adalah linked list yang setiap nodenya mempunyai satu
pointer `next`. Pointer tersebut menunjuk ke node berikutnya. Node terakhir
memiliki `next` bernilai `NULL` atau `Nil`. Struktur list memiliki pointer
`first` yang menunjuk node pertama.
Konsep pointer pada struktur node memungkinkan setiap elemen terhubung secara
dinamis tanpa harus disimpan bersebelahan di memori [6].

Komponen utama singly linked list adalah:

1. **Info**, yaitu data yang disimpan di dalam node.
2. **Next**, yaitu pointer menuju node berikutnya.
3. **First**, yaitu pointer menuju node pertama.
4. **Address**, yaitu alamat node yang digunakan untuk menghubungkan elemen.
5. **Nil**, yaitu penanda bahwa pointer tidak menunjuk node mana pun.

Pada program Modul 5, bagian `info` berisi data mahasiswa yang terdiri atas
nama, NIM, dan umur. Pointer `next` menghubungkan data mahasiswa tersebut
menjadi sebuah list.

### B. Searching pada Linked List

Searching adalah proses mencari node berdasarkan informasi tertentu. Karena
node pada singly linked list tidak dapat diakses langsung menggunakan indeks,
pencarian dilakukan secara berurutan dari `first`. Pointer bantu bergerak ke
node berikutnya melalui `next` sampai data ditemukan atau pointer bernilai
`Nil`.

Pada implementasi guided, fungsi `findNodeByData` mencari data berdasarkan
nama atau NIM. Pada implementasi latihan, fungsi `findElm` mencari node
berdasarkan nilai integer. Jika data tidak ditemukan, fungsi mengembalikan
`Nil`.

### C. Penyisipan Node

Penyisipan node dilakukan dengan mengubah hubungan pointer antar-node.
Penyisipan pada awal list dilakukan dengan mengarahkan `next` node baru ke
`first`, kemudian memindahkan `first` ke node baru. Penyisipan setelah node
tertentu dilakukan dengan menyimpan alamat node setelahnya ke `next` node baru.
Penyisipan pada akhir list dilakukan dengan menelusuri list sampai node
terakhir, kemudian menghubungkannya ke node baru.

Operasi penyisipan yang digunakan adalah:

1. `insertFirst`, untuk menambahkan node di awal list.
2. `insertAfter`, untuk menambahkan node setelah node tertentu.
3. `insertLast`, untuk menambahkan node di akhir list.

### D. Penghapusan Node

Penghapusan node harus memperbaiki hubungan pointer dan membebaskan memori
node yang dihapus. `delFirst` memindahkan `first` ke node berikutnya.
`delLast` mencari node terakhir beserta node sebelumnya, kemudian memutuskan
hubungannya. `delAfter` menghapus node yang berada setelah node tertentu.

Selain menghapus satu node, seluruh isi list dapat dihapus menggunakan
`deleteList` atau `delAll`. Proses ini dilakukan dengan menghapus node satu
per satu sampai list kosong.

### E. Alokasi dan Dealokasi Memori

Node dibuat secara dinamis menggunakan operator `new`. Proses ini disebut
alokasi dan dilakukan oleh fungsi `alokasi`. Ketika node sudah tidak digunakan,
memori harus dikembalikan ke sistem menggunakan `delete` melalui fungsi
`dealokasi` [3][4]. Dealokasi diperlukan untuk mencegah memory leak.

Pointer node yang sudah didealokasi tidak boleh digunakan kembali. Karena itu,
hubungan `next` diputus terlebih dahulu sebelum node dihapus. List juga harus
diakhiri dengan `first = Nil` ketika seluruh node sudah dihapus.

### F. Pembaruan Data dan Kompleksitas

Data pada node dapat diperbarui tanpa membuat node baru. Pembaruan dapat
dilakukan pada node pertama, node terakhir, node setelah posisi tertentu, atau
node yang ditemukan berdasarkan NIM. Untuk menemukan node berdasarkan data,
program harus menelusuri list sehingga kompleksitas waktunya adalah `O(n)`.

Penyisipan di awal memiliki kompleksitas `O(1)`, sedangkan penyisipan di akhir
dan pencarian node umumnya memiliki kompleksitas `O(n)` [5]. Singly linked
list efisien untuk penyisipan dan penghapusan yang lokasinya sudah diketahui,
tetapi tidak mendukung akses acak seperti array.

## Guided

### 1. Implementasi Linked List Mahasiswa

**`list.h`**

```cpp
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

void updateFirst(linkedlist &list);
void updateLast(linkedlist &list);
void updateAfter(linkedlist list, address &prev);
void updateByNim(linkedlist list, string nim);
    
address findNodeByData(linkedlist List, string data);
#endif

#endif
```

**`list.cpp`**

```cpp
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", umur : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;
        list.first->isidata = newData;
    }
}

void updateLast(linkedlist &list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->isidata = newData;
    }
}

void updateAfter(linkedlist list, address &prev)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else if (prev == Nil || prev->next == Nil)
    {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
    }
    else
    {
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    prev->next->isidata = newData;
    }
}

void updateByNim(linkedlist list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = findNodeByData(list, nim);

        if (nodeBantu != Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Masukan nim baru : ";
            cin >> nodeBantu->isidata.nim;
            cout << "Masukan umur baru : ";
            cin >> nodeBantu->isidata.umur;

            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// prosedur-prosedur untuk searching data didalam list
address findNodeByData(linkedlist List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodeByAddress(linkedlist List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", umur : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas umur " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur > nilaiAwal && umur < nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", umur : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```

**`main.cpp`**

```cpp
#include "list.h"
#include <iostream>
using namespace std;

int main(){
		linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    printList(List);

    updateLast(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    printList(List);

    updateAfter(List, nodeC);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER ---" << endl;
    printList(List);

    updateByNim(List, "2311102133");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);

    return 0;
}
```

Program membuat lima node mahasiswa dengan data NIM dan informasi mahasiswa,
kemudian memasukkannya ke dalam singly linked list pada beberapa posisi, yaitu
di awal, di akhir, dan setelah node tertentu. Setelah proses insert selesai,
program menampilkan seluruh isi list serta menghitung jumlah node untuk
memastikan struktur list terbentuk dengan benar. Selanjutnya, program menguji
operasi pembaruan data melalui `updateFirst`, `updateLast`, dan `updateAfter`.
Program juga menjalankan `updateByNim` untuk mencari mahasiswa berdasarkan NIM
tertentu dan memperbarui datanya. Setiap perubahan ditampilkan kembali agar
hasil dari masing-masing operasi dapat diamati dan dibandingkan.

## Unguided

### 1. Implementasi ADT Singly Linked List

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


#endif
```

**`Singlylist.cpp`**

```cpp
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
```

**`main.cpp`**

```cpp
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
```
### Output Unguided 1
![Screenshot Output Unguided 1_1](https://github.com/raflinurh/Struktur-Data_109082500152/blob/main/modul5/output/1.png)

Program ini mengimplementasikan struktur data *singly linked list* menggunakan bahasa C++. Setiap elemen list disimpan dalam sebuah node yang memiliki data bertipe integer dan pointer `next` yang menunjuk ke node berikutnya. Operasi yang dilakukan meliputi inisialisasi list, penambahan elemen, pencarian elemen, penampilan seluruh isi list, perhitungan total nilai, serta penghapusan seluruh node.

Berdasarkan hasil pengujian, lima elemen berhasil dimasukkan ke dalam list dan ditampilkan secara berurutan. Fungsi `findElm(L, 8)` juga dapat menentukan keberadaan nilai 8 dengan benar. Selanjutnya, seluruh nilai elemen dijumlahkan menggunakan traversal dari node pertama hingga node terakhir. Setelah proses selesai, fungsi `delAll(L)` dipanggil untuk menghapus semua node dan membebaskan memori yang telah digunakan. Dengan demikian, program telah menerapkan operasi dasar *singly linked list* serta pengelolaan memori secara dinamis dengan baik.

## Daftar Pustaka

[1] Telkom University, *Modul Praktikum Struktur Data: Singly Linked List*,
Modul 5, School of Computing, Telkom University.

[2] M. T. Goodrich, R. Tamassia, and M. H. Goldwasser, *Data Structures and
Algorithms in Java*, 6th ed. Hoboken, NJ: Wiley, 2014.

[3] B. Stroustrup, *The C++ Programming Language*, 4th ed. Upper Saddle
River, NJ: Addison-Wesley, 2013.

[4] S. B. Lippman, J. Lajoie, and B. E. Moo, *C++ Primer*, 5th ed. Boston,
MA: Addison-Wesley, 2012.

[5] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, *Introduction
to Algorithms*, 3rd ed. Cambridge, MA: MIT Press, 2009.

[6] cppreference.com, “Pointers,” “new expression,” and “delete expression,”
*C++ Reference*, [Online]. Available:
https://en.cppreference.com/w/cpp/language/pointer.html. [Accessed: Oct. 27,
2026].
