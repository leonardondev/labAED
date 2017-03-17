//LEONARDO DO NASCIMENTO
#include "Expression.h"
#include <cmath>
using namespace std;

// pre: nenhuma
// pos: Dada expressao infixa s, converte-a na notacao posfixa e encontra seu valor
Expression::Expression(string s)
{  setInfix(s);
}
                              
// pre: nenhuma
// pos: Dada expressao infixa s, converte-a na notacao posfixa e encontra seu valor
void Expression::setInfix(string s)
{  infix = s;
   infixToPostfix();
   evalPostfix();
}

// pre: objeto criado
// pos: retorna a expressao na notacao infixa
string Expression::getInfix()
{  return infix;
}

// pre: objeto criado
// pos: retorna a expressao na notacao posfixa (RPN)
string Expression::getPostfix()
{  return postfix;
}

// pre: objeto criado
// pos: retorna o valor da expressao na notacao posfixa (RPN)
int Expression::getValue()
{  return value;
}


// pre: infix contem uma expressao aritmetica valida, contendo operadores e digitos na notacao infixa
// pos: postfix contem a mesma expressao dada por infix, convertida na notacao pos-fixada (RPN)
void Expression::infixToPostfix()
{   // Implemente o Algoritmo 1 aqui
    // Ao final, o campo postfix do objeto deve conter a expressao na notacao RPN
    // Remova ou altere qualquer linha seguinte, de acordo com a necessidade do Algoritmo 1
    postfix = "";
    // Para declarar uma pilha usando templates, associe o tipo de dado colocado na mesma 
    Stack<char> S; // um pilha de caracteres
  
    int i;
    int p=0;
    char c;
    for(i=0 ; i<infix.length() ; i++){//percorre infixo
  	c = infix[i];//caracter a ser analizado
  	
  	//se c e um operando: Transferir c para pos-fixa
  	if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9'){
  		postfix[p] = c;
  		p++;
  		i++;
  	}
  	
  	//se c e um parentese esquerdo: Coloque c na pilha
  	else if(c == '(' ){
  		S.Push(c);
  		i++;
  	}
  	
  	
  	/*se c e um parentese direito: Retire caracteres da pilha e transfira-os
  	para pos-fixa ate encontrar um parentese esquerdo.
  	Retire o parentese esquerdo da pilha e descarte-o.*/
  	
  	else if(c == ')' ){
  		char t;
  		S.Pop(t);
  		while(t!='('){
  			postfix[p] = t;
  			p++; 
  			S.Pop(t); 			
  		}
  	}
  	
  	/*se c e um operador:
  		Assuma t como o elemento no topo da pilha.
		Transfira os elementos da pilha para pos-fixa ate que:
		-  precedencia de t seja menor do que a precedencia de c ou
		-  t seja um parentese esquerdo ou
		-  a pilha esteja vazia
		Insira c na pilha*/
  	else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^'){
  		char t;
  		S.Pop(t);
  		while( precedencia(t,c) && t!='(' && !S.Empty() ){
			postfix += t;
  		    p++; 
  		    S.Pop(t);
  		}
  		S.Push(c);
  	}
  	
  }//fim for em infixo
  	
}


// pre: postfix contem a expressao na notacao posfixa
// pos: retorna o valor da expressao, utilzando Algoritmo 2
void Expression::evalPostfix()
{ // Implemente o Algoritmo 2 aqui
  // Ao final, o campo value do objeto deve conter o valor da expressao postfix
  // Remova ou altere qualquer linha seguinte, de acordo com a necessidade do Algoritmo 2
  // caso postfix nao tenha caracteres (string vazia) ou apenas espacos, retorne zero
  // Para declarar uma pilha usando templates, associe o tipo de dado colocado na mesma 
  value = 0;	 // valor da expressao posfix obtida pelo Algoritmo 2
  Stack<int>  S; // um pilha de inteiros
  infixToPostfix();
  int p;
  char c;
  int num1,num2;
  bool doisNumeros = false;
  for(p=0 ; p < postfix.length() ; p++){//percorre postfix
      c = postfix[p];//caracter a ser analizado
      
      if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9'){
          S.Push( (int)c - 48 ); /*guarda o valor numerico do char*/
          p++;
      }
      
      if(doisNumeros){
		  if(c=='+'){
		      if(!S.Empty())
		      S.Pop(num2);
		      if(!S.Empty())
		      S.Pop(num1);
		      S.Push(num1+num2);
		  }
		  if(c=='-'){
		      if(!S.Empty())
		      S.Pop(num2);
		      if(!S.Empty())
		      S.Pop(num1);
		      S.Push(num1-num2);
		  }
		  if(c=='*'){
		      if(!S.Empty())
		      S.Pop(num2);
		      if(!S.Empty())
		      S.Pop(num1);
		      S.Push(num1*num2);
		  }
		  if(c=='/'){
		      if(!S.Empty())
		      S.Pop(num2);
		      if(!S.Empty())
		      S.Pop(num1);
		      S.Push(num1/num2);
		  }
		  if(c=='%'){
		      if(!S.Empty())
		      S.Pop(num2);
		      if(!S.Empty())
		      S.Pop(num1);
		      S.Push(num1%num2);
		  }
		  if(c=='^'){
		      if(!S.Empty())
		      S.Pop(num2);
		      if(!S.Empty())
		      S.Pop(num1);
		      S.Push((int)pow(num1,num2));
		  }
		  
	  }//fim teste doisNumeros
	  
  }//fim for
  S.Pop(value);
  if(S.Empty()) cout << "deu certo!!!!" << endl;
}

//pre: ter dois caracteres de oeracoes
//pos: retorna verdadeiro se op1 precede sobre op2
bool Expression::precedencia(char op1, char op2){  // + - * / % ^
     if(op1=='^')return true;
     else if( (op1=='*' || op1=='/' || op1=='%') && op2!= '^')return true;
     else if( (op1=='+' || op1=='-') && (op2=='+' || op2=='-') )return true;
     else return false;
}
