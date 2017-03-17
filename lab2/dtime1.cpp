// dtime1.cpp
// Driver para testar novo tipo de dados Time
#include <iostream>
#include "time1.h"
using namespace std;

int main(){
	Time dinnerTime;	// instanciar objeto dinnerTime da classe Time
	
	cout << "O horario inicial e ";
	dinnerTime.printMilitary();
	cout << " horario militar, \nque corresponde a ";
	dinnerTime.printStandard();
	cout << " horario padrao.\n\n";
	
	// atribuir valores validos
	dinnerTime.setTime(18,30,0);
	cout << "Jantar sera servido as ";
	dinnerTime.printMilitary();
	cout << " horario militar, \nque corresponde a ";
	dinnerTime.printStandard();
	cout << " horario padrao.\n\n";
	
	// tentativa de atribuir valores invalidos
	dinnerTime.setTime(99,99,99);
	cout << "Apos tentativa de atribuir valores invalidos ";
	dinnerTime.printMilitary();
	cout << " horario militar, \nque corresponde a ";
	dinnerTime.printStandard();
	cout << " horario padrao.\n\n";
	return 0;
}

