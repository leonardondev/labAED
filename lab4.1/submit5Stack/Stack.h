/*
 * Stack.h
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
using namespace std;

typedef char StackEntry;
const long int MaxStack = 100;
class Stack
{ public:
    Stack();
    bool Empty();
    bool Full();
    void Push(StackEntry x);
    void Pop(StackEntry &x);
    int Size();
    void Clear();
  private:
    int Top;                       // topo da pilha
    StackEntry Entry[MaxStack+1];  // vetor com elementos
};

#endif /* STACK_H */
