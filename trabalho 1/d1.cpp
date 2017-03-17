// Driver para testar delimitadores
#include <iostream>
#include "List.h"
using namespace std;

int main(){

List l;
l.Insert(1,3);
l.Insert(2,1);
l.Insert(3,8);
l.Insert(4,5);
l.Insert(5,2);
l.Insert(6,9);
l.Insert(7,4);
l.Insert(8,7);
cout << "Antes Swap" << endl;
cout << "Lista: " << l.toString() << endl;
cout << "Nos..: " << l.toStringAddr() << endl;
l.Swap(8,2);
cout << "Apos Swap" << endl;
cout << "Lista: " << l.toString() << endl;
cout << "Nos..: " << l.toStringAddr() << endl;
return 0;
}

