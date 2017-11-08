#include "cwyplacacz.h"

CWyplacacz::CWyplacacz(CKasetaPieniedzy *kaseta)
{
    this->kaseta = kaseta;
    poziomyNominalow[0] = 800;
    poziomyNominalow[1] = 600;
    poziomyNominalow[2] = 400;
    poziomyNominalow[4] = 300;
    poziomyNominalow[5] = 200;
    poziomyNominalow[6] = 150;
    poziomyNominalow[7] = 100;
    poziomyNominalow[8] = 50;
    poziomyNominalow[9] = 0;
}

//--------Gettery--------//
QVector<int> CWyplacacz::zwrocOstatniaWyplate()
{
    return ostatniaWyplata;
}

//----Sprawdza czy w bankomacie jest wystarczająca ilośc gotówki----//
bool CWyplacacz::czyWystarczyGotowki()
{
    QVector<int> gotowka = kaseta->zwrocIloscNominalow();
    for(int i = 0; i < gotowka.count(); i++)
    {
        if(gotowka[i] < 10)
        {
            return false;
        }
    }
    return true;
}

//----Inicjuje wypłątę z konta sprawdzając czy stan konta jest wystarczający----//
CWyplacacz::WynikWyplaty CWyplacacz::dokonajWyplaty(Account *konto, int kwota)
{
    if(konto->getBalance() >= kwota)
    {
        wyplacPieniadze(kwota);
        konto->withdraw(kwota);
        return CWyplacacz::wyplaconoPieniadze;
    }
    else
    {
        return CWyplacacz::brakSrodkow;
    }
}

//----Wyznacza jakimi nominałami wyznaczyć pieniądze z konta----//
void CWyplacacz::wyplacPieniadze(int kwota)
{
    int pozostalaKwota = kwota;
    QVector<int> iloscPieniedzy = kaseta->zwrocIloscNominalow(); //Pobieramy ilosc banknotow z kasety
    QVector<int> wartoscPieniedzy = kaseta->zwrocWartoscNominalow(); //Pobieramy wartosc nominalow z kasety
    QVector<int> banknotyDoWyplacenia = {0,0,0,0,0,0,0,0}; //Wynikowy wektor banknotow do wyplacenia
    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < iloscPieniedzy.count(); i++) //Petla przechodzaca po wszystkich nominalach
        {
            while(iloscPieniedzy[i] > poziomyNominalow[j]) //Wypłać najpierw nominałami, których poziom jest wysoki
            {
                if(pozostalaKwota == 0) //Jeżeli pozostała do wypłacenia kwota jest równa zero to zakończ pętle
                {
                    kaseta->ustawIloscNominalow(iloscPieniedzy); //Zwracamy kasecie pozostala ilosc nominalow po wyplacie
                    ostatniaWyplata.clear();
                    ostatniaWyplata = banknotyDoWyplacenia; //Przypisujemy wynik
                    return;
                }
                if(wartoscPieniedzy[i] > pozostalaKwota) //Jeżeli nominał jest zbyt duży kończymy pętle while
                {
                    break;
                }
                if(pozostalaKwota - wartoscPieniedzy[i] >= 0) //Jeżeli można wypłacić danym banknotem to dodajemy go do wektora wynikowego
                {
                    pozostalaKwota -= wartoscPieniedzy[i];
                    banknotyDoWyplacenia[i]++;
                    iloscPieniedzy[i]--;
                }
            }
        }
    }
}
