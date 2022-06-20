#pragma once
#include <iostream>
using namespace std;

class Postac
{
protected:
	string nazwa;
	int maksZdrowie;
	int aktualneZdrowie;
	int poziom;
	int poziomTrudnosci;
	int atak;
	int obrona;

public:
	string dostanNazwa();
	
	int dostanMaksZdrowie();

	int dostanAktualneZdrowie();

	int dostanPoziom();

	int dostanPoziomTrudnosci();

	int dostanAtak();

	int dostanObrone();

	void otrzymajObrazenia(int _obrazenia);
};

