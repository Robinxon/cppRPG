#include "Przeciwnik.h"

Przeciwnik::Przeciwnik(string _nazwa, int _atak, int _obrona, int _zdrowie, int _poziom)
{
	nazwa = _nazwa;
	atak = _atak;
	obrona = _obrona;
	aktualneZdrowie = maksZdrowie = _zdrowie;
	poziom = _poziom;
}