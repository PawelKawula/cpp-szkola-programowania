// error4.cpp -- uzywa klas wyjatkow
#include <iostream>
#include <cmath> // lub math.h; uzytkownicy systemu UNIX moga potrzebowac opcji -lm
#include "exc_mean.h"
// prototypy funkcji
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Podaj dwie liczby: ";
    while (cin >> x >> y)
    {
        try {      // poczatek bloku try
            z = hmean(x, y);
            cout << "Srednia harmoniczna liczb " << x << " i " << y
                << " wynosi " << z << endl;
            cout << "Srednia geometryczna liczb " << x << " i " << y
                << " wynosi " << gmean(x, y) << endl;
            cout << "Podaj kolejna pare liczb <w, aby wyjsc>: ";
        }   // koniec bloku try
        catch (bad_hmean & bg)   // poczatek bloku catch
        {
            cout << bg.what();
            cout << "Sprobuj ponownie.\n";
            continue;
        }
        catch (bad_gmean & hg)
        {
            cout << hg.what();
            cout << "Uzyte wartosci: " << hg.v1 << ", "
                << hg.v2 << endl;
            cout << "Niestety, to koniec zabawy.\n";
            break;
        } // koniec bloku catch
    }
    cout << "Koniec\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}

