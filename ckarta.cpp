#include "ckarta.h"

CKarta::CKarta()
{
    licznikNiepoprawnychWprowadzenPinu = 0;
}

//--------Gettery--------//
QString CKarta::zwrocNumerKarty()
{
    return numerKarty;
}

bool CKarta::zwrocCzyKartaZablokowana()
{
    return czyKartaZablokowana;
}

int CKarta::zwrocPin()
{
    return pin;
}

QString CKarta::zwrocNumerKonta()
{
    return numerKonta;
}

QString CKarta::zwrocLokalizacjaKarty()
{
    return lokalizacjaKarty;
}

//--------Settery--------//
void CKarta::ustawNumerKarty(QString nowyNumer)
{
    numerKarty = nowyNumer;
}

void CKarta::ustawCzyKartaZablokowana(bool nowaWartosc)
{
    czyKartaZablokowana = nowaWartosc;
}

void CKarta::ustawPin(int nowyPin)
{
    pin = nowyPin;
}

void CKarta::ustawNumerKonta(QString nowyNumerKonta)
{
    numerKonta = nowyNumerKonta;
}

void CKarta::ustawLokalizacjaKarty(QString lokalizacja)
{
    lokalizacjaKarty = lokalizacja;
}

//----Czyta karte z dysku----//
CKarta::StanKarty CKarta::odczytajKarte(QString lokalizacja)
{
    lokalizacjaKarty = lokalizacja;
    if(lokalizacjaKarty != "")
    {
        int pozycjaKropkiRozszerzenia = lokalizacja.lastIndexOf(".");
        if(lokalizacja.mid(pozycjaKropkiRozszerzenia) != ".card") //Sprawdzenie czy poz zmienna lokalizacja na pweno jest karta
        {
            return brakKarty;
        }
    }
    if(lokalizacjaKarty == "")
    {
        lokalizacjaKarty = QFileDialog::getOpenFileName(Q_NULLPTR,"Wybierz kartę","","Karta (*.card)");
    }
    QFile plikKarty(lokalizacjaKarty);
    if(lokalizacjaKarty.isNull() == false)
    {
        int linia = 0;
        if(plikKarty.open(QIODevice::ReadOnly))
        {

            QTextStream zawartoscPliku(&plikKarty);
            while(zawartoscPliku.atEnd() == 0)
            {
                linia++;
                if(linia == 1)
                {
                    numerKarty = zawartoscPliku.readLine();
                }
                else if(linia == 2)
                {
                    czyKartaZablokowana = zawartoscPliku.readLine().split(" ")[0].toInt();
                }
                else if(linia == 3)
                {
                    pin = zawartoscPliku.readLine().split(" ")[0].toInt();
                }
                else if(linia == 4)
                {
                    numerKonta = zawartoscPliku.readLine();
                }
                else
                {
                    break;
                }
            }
            plikKarty.close();
        }
        if(linia == 4)
        {
            return kartaOdczytana; //Gdy wczytano dwa ustawienia z karty oznacza to że jest poprawna
        }
        else
        {
            return kartaUszkodzona;//Gdy wczytano inną ilość lub karta ma więcej linii oznacza to, że jest niepoprawna
        }
    }
    else
    {
        return brakKarty; //Jeżeli nie wybrano pliku to karta jest niepoprawna
    }
}

//----Zapisuje kartę na dysk----//
bool CKarta::zapiszKarte()
{
    QFile plikKarty(lokalizacjaKarty);
    if(lokalizacjaKarty.isNull() == false)
    {
        if(plikKarty.open(QIODevice::WriteOnly))
        {
            QTextStream zawartoscPliku(&plikKarty);
            zawartoscPliku << numerKarty << endl;
            if(licznikNiepoprawnychWprowadzenPinu >= 3)
            {
               zawartoscPliku << "1" << endl;
            }
            else
            {
               zawartoscPliku << "0" << endl;
            }
            zawartoscPliku << pin << endl;
            zawartoscPliku << numerKonta;
            plikKarty.close();
            return true;
        }
    }
    return false;
}

//----Sprawdza pin----//
bool CKarta::sprawdzPin(int wartosc)
{
    if(pin == wartosc)
    {
        return true;
    }
    else
    {
        licznikNiepoprawnychWprowadzenPinu++;
        if(licznikNiepoprawnychWprowadzenPinu >= 3)
        {
            zablokujKarte(true);
        }
        return false;
    }
}

//----Funkcja blokująca kartę po trzech nieudanych próbach sprawdzenia pinu----//
void CKarta::zablokujKarte(bool wartosc)
{
    czyKartaZablokowana = wartosc;
}
