/*
 * List.h
 *
 *  Created on:
 *      Author:
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

typedef long ListEntry;

class List
{ public:
    List();
    ~List();
    bool Empty();
    bool Full();
    void Clear();
    long Size();
    void Insert(long p, ListEntry x);
    void Delete(long p, ListEntry &x);
    void Retrieve(long p, ListEntry &x);
    long Search(ListEntry x);
    string toString();
    string toStringAddr();
    long GetAddr(long p);

    bool Swap(ListEntry a, ListEntry b);

  private:
    // declaracao de tipos
    struct ListNode; // serah definido logo adiante no codigo

    typedef ListNode *ListPointer;
    struct ListNode
    { ListEntry Entry;   		// tipo de dado colocado na lista
      ListPointer NextNode;   	// ligacao para proximo elemento na lista
    };

    // campos
    ListPointer head;           // inicio da lista
    long count;                 // numero de elementos

    // metodos privados
    void SetPosition(long p, ListPointer &current);
};

#endif /* LIST_H */
