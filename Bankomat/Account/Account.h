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
    void setBalance(double value);

    void withdraw(double amount); //Pobiera kwotę z konta

    bool readAccount(); //Odczytuje plik konta z dysku
    bool writeAccount(); //Zapisuje plik konta na dysku
};

#endif // CKONTO_H
