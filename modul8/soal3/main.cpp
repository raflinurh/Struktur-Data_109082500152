#include "queue.h"

#include <iostream>

using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    for (int i = 1; i <= 5; ++i) {
        enqueue(Q, i * 10);
    }
    printInfo(Q);

    dequeue(Q);
    dequeue(Q);
    enqueue(Q, 60);
    enqueue(Q, 70);
    printInfo(Q);

    return 0;
}
