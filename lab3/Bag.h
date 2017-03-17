// Bag.h
//LEONARDO DO NASCIMENTO
// Declaração/interface para sacola
#include <cstring>
using namespace std;

#ifndef BAG_H
#define BAG_H

class Bag
{ public:
     Bag();
     void Insert(int NewEntry);
     int Occurrence(int Entry);
     void Remove(int Entry);
     bool Full();
     bool Empty();
     int Size();
     string toString();
  private:
    static const int CAPACITY = 100;
    int Data[CAPACITY+1];
    int Used;
};

#endif

