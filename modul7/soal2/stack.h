#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

const int MAX = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
void printInfo(Stack S);
void pushAscending(Stack &S, infotype x);
void balikStack(Stack &S);

#endif
