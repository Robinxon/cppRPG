#include <iostream>
#include "Postac.h"
#include "Gracz.h"
using namespace std;

void menuGlowne()
{
    //zapis ciągu znaków w postaci R"(ciąg znaków)" nie wymaga używania znaku ucieczki
    cout << R"(                    ____________________  ________ )" << endl;
    cout << R"(  ____ ______ ______\______   \______   \/  _____/ )" << endl;
    cout << R"(_/ ___\\____ \\____ \|       _/|     ___/   \  ___ )" << endl;
    cout << R"(\  \___|  |_> >  |_> >    |   \|    |   \    \_\  \)" << endl;
    cout << R"( \___  >   __/|   __/|____|_  /|____|    \______  /)" << endl;
    cout << R"(     \/|__|   |__|          \/                  \/ )" << endl;
}

int main()
{
    menuGlowne();

    Gracz gracz = Gracz("Robert");
    cout << "Gracz: " << gracz.dostanNazwa() << endl;
    
    return 0;
}