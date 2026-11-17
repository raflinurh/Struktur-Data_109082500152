#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    ++S.top;
    S.info[S.top] = x;
}

bool pop(Stack &S, infotype &x) {
    if (isEmpty(S)) {
        return false;
    }

    x = S.info[S.top];
    --S.top;
    return true;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }

    for (int i = S.top; i >= 0; --i) {
        cout << S.info[i];
        if (i > 0) {
            cout << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    for (int left = 0, right = S.top; left < right; ++left, --right) {
        infotype temp = S.info[left];
        S.info[left] = S.info[right];
        S.info[right] = temp;
    }
}
