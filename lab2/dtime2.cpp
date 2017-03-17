// dtime2.cpp
// Driver para mostrar acesso aos elementos do tipo de dados Time
#include <iostream>
#include "time1.h"
using namespace std;

int main()
{ Time t;

	t.hour = 7;
	cout << "minuto = " << t.minute << endl;
	return 0;
}
