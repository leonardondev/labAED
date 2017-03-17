// time1.h
// Declaracao do objeto Time.
// Métodos definidos em time.cpp

// Não incluir header multiplas vezes
#ifndef TIME1_H
#define TIME1_H

// Definicao do tipo abstrato de dados Time
class Time{
	public:
		Time();							//construtor default
		void setTime(int, int, int);	//set hour, minute e second
		void printMilitary();			//imprime hora em formato militar
		void printStandard();			//imprime hora em formato padrao
	private:
		int hour;						// 0 - 23
		int minute;						// 0 - 59
		int second;						// 0 - 59
};

#endif

