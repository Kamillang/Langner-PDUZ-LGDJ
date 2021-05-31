#include "Tablica2D.h"
#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;
int const MAX = 20;

Tab2D::Tab2D(int m, int n) {

    wiersz = m;
    kolumna = n;

    tablica2D = new int* [wiersz];
    for (int i = 0; i < wiersz; i++)
        tablica2D[i] = new int[kolumna];


    drugaTablica = new int* [wiersz];
    for (int i = 0; i < wiersz; i++)
        drugaTablica[i] = new int[kolumna];


    dodatkowaTablica = new int* [wiersz];
    for (int i = 0; i < wiersz; i++)
        dodatkowaTablica[i] = new int[kolumna];

}

void Tab2D::generate(int z) {
    zakres = z;
    int k = 0;

    for (int i = 0; i < wiersz; ++i) {
        for (int j = 0; j < kolumna; ++j) {

            int losowaLiczba = rand() % (2 * z + 1) + (-z);
            tablica2D[i][j] = losowaLiczba;
            dodatkowaTablica[i][j] = k;
            k++;

        }
    }

    k = 1;
    for (int i = 0; i < wiersz; ++i)
    {
        for (int j = 0; j < kolumna; ++j)
        {
            drugaTablica[i][j] = k;
            k++;


        }
    }

}

void Tab2D::simplePrint()
{
    for (int i = 0; i < wiersz; ++i)
    {
        for (int j = 0; j < kolumna; ++j)
        {
            std::cout << tablica2D[i][j] << " ";
        }
        std::cout << "\n";
    }
    cout << "\n";
}

void Tab2D::indexedPrint()
{
    int licznik = 0;
    if (licznik == 0)
    {
        dodatkowaTablica = tablica2D;
    }
    if (licznik > 1)
    {
        dodatkowaTablica = drugaTablica;
    }

    int spacja = to_string(wiersz).size();
    int ujemna = to_string(zakres).size() + 1;

    for (int i = 0; i < kolumna; i++)
    {
        if (i == 0)
        {
            int zerowa = (spacja + 1) + ujemna;
            cout << setw(zerowa) << i;
        }
        else
        {
            cout << setw(static_cast<std::streamsize>(ujemna) + 1) << i;
        }
    }
    cout << "\n";
    cout << setw(static_cast<std::streamsize>(spacja) + 1) << "+";
    for (int i = 0; i <= kolumna; i++)
    {
        cout << "----";
    }
    cout << "\n";

    for (int i = 0; i < wiersz; i++)
    {
        cout << setw(spacja) << i << "|";
        for (int j = 0; j < kolumna; j++)
        {
            cout << setw(ujemna) << dodatkowaTablica[i][j] << " ";

        }
        cout << "\n";

    }
    cout << "\n";
    licznik++;
}

void Tab2D::scanPDUZ()
{
    int x = wiersz - 1;
    int y = kolumna - 1;
    bool granica = true;
    bool next;
    int gora = 0;
    int dol = wiersz - 1;
    int prawa = kolumna - 1;
    int lewa = 0;
    int** trzecia = tablica2D;

    for (int i = 0; i < wiersz; i++)
    {
        for (int j = 0; j < kolumna; j++)
        {
            next = true;
            if (x == 0 && y == 0)
            {
                next = false;
            }
            while (granica && next)
            {
                if (x == gora && y == prawa)
                {
                    if (wiersz % 2 == 0)
                    {
                        trzecia[x][y] = drugaTablica[i][j];
                        x++;
                        y--;
                    }
                    else
                    {
                        trzecia[x][y] = drugaTablica[i][j];
                        y--;
                    }
                    next = false;
                    granica = !granica;
                    break;
                }

                if (x > gora && y <= prawa)
                {
                    if (y == prawa)
                    {
                        trzecia[x][y] = drugaTablica[i][j];
                        x--;
                        next = false;
                        granica = !granica;
                    }
                    else
                    {
                        trzecia[x][y] = drugaTablica[i][j];
                        x--;
                        y++;
                        next = false;
                    }
                    break;
                }

                if (x == gora && y > lewa)
                {
                    trzecia[x][y] = drugaTablica[i][j];
                    y--;
                    next = false;
                    granica = !granica;
                    break;
                }
            }
            while (!granica && next)
            {
                if (x == dol && y == lewa)
                {
                    if (kolumna % 2 == 0)
                    {
                        trzecia[x][y] = drugaTablica[i][j];
                        x--;
                    }
                    else
                    {
                        trzecia[x][y] = drugaTablica[i][j];
                        x--;
                        y++;
                    }
                    granica = !granica;
                    next = false;
                    break;
                }
                if (x < dol && y > lewa)
                {
                    trzecia[x][y] = drugaTablica[i][j];
                    x++;
                    y--;
                    next = false;
                    break;
                }
                if (x < dol && y == lewa)
                {
                    trzecia[x][y] = drugaTablica[i][j];
                    x--;
                    granica = !granica;
                    next = false;
                    break;
                }
                if (x == dol && y > lewa)
                {                  
                    trzecia[x][y] = drugaTablica[i][j];
                    y--;
                    next = false;
                    granica = !granica;
                    break;
                }
            }
            if (x == 0 && y == 0 && i == wiersz - 1 && j == kolumna - 1)
            {
                trzecia[x][y] = drugaTablica[i][j];
            }
        }
    }
    drugaTablica = trzecia;

}

//void Tab2D::scanLGDJ()
//{
//    
//    int x = 0;
//    int y = 0;
//    bool granica = true;
//    bool next;
//    int gora = 0;
//    int dol = wiersz - 1;
//    int prawa = kolumna - 1;
//    int lewa = 0;
//    int** dodatkowaTablica = tablica2D;
//
//    for (int i = 0; i < wiersz; i++)
//    {
//        for (int j = 0; j < kolumna; j++)
//        {
//            next = true;
//            /*if (x == 0 && y == 0)
//            {
//                next = false;
//            }*/
//            while ( next)
//            {
//                if (x == gora && y == lewa)
//                {
//                    dodatkowaTablica[x][y] = drugaTablica[i][j];
//                    y++;
//                    next = false;
//                    break;
//
//                }
//                if (x == gora && y > lewa)
//                {
//                    dodatkowaTablica[x][y] = drugaTablica[i][j];
//                    x++;
//                    y--;
//                    next = false;
//                    break;
//                }
//                if (x > gora && y == lewa)
//                {
//                    dodatkowaTablica[x][y] = drugaTablica[i][j];
//                    x = 0;
//                    y = 2;
//                    
//                    next = false;
//                    break;
//                }
//                if (x > gora && y > lewa)
//                {
//                    dodatkowaTablica[x][y] = drugaTablica[i][j];
//                    x++;
//                    y--;
//                    next = false;
//                    break;
//
//                }
//                if (x > gora && y == prawa)
//                {
//                    dodatkowaTablica[x][y] = drugaTablica[i][j];
//                    x++;
//                    y--;
//                    next = false;
//                    break;
//                }
//                if (x == dol && y < prawa)
//                {
//                    if (kolumna <= 3)
//                    {
//                        dodatkowaTablica[x][y] = drugaTablica[i][j];
//                        x = 2;
//                        y = 2;
//                        next = false;
//                        break;
//                    }
//                    else
//                    {
//                        dodatkowaTablica[x][y] = drugaTablica[i][j];
//                        x = 0;
//                        y = 3;
//                        next = false;
//                        break;
//
//                    }
//                }
//                if (x == gora && y == prawa)
//                {
//                    dodatkowaTablica[x][y] = drugaTablica[i][j];
//                    x++;
//                    y--;
//                    next = false;
//                    break;
//
//                }
//                if (x ==dol && y == lewa)
//                {
//
//                   if (kolumna <= 3)
//                   {
//                            dodatkowaTablica[x][y] = drugaTablica[i][j];
//                            x = 1;
//                            y = prawa;
//                            next = false;
//                            break;
//                   }
//                   else
//                   {
//                            dodatkowaTablica[x][y] = drugaTablica[i][j];
//                            x = 0;
//                            y = 3;
//                            next = false;
//                            break;
//                   }
//
//                }
//                
//            }
//           
//            if (x == dol && y == prawa )
//            {
//                dodatkowaTablica[x][y] = drugaTablica[i][j];
//            }
//        }
//    }
//    drugaTablica ;
//
//}

    

   
   


