/*
 * Brackets.cpp
*/
#include "Brackets.h"
using namespace std;

Brackets::Brackets()
// Pre: nenhuma
// Pos: Cria Brackets contendo expressao vazia (string sem caracteres)
{
}

Brackets::Brackets(string e)
// Pre: nenhuma
// Pos: Cria Brackets contendo expressao e fornecida
{  expression = e;
}

void Brackets::setExpression(string e)
// Pre: Objeto criado
// Pos: altera o valor atual da expressao para o valor s fornecido
{  expression = e;
}

void Brackets::getExpression(string &e)
// Pre: Objeto criado
// Pos: retorna o valor atual da expressao
{  e = expression;
}


bool Brackets::checkBalancedBrackets(){ 
	// sua implementacao vem aqui...
	// altere o valor de retorno, conforme especificacao deste metodo
	char x;
	S.Clear();
	for(unsigned int i=0 ; i<expression.length() ; i++){
		if(expression[i]=='(') S.Push('(');
		if(expression[i]=='[') S.Push('[');
		if(expression[i]=='{') S.Push('{');
		
		if( expression[i]==')'){		
			if( !S.Empty() ){
				S.Pop(x);
				if(x!='(')
					return false;
			}
			else
				return false;
		}//fim if
		
		if( expression[i]==']'){		
			if( !S.Empty() ){
				S.Pop(x);
				if(x!='[')
					return false;
			}
			else
				return false;
		}//fim if
		
		if( expression[i]=='}'){		
			if( !S.Empty() ){
				S.Pop(x);
				if(x!='{')
					return false;
			}
			else
				return false;
		}//fim if
		
	}//fim for
  
	return S.Empty();
	
}
