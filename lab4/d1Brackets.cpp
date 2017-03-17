// Driver para testar delimitadores
#include <iostream>
#include <iomanip>
#include "Brackets.h"
using namespace std;

int main()
{  Brackets b1, b2("2+3*(1+7)"), b3;
   string e;

   cout << boolalpha;
   b1.getExpression(e);
   cout << "Expressao: |" << e << "|, delimitadores ok? " << b1.checkBalancedBrackets() << endl;

   b2.getExpression(e);
   cout << "Expressao: |" << e << "|, delimitadores ok? " << b2.checkBalancedBrackets() << endl;

   b3.setExpression("2*(1-3]");
   b3.getExpression(e);
   cout << "Expressao: |" << e << "|, delimitadores ok? " << b3.checkBalancedBrackets() << endl;

  return 0;
}
