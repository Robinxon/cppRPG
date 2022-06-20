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
	void ustawPrzedmiotOfensywny(string _nazwa, int _wartoscBonusu);

	Przedmiot* dostanPrzedmiotDefensywny();
	void ustawPrzedmiotDefensywny(string _nazwa, int _wartoscBonusu);

	int dostanAtak();

	int dostanObrone();

	bool zapisz();
};

