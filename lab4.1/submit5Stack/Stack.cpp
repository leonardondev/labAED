/*
 * Stack.cpp
 *
 */
#include "Stack.h"

Stack::Stack()
// pré-condição: nenhuma
// pós-condição: Pilha é criada e iniciada como vazia
{
  Top = 0;
}

bool Stack::Empty()
// pré-condição: Pilha já tenha sido criada
// pós-condição: função retorna true se a pilha está vazia; false caso contrário
{
  return (Top == 0);
}

bool Stack::Full()
// pré-condição: Pilha já tenha sido criada
// pós-condição: função retorna true se a pilha está cheia; false caso contrário
{
  return (Top == MaxStack);
}

void Stack::Push(StackEntry x)
// pré-condição: Pilha S já tenha sido criada
// pós-condição: O item x é armazenado no topo da pilha
{
  if (Full())
  { cout << "Pilha Cheia" << endl;
    abort();
  }
  Top++;
  Entry[Top] = x;
}

void Stack::Pop(StackEntry &x)
// pré-condição: Pilha já tenha sido criada e não está vazia
// pós-condição: O item no topo da pilha é removido e seu valor é retornado na variável x
{
  if (Empty())
  { cout << "Pilha Vazia" << endl;
    abort();
  }
  x = Entry[Top] ;
  Top--;
}

int Stack::Size()
// pré-condição: Pilha já tenha sido criada
// pós-condição: retorna o numero de elementos da pilha
{  return Top;
}


void Stack::Clear()
// pré-condição: Pilha já tenha sido criada
// pós-condição: Esvazia o conteudo da pilha
{  Top = 0;
}




