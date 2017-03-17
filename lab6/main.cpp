#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "BSTreeTemplate.h"
using namespace std;

int main()
{ BinarySearchTree<int> t;
  int e;

  cout << "Arvore " << endl;
  cout << "--------------------------------------------" << endl;
  t.Print();
  cout << "--------------------------------------------" << endl;
  cout << "Elemento? (>0 insere, <0 remove, =0 termina) ";
  cin >> e;
  while(e != 0)
  { if(e > 0)
    { cout << "Inserindo " << e << endl;
      t.Insert(e);
      cout << boolalpha << "Busca " << t.Search(e) << endl;
    }
    else
    { cout << "Removendo " << -e << endl;
      t.Delete(-e);
      cout << boolalpha << "Busca " << t.Search(-e) << endl;
    } 
    cout << "Arvore " << endl;
    cout << "--------------------------------------------" << endl;
    t.Print();
    cout << "--------------------------------------------" << endl;
    cout << "Nos = " << t.Nodes() << " Folhas = " << t.Leaves() << " Altura = " << t.Height() << endl;
    cout << "Min = " << t.Minimum() << " Max = " << t.Maximum() << endl;
    cout << "2o Min = " << t.SecondMinimum() << endl;
    
    cout << "Elemento? (>0 insere, <0 remove, =0 termina) ";
    cin >> e;
  }        
  cout << "Arvore Final" << endl;
  cout << "--------------------------------------------" << endl;
  t.Print();
  cout << "--------------------------------------------" << endl;
  return 0;   
}
