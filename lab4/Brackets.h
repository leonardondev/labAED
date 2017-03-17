/*
 * Brackets.h
 *
 */
#ifndef BRACKETS_H
#define BRACKETS_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Stack.h"
using namespace std;

class Brackets
{ public:
    Brackets();
    Brackets(string e);
    void setExpression(string e);
    void getExpression(string &e);
    bool checkBalancedBrackets();
  private:
    string expression; // expressao aritmetica a ser analisada
    Stack  S;          // pilha para uso na verificacao de equilibrio de delimitadores
};

#endif /* BRACKETS_H */
