// Driver para testar novo tipo de dados Sacola
//LEONARDO DO NASCIMENTO
#include <iostream>
#include "Bag.h"
using namespace std;

int menu()
{ int opcao;

  cout << "1. Inserir" << endl;
  cout << "2. Contar ocorrencias de um numero" << endl;
  cout << "3. Testar se sacola cheia" << endl;
  cout << "4. Imprimir sacola" << endl;
  cout << "5. Remover um numero da sacola" << endl;
  cout << "9. Sair" << endl;
  cout << "   Opcao: ";
  cin >> opcao;
  cout << endl;
  return opcao;
}
//----------------------------------------------
int main()
{ Bag x;
  int opcao;
  int num;

  opcao = menu();
  while(opcao != 9)
  {  switch(opcao)
    {  case 1:  // inserir
         cout << "Numero a ser inserido: ";
         cin >> num;
         x.Insert(num);
         break;
       case 2:  // contar
         cout << "Numero a ser contado: ";
         cin >> num;
         cout << "Ha " << x.Occurrence(num) << " ocorrencias do numero "
              << num << " na sacola" << endl;
         break;
       case 3: // sacola cheia?
         if(x.Full())
            cout << "Sacola cheia" << endl;
         else 
            cout << "Sacola nao cheia" << endl;
         break;
       case 4:
         cout << x.toString() << endl;
         break;
       case 5:
         cout << "Numero a ser removido:";
         cin >> num;
         x.Remove(num);
         break;
    }
    opcao = menu();
  }    
}
