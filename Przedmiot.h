#pragma once
#include <iostream>
using namespace std;

class Przedmiot
{
private:
	string nazwa;
	int wartoscBonusu;

public:
	Przedmiot(string _nazwa, int _wartoscBonusu);
	string dostanNazwe();
	int dostanWartoscBonusu();
};

