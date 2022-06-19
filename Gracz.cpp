#include <fstream>
#include "Gracz.h"
#include <string>

Gracz::Gracz(string _nazwa, int _poziomTrudnosci)
{
	nazwa = _nazwa;
	poziomTrudnosci = _poziomTrudnosci;
	atak = 5;
	obrona = 5;
	maksZdrowie = aktualneZdrowie = 100;
	poziom = 1;
	doswiadczenie = 0;
	//przedmiotOfensywny = NULL;
	//przedmiotDefensywny = NULL;
	przedmiotOfensywny = new Przedmiot("Olisadebe", 15);
	przedmiotDefensywny = new Przedmiot("Baba noga", 33);
}

Gracz::Gracz()
{
	ifstream plik("save.txt");

	getline(plik, nazwa);
	plik >> aktualneZdrowie;
	plik >> maksZdrowie;
	plik >> poziom;
	plik >> doswiadczenie;
	plik >> atak;
	plik >> obrona;
	plik >> poziomTrudnosci;

	string przedmiotNazwa = "0";
	int przedmiotBonus = 0;

	plik.seekg(0, ios::beg);
	for (int x = 0; getline(plik, przedmiotNazwa) && x < 9; x++)
	{
		if (x == 8)
		{
			plik >> przedmiotBonus;
			if (przedmiotNazwa != "0")
			{
				przedmiotOfensywny = new Przedmiot(przedmiotNazwa, przedmiotBonus);
			}
			else
			{
				przedmiotOfensywny = NULL;
			}
		}
	}

	plik.seekg(0, ios::beg);
	for (int x = 0; getline(plik, przedmiotNazwa) && x < 11; x++)
	{
		if (x == 10)
		{
			plik >> przedmiotBonus;
			if (przedmiotNazwa != "0")
			{
				przedmiotDefensywny = new Przedmiot(przedmiotNazwa, przedmiotBonus);
			}
			else
			{
				przedmiotDefensywny = NULL;
			}
		}
	}

	plik.close();
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
	ofstream plik("save.txt");
	if (plik.is_open())
	{
		plik << nazwa << endl;
		plik << aktualneZdrowie << endl;
		plik << maksZdrowie << endl;
		plik << poziom << endl;
		plik << doswiadczenie << endl;
		plik << atak << endl;
		plik << obrona << endl;
		plik << poziomTrudnosci << endl;

		if (przedmiotOfensywny != NULL)
		{
			plik << przedmiotOfensywny->dostanNazwe() << endl;
			plik << przedmiotOfensywny->dostanWartoscBonusu() << endl;
		}
		else
		{
			plik << 0 << endl;
			plik << 0 << endl;
		}

		if (przedmiotDefensywny != NULL)
		{
			plik << przedmiotDefensywny->dostanNazwe() << endl;
			plik << przedmiotDefensywny->dostanWartoscBonusu();
		}
		else
		{
			plik << 0 << endl;
			plik << 0;
		}
		
		if (plik.good())
		{
			plik.close();
			return true;
		}
		else
		{
			plik.close();
			return false;
		}
	}
	else
	{
		return false;
	}
}