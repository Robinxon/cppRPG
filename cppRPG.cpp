#include <iostream>
#include "Gracz.h"
using namespace std;

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
        cout << "2. Wczytaj gre" << endl;
        cout << "9. Wyjdz z gry" << endl;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            //nowa gra
            break;
        case 2:
            //wczytaj gre
            break;
        default:
            break;
        }
    } while (wybor != 9);
}

int main()
{
    menuGlowne();

    Gracz gracz = Gracz("Robert");
    
    return 0;
}