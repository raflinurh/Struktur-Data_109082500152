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

void balikStack(Stack &S) {
    for (int left = 0, right = S.top; left < right; ++left, --right) {
        infotype temp = S.info[left];
        S.info[left] = S.info[right];
        S.info[right] = temp;
    }
}

void getInputStream(Stack &S) {
    cout << "Masukkan angka (tekan Enter untuk selesai): ";
    char input;
    while (cin.get(input) && input != '\n') {
        if (input >= '0' && input <= '9') {
            push(S, input - '0');
        }
    }
}
