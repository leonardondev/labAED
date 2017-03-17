//Bag.cpp
//LEONARDO DO NASCIMENTO
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream> 
#include "Bag.h"
using namespace std;

Bag::Bag()
// pre: Nenhuma
// pos: A sacola eh criada vazia (sem elementos)
{ Used = 0;
}

void Bag::Insert(int NewEntry)
// pre: Bag não esteja cheia
// pos: Uma nova cópia de NewEntry eh adicionada aa Bag 
{ if(Full())
  { cout << "Sacola cheia..." << endl;
    abort();
  }
  Used++;
  Data[Used] = NewEntry;
}

int Bag::Occurrence(int Entry)
// pre: Nenhuma
// pos: Retorna o numero de ocorrencias do elemento
//      Entry na Bag
{ int i,total=0;

  for(i=1; i<=Used; i++)
    if(Data[i] == Entry)
      total++;
  return total;  
}

void Bag::Remove(int Entry)
// pre: Nenhuma
// pos: Remove uma ocorrencia do elemento Entry na Bag.
//      Se o elemento nao existir, a Bag permanece inalterada.
{
	/*condicao quando a lista esta vazia*/
	if(Empty()){
		cout << "Sacola vazia..." << endl;
		return;
	}
	
	/*condicao quando a lista tem elementos*/
	if(Data[Used] == Entry && Used > 0)
		Used--;
	else{
		for(int i=Used; i>=1; i--)
		if(Data[i] == Entry){
			Data[i] = Data[Used];
			Used--;
			return;	
		}
	}
	
}

bool Bag::Full()
// pre: Nenhuma
// pos: Retorna true se a sacola estah cheia; false caso contrario
{ return (Used == CAPACITY);
}

bool Bag::Empty()
// pre: Nenhuma
// pos: Retorna true se a sacola estah vazia; false caso contrario
{ return (Used == 0);
}

int Bag::Size()
// pre: Nenhuma
// pos: Retorna o numero de elementos na sacola
{ return Used;
}

string Bag::toString()
// pre: Nenhuma
// pos: Retorna Bag no formato de string
//      Por exemplo, Bag contendo elementos 8,10,8
//      retorna [8,10,8]
{ int i;
  stringstream ss;

  ss << "[";
  for(i = 1; i <= Used; i++)
  {  ss << Data[i];
     if( i != Used )
       ss << ",";
  }
  ss << "]";
  return ss.str();
}
