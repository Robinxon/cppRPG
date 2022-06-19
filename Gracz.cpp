#include <fstream>
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

bool Gracz::zapisz()
{
	ofstream file("save.txt");
	if (file.is_open())
	{
		file << nazwa << endl;
		file << aktualneZdrowie << endl;
		file << maksZdrowie << endl;
		file << poziom << endl;
		file << doswiadczenie << endl;
		file << atak << endl;
		file << obrona << endl;
		file << poziomTrudnosci << endl;

		if (przedmiotOfensywny != NULL)
		{
			file << przedmiotOfensywny->dostanNazwe() << endl;
			file << przedmiotOfensywny->dostanWartoscBonusu() << endl;
		}
		else
		{
			file << 0 << endl;
			file << 0 << endl;
		}

		if (przedmiotDefensywny != NULL)
		{
			file << przedmiotDefensywny->dostanNazwe() << endl;
			file << przedmiotDefensywny->dostanWartoscBonusu();
		}
		else
		{
			file << 0 << endl;
			file << 0;
		}
		
		if (file.good())
		{
			file.close();
			return true;
		}
		else
		{
			file.close();
			return false;
		}
	}
	else
	{
		return false;
	}
}