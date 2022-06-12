#include <iostream>
#include <string>
#include <locale.h>
#include "Gracz.h"
using namespace std;

void menuGlowne();
void nowaGra();
void prolog();

Gracz* gracz = NULL;

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
}

void prolog()
{
    system("CLS");
    cout << "Za górami, za lasami, nasz bohater postanowił wejść do starego zamczyska zwanego SESJA." << endl;
    cout << "Ciekawe co będzie na niego tam czychać..." << endl;
    cout << endl;
    system("pause");
}