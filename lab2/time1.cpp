// time1.cpp
// Definicao dos Metodos para objeto Time.
#include <iostream>
#include "time2.h"
using namespace std;

int main(){
	Time dinnerTime;	// instanciar objeto dinnerTime da classe Time
	
	cout << "O horario inicial e ";
	dinnerTime.printMilitary();
	cout << " horario militar, \nque corresponde a ";
	dinnerTime.printStandard();
	cout << " horario padrao.\n\n";
	
	// atribuir valores validos
	dinnerTime.setTime(23,58,0);
	cout << "Jantar sera servido as ";
	dinnerTime.printMilitary();
	cout << " horario militar, \nque corresponde a ";
	dinnerTime.printStandard();
	cout << " horario padrao.\n\n";
	
	for(int i=0;i<200;i++){
		dinnerTime.tick();
		dinnerTime.printMilitary();
		cout << endl;
	}
	return 0;
}


Time::Time()
// Pre: Nenhuma
// Pos: Construtor Time inicia cada elemento de dados em zero,
//assegurando que todos os objetos Time iniciem num estado consistente.
{
	hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s)
// Pre: Valores validos para hora (h), minuto (m) e segundo (s) sejam fornecidos.
// Pos: Atribui novos valores de hora (24 horas).
//Verificacao da validade dos valores fornecidos.
//Atribui zero aos valores invalidos (estado consistente).
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printMilitary()
// Pre: Nenhuma.
// Pos: Horario no formato 24 horas e' impresso.
{
	cout << (hour < 10 ? "0" : "") << hour << ":"
		 << (minute < 10 ? "0" : "") << minute << ":"
		 << (second < 10 ? "0" : "") << second;
}

void Time::printStandard()
// Pre: Nenhuma.
// Pos: Horario no formato 12 horas (AM/PM) e' impresso.
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
		 << ":" << (minute < 10 ? "0" : "") << minute
		 << ":" << (second < 10 ? "0" : "") << second
		 << (hour < 12 ? " AM" : " PM");
}

void Time::tick()
// Pre: Nenhuma.
// Pos: 
{
	second++;
	if(second >=60){
		minute++;
		second = 0;
		if(minute >=60){
			hour++;
			minute = 0;
			if(hour >=24){
				hour = 0;
			}
		}
	}
}

void Time::reverseTick()
// Pre: Nenhuma.
// Pos: 
{
	second--;
	if(second -1){
		minute++;
		second = 0;
		if(minute >=60){
			hour++;
			minute = 0;
			if(hour >=24){
				hour = 0;
			}
		}
	}
}


