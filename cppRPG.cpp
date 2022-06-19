#include <iostream>
#include <string>
#include <locale.h>
#include "Gracz.h"
#include "Przeciwnik.h"
using namespace std;

void menuGlowne();
void nowaGra();
void prolog();
void menuGry();
void wypiszStatystykiGracza();
void wypiszStatystykiPrzedmiotu(Przedmiot *_przedmiot);

Gracz* gracz = NULL;
Przeciwnik* przeciwnik = NULL;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    menuGlowne();

    delete gracz;
    return 0;
}

void menuGlowne()
{
    int wybor = 0;
    do
    {
        system("CLS");
        //zapis ciągu znaków w postaci R"(ciąg znaków)" nie wymaga używania znaku ucieczki
        cout << R"(                    ____________________  ________ )" << endl;
        cout << R"(  ____ ______ ______\______   \______   \/  _____/ )" << endl;
        cout << R"(_/ ___\\____ \\____ \|       _/|     ___/   \  ___ )" << endl;
        cout << R"(\  \___|  |_> >  |_> >    |   \|    |   \    \_\  \)" << endl;
        cout << R"( \___  >   __/|   __/|____|_  /|____|    \______  /)" << endl;
        cout << R"(     \/|__|   |__|          \/                  \/ )" << endl;
        cout << endl;
        cout << "1. Nowa gra" << endl;
        cout << "2. Wczytaj grę" << endl;
        cout << "9. Wyjdź z gry" << endl;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            nowaGra();
            break;
        case 2:
            //wczytaj gre
            break;
        default:
            break;
        }
    } while (wybor != 9);
}

void nowaGra()
{
    string nazwaGracza;

    system("CLS");
    cout << "Podaj nazwę gracza:" << endl;
    cin.ignore();
    getline(cin, nazwaGracza);

    int poziomTrudnosci = 0;
    do
    {
        cout << endl;
        cout << "Wybierz poziom trudnosci:" << endl;
        cout << "1. Łatwy" << endl;
        cout << "2. Normalny" << endl;
        cout << "3. Trudny" << endl;
        cin >> poziomTrudnosci;
    } while (poziomTrudnosci != 1 && poziomTrudnosci != 2 && poziomTrudnosci != 3);

    gracz = new Gracz(nazwaGracza, poziomTrudnosci);

    prolog();
    menuGry();
}

void prolog()
{
    system("CLS");
    cout << "Za górami, za lasami, nasz bohater postanowił wejść do starego zamczyska zwanego SESJA." << endl;
    cout << "Ciekawe co będzie na niego tam czychać..." << endl;
    cout << endl;
    system("pause");
}

void menuGry()
{
    int wybor = 0;
    do
    {
        system("CLS");
        wypiszStatystykiGracza();
        cout << endl;
        cout << "Co chcesz teraz zrobić?" << endl;
        cout << "1. Idź dalej" << endl;
        cout << "2. Zapisz grę" << endl;
        cout << "9. Wyjdź do menu" << endl;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            //losowe wydarzenie
            break;
        case 2:
            //zapisanie gry
            break;
        case 9:
            break;
        default:
            break;
        }
    } while (wybor != 9);
}

void wypiszStatystykiGracza()
{
    cout << gracz->dostanNazwa() << ": " << gracz->dostanAktualneZdrowie() << "/" << gracz->dostanMaksZdrowie() << endl;
    cout << "Poziom: " << gracz->dostanPoziom() << endl;
    cout << "Doświadczenie: " << gracz->dostanDoswiadczenie() << endl;
    cout << "Atak: " << gracz->dostanAtak() << endl;
    cout << "Obrona: " << gracz->dostanObrone() << endl;
    cout << endl;
    cout << "Przedmiot ofensywny:" << endl;
    wypiszStatystykiPrzedmiotu(gracz->dostanPrzedmiotOfensywny());
    cout << "Przedmiot defensywny:" << endl;
    wypiszStatystykiPrzedmiotu(gracz->dostanPrzedmiotDefensywny());
}

void wypiszStatystykiPrzedmiotu(Przedmiot *_przedmiot)
{
    if (_przedmiot != NULL)
    {
        cout << _przedmiot->dostanNazwe() << ": +" << _przedmiot->dostanWartoscBonusu() << endl;
    }
    else
    {
        cout << "-brak przedmiotu-" << endl;
    }
}