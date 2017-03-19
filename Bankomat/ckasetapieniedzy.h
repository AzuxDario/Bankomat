#ifndef CKASETAPIENIEDZY_H
#define CKASETAPIENIEDZY_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>

class CKasetaPieniedzy
{
private:
    QVector<int> iloscNominalow;
    QVector<int> wartoscNominalow;
public:
    CKasetaPieniedzy();
    ~CKasetaPieniedzy();

    //----Gettery----//
    QVector<int> zwrocIloscNominalow();
    QVector<int> zwrocWartoscNominalow();

    //----Settery----//
    void ustawIloscNominalow(QVector<int> wartosc);
    void dodajGotowki(QVector<int> wartosc);

    void odczytajKasete(); //Odczytuje informacje o ilości pieniędzy z dysku
    void zapiszKasete(); //Zapisuje informację o ilości pieniędzy na dysk
};

#endif // CKASETAPIENIEDZY_H
