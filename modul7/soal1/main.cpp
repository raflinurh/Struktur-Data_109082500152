#include "stack.h"

#include <iostream>

using namespace std;

int main() {
    Stack S;
    int value;

    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S, value);
    push(S, 2);
    push(S, 3);
    pop(S, value);
    push(S, 9);

    cout << "Isi stack: ";
    printInfo(S);

    cout << "Stack setelah dibalik: ";
    balikStack(S);
    printInfo(S);

    return 0;
}
