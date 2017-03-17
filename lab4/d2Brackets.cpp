// Driver para testar delimitadores
#include <iostream>
#include <iomanip>
#include "Brackets.h"
using namespace std;

int main()
{  Brackets b1;
   string e;

   cout << "\nForneca uma expressao: ";
   while( getline(cin, e) )
   { // e = e.substr(0, e.length()-1); // remover <enter>
	  b1.setExpression(e);
      cout << boolalpha << endl;
 	  cout << "Expressao: |" << e << "|, delimitadores ok? " << b1.checkBalancedBrackets() << endl;
      cout << "\nForneca uma expressao: ";
   }

  return 0;
}
