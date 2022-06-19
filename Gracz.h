#pragma once
#include "Postac.h"
#include "Przedmiot.h"

class Gracz : public Postac
{
private:
	int doswiadczenie;
	Przedmiot* przedmiotOfensywny;
	Przedmiot* przedmiotDefensywny;

public:
	Gracz(string _nazwa, int _poziomTrudnosci);
	Gracz();

	int dostanDoswiadczenie();

	Przedmiot* dostanPrzedmiotOfensywny();

	Przedmiot* dostanPrzedmiotDefensywny();

	int dostanAtak();

	int dostanObrone();

	bool zapisz();
};

