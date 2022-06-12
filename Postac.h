#pragma once
#include <iostream>
using namespace std;

class Postac
{
private:
	string nazwa;
	int maksZdrowie;
	int aktualneZdrowie;
	int poziom;
	int poziomTrudnosci;
	int atak;
	int obrona;

public:
	void ustawNazwa(string _nazwa);
	string dostanNazwa();
	void ustawPoziomTrudnosci(int _poziomTrudnosci);
};

