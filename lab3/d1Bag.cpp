// Driver para testar novo tipo de dados Sacola
//LEONARDO DO NASCIMENTO
#include <iostream>
#include "Bag.h"
using namespace std;

int main()
{ Bag b;

  cout << "Inserindo um 4 na sacola..." << endl;
  b.Insert(4); 
  cout << "Ha " << b.Occurrence(4) << " numero(s) 4 na sacola" << endl;
  cout << b.toString() << endl << endl;

  cout << "Inserindo um 8 na sacola..." << endl;
  b.Insert(8); 
  cout << "Ha " << b.Occurrence(8) << " numero(s) 8 na sacola" << endl;
  cout << b.toString() << endl << endl;;

  cout << "Inserindo um outro 4 na sacola..." << endl;
  b.Insert(4); 
  cout << "Ha " << b.Occurrence(4) << " numero(s) 4 na sacola" << endl;
  cout << endl << b.toString() << endl << endl;;

  cout << "Sacola esta' cheia? " << b.Full() << endl; 
  
  cout << "Removendo um 4 da sacola..." << endl;
  cout << endl << b.toString() << endl << endl;
  b.Remove(4);
  cout << endl << b.toString() << endl << endl; 
  cout << "Ha " << b.Occurrence(4) << " numero(s) 4 na sacola" << endl;
  

  cout << "Sacola esta' cheia? " << boolalpha << b.Full() << endl; 

  cout << endl << b.toString() << endl << endl;
  cout << "Ha " << b.Occurrence(10) << " numero(s) 10 na sacola" << endl;
  cout << "Removendo um 10 da sacola..." << endl;
  b.Remove(10); 
  cout << "Ha " << b.Occurrence(10) << " numero(s) 10 na sacola" << endl;
  cout << endl << b.toString() << endl << endl;

  cout << "Sacola esta' cheia? " << noboolalpha << b.Full() << endl; 
  cout << b.toString() << endl;
  
  cout << "Removendo um 4 da sacola..." << endl;
  cout << endl << b.toString() << endl << endl;
  b.Remove(4);
  cout << endl << b.toString() << endl << endl; 
  cout << "Ha " << b.Occurrence(4) << " numero(s) 4 na sacola" << endl;
  
  cout << "Removendo um 4 da sacola..." << endl;
  cout << endl << b.toString() << endl << endl;
  b.Remove(4);
  cout << endl << b.toString() << endl << endl; 
  cout << "Ha " << b.Occurrence(4) << " numero(s) 4 na sacola" << endl;
  
  cout << "Removendo um 8 da sacola..." << endl;
  cout << endl << b.toString() << endl << endl;
  b.Remove(8);
  cout << endl << b.toString() << endl << endl; 
  cout << "Ha " << b.Occurrence(8) << " numero(s) 8 na sacola" << endl;

  return 0;
}
