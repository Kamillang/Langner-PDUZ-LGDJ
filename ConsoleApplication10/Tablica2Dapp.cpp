// Tablica_2D.cpp : Ten plik zawiera funkcj� �main�. W nim rozpoczyna si� i ko�czy wykonywanie programu.
//

#include "Tablica2D.h"
#include <iostream>
// #include "..\Tablica_2D\Tablica2D.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout << "Generacja tablic wg parametr�w u�ytkownika.\n";
    cout << "Parametry m n z oznaczaj� odpowiednio:\n";
    cout << "liczb� wierszy, kolumn, zakres generacji [-z..z).\n";
    cout << "Dowolny parametr <= 0 powoduje koniec programu.\n\n";
    while (true) { 
        int m, n, z;
        cout << "m n z = "; cin >> m >> n >> z;
        if (!cin || m <= 0 || n <= 0 || z <= 0) break;
        Tab2D T(m, n);
        T.generate(z);
        cout << "\nTablica bez wyr�wnania kolumn\n\n";

        T.simplePrint();
        cout << "Tablica z indeksowaniem\n\n";

        T.indexedPrint();
        cout << "Tablica ze skanowaniem PDUZ\n\n";

        T.scanPDUZ();
        T.indexedPrint();

        cout << "Tablica ze skanowaniem LGDJ\n\n"; 
       /* T.scanLGDJ();
        T.indexedPrint();*/
    }
    if (!cin) cout << "\nB��d w danych\n";
    cout << "\nKoniec programu\n";
    return 0;
}

