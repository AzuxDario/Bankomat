#ifndef CKARTA_H
#define CKARTA_H

#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>

class CKarta
{
public:
    CKarta();
private:
    QString numerKarty;
    bool czyKartaZablokowana;
    int pin;
    QString numerKonta;
    QString lokalizacjaKarty;
    int licznikNiepoprawnychWprowadzenPinu;
public:
    enum StanKarty {kartaOdczytana, kartaUszkodzona, brakKarty};

    //----Gettery----//
    QString zwrocNumerKarty();
    bool zwrocCzyKartaZablokowana();
    int zwrocPin();
    QString zwrocNumerKonta();
    QString zwrocLokalizacjaKarty();

    //----Settery----//
    void ustawNumerKarty(QString nowyNumer);
    void ustawCzyKartaZablokowana(bool nowaWartosc);
    void ustawPin(int nowyPin);
    void ustawNumerKonta(QString nowyNumerKonta);
    void ustawLokalizacjaKarty(QString lokalizacja);

    StanKarty odczytajKarte(QString lokalizacja = ""); //Czyta karte z dysku
    bool zapiszKarte(); //Zapisuje kartę na dysk
    bool sprawdzPin(int wartosc); //Sprawdza pin

private:
    void zablokujKarte(bool wartosc); //Funkcja blokująca kartę po trzech nieudanych próbach sprawdzenia pinu

};

#endif // CKARTA_H
