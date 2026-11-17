#include "stack.h"

#include <iostream>

using namespace std;

int main() {
    Stack S;
    createStack(S);

    getInputStream(S);
    cout << "Isi stack: ";
    printInfo(S);

    cout << "Stack setelah dibalik: ";
    balikStack(S);
    printInfo(S);

    return 0;
}
