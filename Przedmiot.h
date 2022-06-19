#pragma once
#include <iostream>
using namespace std;

class Przedmiot
{
private:
	string nazwa;
	int wartoscBonusu;

public:
	string dostanNazwe();
	int dostanWartoscBonusu();
};

