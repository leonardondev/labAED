#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "BSTreeTemplate.h"
using namespace std;

int main()
{ 
	BinarySearchTree<string> t;
	string s;
	ifstream ent("mam.txt");
	ofstream saida("saida-mam.txt");

	while(ent >> s)
	{
		t.SearchInsert(s);
	}
	ent.close();
	
	saida << "Escrever as informações solicitadas..." << endl;
	cout << "Arvore Final" << endl;
	cout << "Altura: " << t.Height() << endl;
	cout << "Nro de folhas: " << t.Leaves() << endl;
	cout << "Nro de nos: " << t.Nodes() << endl;
	
	
	cout << "--------------------------------------------" << endl;
	t.Print();
	cout << "--------------------------------------------" << endl;
	saida.close();
	cin >> s;
	return 0;
}


