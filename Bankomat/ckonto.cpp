#include "ckonto.h"

CKonto::CKonto()
{

}

CKonto::CKonto(QString numerKonta)
{
    this->numerKonta = numerKonta;
    odczytajKonto();
}

//--------Gettery--------//
QString CKonto::zwrocImie()
{
    return imie;
}

QString CKonto::zwrocNazwisko()
{
    return nazwisko;
}

QString CKonto::zwrocNumerKonta()
{
    return numerKonta;
}

double CKonto::zwrocStanKonta()
{
    return stanKonta;
}

//--------Settery--------//
void CKonto::ustawImie(QString noweImie)
{
    imie = noweImie;
}

void CKonto::ustawNazwisko(QString noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void CKonto::ustawNumerKonta(QString nowyNumerKonta)
{
    numerKonta = nowyNumerKonta;
}

void CKonto::ustawStanKonta(double nowyStanKonta)
{
    stanKonta = nowyStanKonta;
}

//----Pobiera kwotę z konta----//
void CKonto::odejmijZeStanuKonta(double kwota)
{
    stanKonta -= kwota;
    zapiszKonto();
}

//----Odczytuje plik konta z dysku----//
bool CKonto::odczytajKonto()
{
    QString sciezka = "";
    QFile plikKonta(sciezka + "accounts" + QDir::separator() + numerKonta + ".acc");
    if(numerKonta.isNull() == false)
    {
        if(plikKonta.open(QIODevice::ReadOnly))
        {
            QTextStream zawartoscPliku(&plikKonta);
            imie = zawartoscPliku.readLine();
            nazwisko = zawartoscPliku.readLine();
            stanKonta = zawartoscPliku.readLine().toDouble();
            plikKonta.close();
        }
        return true;
    }
    else
    {
        return false;
    }
}

//----Zapisuje plik konta na dysku----//
bool CKonto::zapiszKonto()
{
    QString sciezka = "";
    QFile plikKonta(sciezka + "accounts" + QDir::separator() + numerKonta + ".acc");
    if(numerKonta.isNull() == false)
    {
        if(plikKonta.open(QIODevice::WriteOnly))
        {
            QTextStream zawartoscPliku(&plikKonta);
            zawartoscPliku << imie << endl;
            zawartoscPliku << nazwisko << endl;
            zawartoscPliku << stanKonta;
            plikKonta.close();
            return true;
        }
    }
    return false;
}
