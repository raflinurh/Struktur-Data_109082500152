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
    if (!isFull(S)) {
        S.info[++S.top] = x;
    }
}

void printInfo(Stack S) {
    for (int i = S.top; i >= 0; --i) {
        cout << S.info[i] << (i == 0 ? '\n' : ' ');
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        return;
    }

    int position = 0;
    while (position <= S.top && S.info[position] < x) {
        ++position;
    }

    for (int i = S.top; i >= position; --i) {
        S.info[i + 1] = S.info[i];
    }

    S.info[position] = x;
    ++S.top;
}

void balikStack(Stack &S) {
    for (int left = 0, right = S.top; left < right; ++left, --right) {
        infotype temp = S.info[left];
        S.info[left] = S.info[right];
        S.info[right] = temp;
    }
}
