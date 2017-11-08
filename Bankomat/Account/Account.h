#ifndef CKONTO_H
#define CKONTO_H

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QString>

class Account
{
private:
    QString name;
    QString surname;
    QString accountNumber;
    double balance;
public:
    Account();
    Account(QString accountNumber);

    //----Gettery----//
    QString getName();
    QString getSurname();
    QString getAccountNumber();
    double getBalance();

    //----Settery----//
    void setName(QString value);
    void setSurname(QString value);
    void setAccountNumber(QString value);
    void ustawStanKonta(double nowyStanKonta);

    void odejmijZeStanuKonta(double kwota); //Pobiera kwotę z konta

    bool odczytajKonto(); //Odczytuje plik konta z dysku
    bool zapiszKonto(); //Zapisuje plik konta na dysku
};

#endif // CKONTO_H
