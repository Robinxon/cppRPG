#include "Gracz.h"

Gracz::Gracz(string _nazwa, int _poziomTrudnosci)
{
	nazwa = _nazwa;
	poziomTrudnosci = _poziomTrudnosci;
	atak = 5;
	obrona = 5;
	maksZdrowie = aktualneZdrowie = 100;
	poziom = 1;
	doswiadczenie = 0;
	przedmiotOfensywny = NULL;
	przedmiotDefensywny = NULL;
}

int Gracz::dostanDoswiadczenie()
{
	return doswiadczenie;
}

Przedmiot* Gracz::dostanPrzedmiotOfensywny()
{
	return przedmiotOfensywny;
}

Przedmiot* Gracz::dostanPrzedmiotDefensywny()
{
	return przedmiotDefensywny;
}

int Gracz::dostanAtak()
{
	if (przedmiotOfensywny == NULL)
	{
		return atak;
	}
	else
	{
		int wartosc = atak + przedmiotOfensywny->dostanWartoscBonusu();
		return wartosc;
	}
}

int Gracz::dostanObrone()
{
	if (przedmiotDefensywny == NULL)
	{
		return obrona;
	}
	else
	{
		int wartosc = obrona + przedmiotDefensywny->dostanWartoscBonusu();
		return wartosc;
	}
}