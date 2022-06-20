#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>
#include "Gracz.h"
#include "Przeciwnik.h"
using namespace std;

void pauzaSystemowa();
void menuGlowne();
void nowaGra();
void prolog();
void menuGry();
void wypiszStatystykiGracza();
void wypiszStatystykiPrzedmiotu(Przedmiot *_przedmiot);
void wczytajGre(string *_wiadomosc);
bool czyZapisIstnieje();
void losujWydarzenie(string *_wiadomosc);
void wydarzenieNic();
void wydarzeniePrzedmiot(string* _wiadomosc);

Gracz* gracz = NULL;
Przeciwnik* przeciwnik = NULL;

int main()
{
    setlocale(LC_CTYPE, "Polish");
    srand(time(NULL));

    menuGlowne();

    delete gracz;
    return 0;
}

void pauzaSystemowa()
{
    cout << "Wciśnij dowolny klawisz, aby kontynuować..." << endl;
    system("pause>nul");
}

void menuGlowne()
{
    string wiadomosc = "";
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
        if (wiadomosc != "")
        {
            cout << wiadomosc << endl;
            cout << endl;
            wiadomosc = "";
        }
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
            wczytajGre(&wiadomosc);
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
    pauzaSystemowa();
}

void menuGry()
{
    string wiadomosc = "";
    int wybor = 0;
    do
    {
        system("CLS");
        wypiszStatystykiGracza();
        cout << endl;
        if (wiadomosc != "")
        {
            cout << wiadomosc << endl;
            cout << endl;
            wiadomosc = "";
        }
        cout << "Co chcesz teraz zrobić?" << endl;
        cout << "1. Idź dalej" << endl;
        cout << "2. Zapisz grę" << endl;
        cout << "9. Wyjdź do menu" << endl;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            system("CLS");
            cout << "Wędrujesz w nieznane..." << endl;
            losujWydarzenie(&wiadomosc);
            pauzaSystemowa();
            break;
        case 2:
            if (gracz->zapisz())
            {
                wiadomosc = "Gra zapisana pomyślnie!";
            }
            else
            {
                wiadomosc = "Nie udało się zapisać gry!";
            }
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

void wczytajGre(string *_wiadomosc)
{
    if(czyZapisIstnieje())
    {
        gracz = new Gracz();
        menuGry();
    }
    else
    {
        *_wiadomosc = "Nie udało się wczytać gry!";
    }
    
}

bool czyZapisIstnieje()
{
    ifstream plik("save.txt");
    return plik.good();
}

void losujWydarzenie(string *_wiadomosc)
{
    int r = rand() % 100;
    if (r < 20)
    {
        wydarzenieNic();
    }
    else if (r < 40)
    {
        wydarzeniePrzedmiot(_wiadomosc);
    }
    else if (r < 90)
    {
        //wydarzenie przeciwnik
    }
    else
    {
        //wydarzenie boss
    }
}

void wydarzenieNic()
{
    int r = rand() % 100;
    if (r < 20)
    {
        cout << "Nic nie znajdujesz." << endl;
    }
    else if (r < 40)
    {
        cout << "Dochodzisz do opuszczonego domu, w którym nie znajdujesz nic przydatnego." << endl;
    }
    else if (r < 60)
    {
        cout << "W oddali widzisz postać, która ucieka w mrok jak tylko cię zobaczyła." << endl;
    }
    else if (r < 80)
    {
        cout << "Na ziemi widzisz coś błyszczącego, lewcz niestety to tylko bezwartościowy kawałek szkła." << endl;
    }
    else
    {
        cout << "Burczy ci w brzuchu, lecz niestety w zasięgu wzroku nie ma nic do jedzenia." << endl;
    }
}

void wydarzeniePrzedmiot(string *_wiadomosc)
{
    string nazwa;
    int bonus;
    bool czyOfensywny;

    int r = rand() % 100;
    if (r < 20)
    {
        nazwa = "Sztylet";
        bonus = (rand() % 10) + 1;
        czyOfensywny = true;
    }
    else if (r < 40)
    {
        nazwa = "Miecz";
        bonus = (rand() % 10) + 6;
        czyOfensywny = true;
    }
    else if (r < 50)
    {
        nazwa = "Topór";
        bonus = (rand() % 10) + 11;
        czyOfensywny = true;
    }
    else if (r < 70)
    {
        nazwa = "Tarcza";
        bonus = (rand() % 10) + 1;
        czyOfensywny = false;
    }
    else if (r < 90)
    {
        nazwa = "Amulet";
        bonus = (rand() % 10) + 6;
        czyOfensywny = false;
    }
    else
    {
        nazwa = "Zbroja";
        bonus = (rand() % 10) + 11;
        czyOfensywny = false;
    }

    int wybor = 0;
    do
    {
        cout << "Znajdujesz przedmiot: " << nazwa << " +" << bonus << " do punktów ";
        if (czyOfensywny)
        {
            cout << "ataku." << endl;
        }
        else
        {
            cout << "obrony." << endl;
        }
        cout << "Obecny przedmiot:" << endl;
        if (czyOfensywny)
        {
            wypiszStatystykiPrzedmiotu(gracz->dostanPrzedmiotOfensywny());
        }
        else
        {
            wypiszStatystykiPrzedmiotu(gracz->dostanPrzedmiotDefensywny());
        }
        cout << "Czy chcesz się w niego wyposażyć?" << endl;
        cout << "1. Tak" << endl;
        cout << "2. Nie" << endl;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            if (czyOfensywny)
            {
                gracz->ustawPrzedmiotOfensywny(nazwa, bonus);
            }
            else
            {
                gracz->ustawPrzedmiotDefensywny(nazwa, bonus);
            }
            *_wiadomosc = "Wyposażyłeś się w nowy przedmiot!";
            break;
        case 2:
            *_wiadomosc = "Zostawiłeś przedmiot tam gdzie leżał!";
            break;
        default:
            break;
        }
    } while (wybor != 1 && wybor != 2);
}