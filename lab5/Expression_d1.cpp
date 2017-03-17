//LEONARDO DO NASCIMENTO
//drive para teste do RPN

#include<iostream>
#include"Expression.h"
using namespace std;

int main(){

	Expression e1("4*(2+3)");

	cout << "Infix..: |" << e1.getInfix() << "|" << endl;
	
	
//	cout << "Infix..: |" << e1.getInfix() << "|" << endl
//	<< "Postfix: |" << e1.getPostfix() << "|" << endl
//	<< "Value..: " << e1.getValue() << endl
//	<< endl;
	
//	cout << "Infix..: |" << e2.getInfix() << "|" << endl
//	<< "Postfix: |" << e2.getPostfix() << "|" << endl
//	<< "Value..: " << e2.getValue() << endl
//	<< endl;
	
	return 0;	

}
