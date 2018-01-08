#ifndef ACCOUNT_H
#define ACCOUNT_H

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
    QString getName() {return name;}
    QString getSurname() {return surname;}
    QString getAccountNumber() {return accountNumber;}
    double getBalance() {return balance;}

    //----Settery----//
    void setName(QString value) {name = value;}
    void setSurname(QString value) {surname = value;}
    void setAccountNumber(QString value) {accountNumber = value;}
    void setBalance(double value) {balance = value;}

    void withdraw(double amount) {balance -= amount; writeAccount();}//Pobiera kwotę z konta

    bool readAccount(); //Odczytuje plik konta z dysku
    bool writeAccount(); //Zapisuje plik konta na dysku
};

#endif // ACCOUNT_H
