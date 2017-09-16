// sumafile.cpp -- funkcje maj�ce tablic� za parametr
#include <iostream>
#include <fstream>          // wej�cie-wyj�cie przez pliki
#include <cstdlib>          // funkcja exit()
const int SIZE = 60;
int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;        // obiekt obs�uguj�cy odczyt z pliku

    cout << "Podaj nazw� pliku z danymi: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);  // po��czenie inFile z plikiem
    if (!inFile.is_open())  // nieudana pr�ba otwarcia pliku
    {
        cout << "Otwarcie pliku " << filename << " nie powiod�o si�.\n";
        cout << "Program zostanie zako�czony.\n";
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;          // liczba element�w do odczytu

    inFile >> value;        // pobierz pierwsz� warto��
    while (inFile.good())   // p�ki dobre dane i nie EOF
    {
        ++count;            // wczytano kolejn� dan�
        sum += value;       // obliczenie bie��cej sumy
        inFile >> value;    // pobranie nast�pnej warto�ci
    }
    if (inFile.eof())
        cout << "Koniec pliku.\n";
    else if (inFile.fail())
        cout << "Wczytywanie danych przerwane - b��d.\n";
    else
        cout << "Wczytywanie danych przerwane, przyczyna nieznana.\n";
    if (count == 0)
        cout << "Nie przetworzono �adnych danych.\n";
    else
    {
        cout << "Wczytanych element�w: " << count << endl;
        cout << "Suma: " << sum << endl;
        cout << "�rednia: " << sum / count << endl;
    }
    inFile.close();         // plik ju� niepotrzebny
    return 0;
}
