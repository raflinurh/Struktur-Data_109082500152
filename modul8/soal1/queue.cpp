#include "queue.h"

#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX_QUEUE - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        ++Q.tail;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    infotype result = -1;
    if (isEmptyQueue(Q)) {
        cout << "Antrean kosong!" << endl;
        return result;
    }

    result = Q.info[Q.head];
    for (int i = Q.head; i < Q.tail; ++i) {
        Q.info[i] = Q.info[i + 1];
    }

    --Q.tail;
    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }
    return result;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
        cout << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; ++i) {
        cout << Q.info[i];
        if (i < Q.tail) {
            cout << " ";
        }
    }
    cout << endl;
}
