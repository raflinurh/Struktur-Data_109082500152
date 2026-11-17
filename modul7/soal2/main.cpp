#include "stack.h"

#include <iostream>

using namespace std;

int main() {
    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    cout << "Stack dengan push ascending: ";
    printInfo(S);

    cout << "Stack setelah dibalik: ";
    balikStack(S);
    printInfo(S);

    return 0;
}
