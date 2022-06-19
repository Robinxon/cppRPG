#include "Przedmiot.h"

Przedmiot::Przedmiot(string _nazwa, int _wartoscBonusu)
{
	nazwa = _nazwa;
	wartoscBonusu = _wartoscBonusu;
}

string Przedmiot::dostanNazwe()
{
	return nazwa;
}

int Przedmiot::dostanWartoscBonusu()
{
	return wartoscBonusu;
}