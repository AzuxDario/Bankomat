#include "ckasetapieniedzy.h"

CKasetaPieniedzy::CKasetaPieniedzy()
{
    wartoscNominalow = {200,100,50,20,10,5,2,1};
    odczytajKasete();
}

CKasetaPieniedzy::~CKasetaPieniedzy()
{
    zapiszKasete();
}

//--------Gettery--------//
QVector<int> CKasetaPieniedzy::zwrocIloscNominalow()
{
    odczytajKasete();
    return iloscNominalow;
}

QVector<int> CKasetaPieniedzy::zwrocWartoscNominalow()
{
    return wartoscNominalow;
}

//--------Settery--------//
void CKasetaPieniedzy::ustawIloscNominalow(QVector<int> wartosc)
{
    iloscNominalow = wartosc;
    zapiszKasete();
}

void CKasetaPieniedzy::dodajGotowki(QVector<int> wartosc)
{
    for(int i = 0; i < iloscNominalow.count(); i++)
    {
        iloscNominalow[i] += wartosc[i];
    }
    zapiszKasete();
}

//----Odczytuje informacje o ilości pieniędzy z dysku----//
void CKasetaPieniedzy::odczytajKasete()
{
    iloscNominalow.clear();
    QFile plikKasety("money.mon");
    if(plikKasety.open(QIODevice::ReadOnly))
    {
        QTextStream zawartoscPliku(&plikKasety);
        iloscNominalow.push_back(zawartoscPliku.readLine().toInt());
        iloscNominalow.push_back(zawartoscPliku.readLine().toInt());
        iloscNominalow.push_back(zawartoscPliku.readLine().toInt());
        iloscNominalow.push_back(zawartoscPliku.readLine().toInt());
        iloscNominalow.push_back(zawartoscPliku.readLine().toInt());
        iloscNominalow.push_back(zawartoscPliku.readLine().toInt());
        iloscNominalow.push_back(zawartoscPliku.readLine().toInt());
        iloscNominalow.push_back(zawartoscPliku.readLine().toInt());
        plikKasety.close();
    }
}

//----Zapisuje informację o ilości pieniędzy na dysk----//
void CKasetaPieniedzy::zapiszKasete()
{
    QFile plikKasety("money.mon");
    if(plikKasety.open(QIODevice::WriteOnly))
    {
        QTextStream zawartoscPliku(&plikKasety);
        zawartoscPliku << iloscNominalow[0] << endl;
        zawartoscPliku << iloscNominalow[1] << endl;
        zawartoscPliku << iloscNominalow[2] << endl;
        zawartoscPliku << iloscNominalow[3] << endl;
        zawartoscPliku << iloscNominalow[4] << endl;
        zawartoscPliku << iloscNominalow[5] << endl;
        zawartoscPliku << iloscNominalow[6] << endl;
        zawartoscPliku << iloscNominalow[7];
        plikKasety.close();
    }
}
