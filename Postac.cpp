#include "Postac.h"

void Postac::ustawNazwa(string _nazwa)
{
	nazwa = _nazwa;
}

string Postac::dostanNazwa()
{
	return nazwa;
}

void Postac::ustawPoziomTrudnosci(int _poziomTrudnosci)
{
	poziomTrudnosci = _poziomTrudnosci;
}