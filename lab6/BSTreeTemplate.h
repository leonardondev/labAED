#include <iostream>
#include <iomanip>
using namespace std;

#ifndef BSTREETEMPLATE_H
#define BSTREETEMPLATE_H

template< class TreeEntry >
class BinarySearchTree
{ public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool Empty();
    bool Full();
    void Clear();
    bool Search(TreeEntry x);
    void Insert(TreeEntry x);
    void Delete(TreeEntry x);
    void Print();
    int Nodes();
    int Leaves();
    int Height();
    TreeEntry Minimum();
    TreeEntry Maximum();
    TreeEntry SecondMinimum();
    
  private:
    // definicao de estruturas
    struct TreeNode; 
    typedef TreeNode *TreePointer; 

    struct TreeNode
    { TreeEntry Entry;             
      TreePointer LeftNode, RightNode; 
    };

    // campos
    TreePointer root;
    
    // metodos
    void Clear(TreePointer &t);
    bool ISearch(TreeEntry x);
    bool RSearch(TreeEntry x, TreePointer &t);
    void Delete(TreeEntry x, TreePointer &p);
    void DelMin(TreePointer &q,  TreePointer &r);
    void Preorder(TreePointer &t);
    void Inorder(TreePointer &t);
    void Postorder(TreePointer &t);
    void Print(TreePointer t, int s);
    int  Nodes(TreePointer &t);
    int  Leaves(TreePointer &t);
    int  Height(TreePointer &t);
}; 

//------------------------------------------------------------
template< class TreeEntry >
BinarySearchTree<TreeEntry>::BinarySearchTree()
{  
  root = NULL;
}
//------------------------------------------------------------
template< class TreeEntry >
BinarySearchTree<TreeEntry>::~BinarySearchTree()
{  
  Clear();
}
//------------------------------------------------------------
template< class TreeEntry >
bool BinarySearchTree<TreeEntry>::Empty()
{
  return (root == NULL);
}
//------------------------------------------------------------
template< class TreeEntry >
bool BinarySearchTree<TreeEntry>::Full()
{
  return false;
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Clear()
{
  Clear(root);
  root = NULL;
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Clear(TreePointer &t)
{
  if( t != NULL )
  { Clear( t->LeftNode );
    Clear( t->RightNode );
    delete t;
  }
}
//------------------------------------------------------------
template< class TreeEntry >
bool BinarySearchTree<TreeEntry>:: Search(TreeEntry x)
{ // basta escolher uma unica implementacao do metodo de busca
  // return ISearch(x);
  return RSearch(x, root);
}
//------------------------------------------------------------
template< class TreeEntry >
bool BinarySearchTree<TreeEntry>::ISearch(TreeEntry x)
{ TreePointer t=root;

  while (t != NULL && t->Entry != x) 
    if(x < t->Entry)
      t = t->LeftNode; // procurar subarvore esquerda
    else
      t = t->RightNode; // procurar subarvore direita
 
  return (t != NULL);
}
//------------------------------------------------------------
template< class TreeEntry >
bool BinarySearchTree<TreeEntry>::RSearch(TreeEntry x, TreePointer &t)
{
  if(t == NULL)
    return false; // x nao encontrado
  
  if(x < t->Entry)
      return RSearch(x,t->LeftNode);
  else
    if(x > t->Entry)
      return RSearch(x,t->RightNode);
   else     // x == t->Entry
      return true;
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Insert(TreeEntry x)
{ TreePointer p=NULL, q=root, r;

  while (q != NULL) 
  { p = q; 
    if(x < q->Entry)
      q = q->LeftNode;
    else
      q = q->RightNode;
  }
  
  r = new TreeNode;
  r->Entry = x;
  r->LeftNode = NULL;
  r->RightNode = NULL;

  if(p == NULL)
    root = r;  // arvore vazia
  else
    if(x < p->Entry)
      p->LeftNode = r;
    else
      p->RightNode = r;
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Delete(TreeEntry x)
{
  Delete(x,root);
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Delete(TreeEntry x, TreePointer &p)
{ TreePointer q;
   
   if(p == NULL)
   { cout << "Elemento inexistente" << endl;
     abort();
   }
   if(x < p->Entry)
      Delete(x,p->LeftNode);
   else
    if(x > p->Entry)
       Delete(x,p->RightNode);
    else // remover p->
    { q = p;
      if(q->RightNode == NULL)
         p = q->LeftNode;
      else
        if(q->LeftNode == NULL)
          p = q->RightNode;
        else
          DelMin(q,q->RightNode);
      delete q;
    }
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::DelMin(TreePointer &q,  TreePointer &r)
{
  if(r->LeftNode != NULL)
    DelMin(q,r->LeftNode);
  else
  { q->Entry = r->Entry;
    q = r;
    r = r->RightNode;
  }
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Print(TreePointer t, int s)
{ int i;

  if(t != NULL) 
  { Print(t->RightNode, s+3);
    for(i=1; i<= s; i++)
      cout << " ";
    cout << setw(6) << t->Entry << endl;
    Print(t->LeftNode, s+3);
  }
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Print()
{
  Print(root,0);     
  cout << endl << "Pre-ordem" << endl;
  Preorder(root);
  cout << endl << "Em-ordem" << endl;
  Inorder(root);
  cout << endl << "Pos-ordem" << endl;
  Postorder(root);
  cout << endl;
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Preorder(TreePointer &t)
{
  if(t != NULL)
  { cout << t->Entry << ",";
    Preorder(t->LeftNode);
    Preorder(t->RightNode);
  }
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Inorder(TreePointer &t)
{
  if(t != NULL)
  { Inorder(t->LeftNode);
    cout << t->Entry << ",";
    Inorder(t->RightNode);
  }
}
//------------------------------------------------------------
template< class TreeEntry >
void BinarySearchTree<TreeEntry>::Postorder(TreePointer &t)
{
  if(t != NULL)
  { Postorder(t->LeftNode);
    Postorder(t->RightNode);
    cout << t->Entry << ",";
  }
}
//------------------------------------------------------------
template< class TreeEntry >
int BinarySearchTree<TreeEntry>::Nodes()
{  return Nodes(root);
}
//------------------------------------------------------------
template< class TreeEntry >
int BinarySearchTree<TreeEntry>::Nodes(TreePointer &t)
{ 
  if(t == NULL)
     return 0;
  else
    return 1 + Nodes(t->LeftNode) + Nodes(t->RightNode);
}
//------------------------------------------------------------
template< class TreeEntry >
int BinarySearchTree<TreeEntry>::Leaves()
{  return Leaves(root);
}
//------------------------------------------------------------
template< class TreeEntry >
int BinarySearchTree<TreeEntry>::Leaves(TreePointer &t)
{  if(t == NULL)
     return 0;
   else
     if(t->LeftNode == NULL && t->RightNode == NULL)
        return 1;
     else
        return Leaves(t->LeftNode) + Leaves(t->RightNode);
}
//------------------------------------------------------------
template< class TreeEntry >
int BinarySearchTree<TreeEntry>::Height()
{  return Height(root);
}
//------------------------------------------------------------
template< class TreeEntry >
int BinarySearchTree<TreeEntry>::Height(TreePointer &t)
{ if(t == NULL)
     return -1;
  else
  {   int L,R;
      L = Height(t->LeftNode);
      R = Height(t->RightNode);
      if(L>R) return L+1; else return R+1;
  }
}
//------------------------------------------------------------
template< class TreeEntry >
TreeEntry BinarySearchTree<TreeEntry>::Minimum()
{ TreePointer t=root;

  if(t == NULL)
  { cout << "Arvore vazia" << endl;
    abort();
  }
  while (t->LeftNode != NULL) 
    t = t->LeftNode; // procurar subarvore esquerda
  
  return t->Entry;
}
//------------------------------------------------------------
template< class TreeEntry >
TreeEntry BinarySearchTree<TreeEntry>::Maximum()
{ TreePointer t=root;

  if(t == NULL)
  { cout << "Arvore vazia" << endl;
    abort();
  }
  while (t->RightNode != NULL) 
    t = t->RightNode; // procurar subarvore direita
  
  return t->Entry;
}
//------------------------------------------------------------
template< class TreeEntry >
TreeEntry BinarySearchTree<TreeEntry>::SecondMinimum()
{ TreePointer t=root;
  TreePointer b=root;

  if(t == NULL)
  { cout << "Arvore vazia" << endl;
    abort();
  }
  
  if( Height(t) < 1)
  {	cout << "A Arvore nao tem dois valores" << endl;
  }
  else
  {
  	  
  	  while (t->LeftNode != NULL)
	  { b = t;
		t = t->LeftNode;
	  }
	  
	  //caso o minimo e folha
	  if(t->RightNode == NULL)
	  	return b->Entry;
	  	
	  else
	  {	 t = t->RightNode;
	  	 //caso subavore direita de t seja folha
	  	 if(t->LeftNode == NULL)
	  	   return t->Entry;
	  	 //caso subavore direita de t tenha altura > 0
	  	 else
	  	 { while(t->LeftNode!=NULL)
	  	   { t = t->LeftNode;
	  	   }
	  	   return t->Entry;
	  	 }
	  }

	  
	  
	  
	  
  }

}
//------------------------------------------------------------

#endif /* BSTREETEMPLATE_H */
