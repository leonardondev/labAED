//LEONARDO DO NASCIMENTO
/*
 * StackTemplate.h
 */

#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H

#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

template< class StackEntry >
class Stack
{ public:
    Stack();
    bool Empty();
    bool Full();
    void Push(StackEntry x);
    void Pop(StackEntry &x);
    void Top(StackEntry &x);
    int Size();
    void Clear();
    string toString();
  private:
    static const int MaxStack = 100;
    int top;                       // topo da pilha
    StackEntry Entry[MaxStack+1];  // vetor com elementos
};

template< class StackEntry >
Stack<StackEntry>::Stack()
// pre-condicao: nenhuma
// pos-condicao: Pilha eh criada e iniciada como vazia
{
  top = 0;
}

template< class StackEntry >
bool Stack<StackEntry>::Empty()
// pre-condicao: Pilha ja tenha sido criada
// pos-condicao: funcao retorna true se a pilha esta vazia; false caso contrario
{
  return (top == 0);
}

template< class StackEntry >
bool Stack<StackEntry>::Full()
// pre-condicao: Pilha ja tenha sido criada
// pos-condicao: funcao retorna true se a pilha esta cheia; false caso contrario
{
  return (top == MaxStack);
}

template< class StackEntry >
void Stack<StackEntry>::Push(StackEntry x)
// pre-condicao: Pilha S ja tenha sido criada
// pos-condicao: O item x é armazenado no topo da pilha
{
  if (Full())
  { cout << "Pilha Cheia" << endl;
    abort();
  }
  top++;
  Entry[top] = x;
}

template< class StackEntry >
void Stack<StackEntry>::Pop(StackEntry &x)
// pre-condicao: Pilha ja tenha sido criada e não esta vazia
// pos-condicao: O item no topo da pilha eh removido e seu valor retornado na variavel x
{
  if (Empty())
  { cout << "Pilha Vazia" << endl;
    abort();
  }
  x = Entry[top];
  top--;
}

template< class StackEntry >
void Stack<StackEntry>::Top(StackEntry &x)
// pre-condicao: Pilha ja tenha sido criada e não esta vazia
// pos-condicao: O item no topo da pilha eh retornado na variavel x; pilha permanece inalterada
{
  if (Empty())
  { cout << "Pilha Vazia" << endl;
    abort();
  }
  x = Entry[top];
}



template< class StackEntry >
int Stack<StackEntry>::Size()
// pre-condicao: Pilha ja tenha sido criada
// pos-condicao: retorna o numero de elementos da pilha
{  return top;
}


template< class StackEntry >
void Stack<StackEntry>::Clear()
// pre-condicao: Pilha ja tenha sido criada
// pos-condicao: Esvazia o conteudo da pilha
{  top = 0;
}

template< class StackEntry >
string Stack<StackEntry>::toString()
// pre-condicao: Pilha ja tenha sido criada
// pos-condicao: Transforma conteudo em uma string separada por espacos (Topo a direita)
{  int i;
   stringstream ss;
   
   for(i=1; i<=top; i++)
       ss << Entry[i];
   return ss.str();       
}

#endif /* STACKTEMPLATE_H */
