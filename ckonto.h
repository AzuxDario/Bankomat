#ifndef CKONTO_H
#define CKONTO_H

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QString>

class CKonto
{
private:
    QString imie;
    QString nazwisko;
    QString numerKonta;
    double stanKonta;
public:
    CKonto();
    CKonto(QString numerKonta);

    //----Gettery----//
    QString zwrocImie();
    QString zwrocNazwisko();
    QString zwrocNumerKonta();
    double zwrocStanKonta();

    //----Settery----//
    void ustawImie(QString noweImie);
    void ustawNazwisko(QString noweNazwisko);
    void ustawNumerKonta(QString nowyNumerKonta);
    void ustawStanKonta(double nowyStanKonta);

    void odejmijZeStanuKonta(double kwota); //Pobiera kwotę z konta

    bool odczytajKonto(); //Odczytuje plik konta z dysku
    bool zapiszKonto(); //Zapisuje plik konta na dysku
};

#endif // CKONTO_H
