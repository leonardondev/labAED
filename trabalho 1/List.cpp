/*
 * List.cpp
 *
 *  Created on:
 *      Author:
 */
#include "List.h"
//---------------------------------------------------------------
List::List()
{
  head = NULL;
  count = 0;
}
//---------------------------------------------------------------
List::~List()
{
  Clear();
}
//---------------------------------------------------------------
bool List::Empty()
{
  return (head == NULL);
}
//---------------------------------------------------------------
bool List::Full()
{
   return false;
}
//---------------------------------------------------------------
void List::Clear()
{ ListPointer q;

  while (head != NULL)
  {  q = head;
     head = head->NextNode;
     delete q;
  }
  count = 0;
}
//---------------------------------------------------------------
long List::Size()
{
   return count;
}
//---------------------------------------------------------------
void List::Insert(long p, ListEntry x)
{ ListPointer NewNode, current;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  NewNode = new ListNode;
  NewNode->Entry = x;
  if(p == 1)
  {  NewNode->NextNode = head;
     head = NewNode;
  }
  else
  {  SetPosition(p-1,current);
     NewNode->NextNode = current->NextNode;
     current->NextNode = NewNode;
  }
  count++;
}
//---------------------------------------------------------------
void List::Delete(long p, ListEntry &x)
{ ListPointer Node, current;

  if (p < 1 || p > count)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  if(p == 1)
  {  Node = head;
     head = Node->NextNode;
  }
  else
  {  SetPosition(p-1,current);
     Node = current->NextNode;
     current->NextNode = Node->NextNode;
  }
  x = Node->Entry;
  delete Node;
  count = count - 1;
}
//---------------------------------------------------------------
void List::Retrieve(long p, ListEntry &x)
{ ListPointer current;

  SetPosition(p,current);
  x = current->Entry;
}
//---------------------------------------------------------------
long List::Search(ListEntry x)
{ long p=1;
  ListPointer q=head;

  while (q != NULL && q->Entry != x)
  {  q = q->NextNode;
     p++;
  }
  return (q == NULL ? 0 : p);
}
//---------------------------------------------------------------
string List::toString()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q->Entry << ",";
     q = q->NextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
string List::toStringAddr()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q << ",";
     q = q->NextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
void List::SetPosition(long p, ListPointer &current)
{ long i;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  current = head;
  for(i=2; i<=p; i++)
      current = current->NextNode;
}
//---------------------------------------------------------------
long List::GetAddr(ListEntry x)
{ ListPointer current=NULL;
  long p = Search(x);
  if(p != 0)
    SetPosition(p, current);
  return (long)current;
}
//---------------------------------------------------------------
bool List::Swap(ListEntry a, ListEntry b)
{ // sua implementacao vem aqui

/*se a lista tem menos de 2 elementos, 	returna false*/
	if(Size()<2)
		return false;


	ListPointer p1, p2, q1, q2;
	p1 = head;
	p2 = head;
	q1 = p1;
	q2 = p2;
	bool fimA = false;
	bool fimB = false;
	
	if(head->Entry == a){
		p1 = head;
		p2 = head;
		fimA = true;
	}
	/*n iteracoes*/
	while(!fimA || !fimB){
		if(p2 != NULL && p2->Entry != a && fimA==false){
			p1=p2;
			p2=p2->NextNode;
		}
		else fimA = true;
		
		if(q2 != NULL && q2->Entry != b && fimB==false){
			q1=q2;
			q2=q2->NextNode;		
		}
		else fimB = true;
	
	}//fim do while
	cout << "ponteiro p1..: " << p1 << endl;
	cout << "ponteiro p2..: " << p2 << endl;
	cout << "ponteiro q1..: " << q1 << endl;
	cout << "ponteiro q2..: " << q2 << endl;
	
/*se nao encontrar a e b, 		returna false*/
	if(p2==NULL || q2==NULL)
		return false;

/***adjacentes***/
	else if(p2==q1 || p1==q2){
		p2->NextNode = q2->NextNode;
		p1->NextNode = q2;
		q2->NextNode = q1;
		return true;
	}
	

/***head***/
	else if(1){
		p2->NextNode = q2->NextNode;
		q1->NextNode = p2;
		q2->NextNode = q1;
		head = q2;
		return true;
	}

/***tail***/
	else if(q2->NextNode == NULL){
		q2->NextNode = p2->NextNode;
		p1->NextNode = q2;
		q1->NextNode = p2;
		p2->NextNode = NULL;
		return true;
	}

/***nao adjacentes***/
	else if(q2->NextNode == NULL){
		ListPointer aux = q2->NextNode;
		q2->NextNode = p2->NextNode;
		q1->NextNode = p2;
		p1->NextNode = q2;
		p2->NextNode = aux;
		return true;
	}
	else{
		return false;
	}
}
//---------------------------------------------------------------
