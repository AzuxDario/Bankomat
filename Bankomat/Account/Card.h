#ifndef CKARTA_H
#define CKARTA_H

#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>

class Card
{
public:
    Card();
private:
    QString cardNumber;
    bool isCardBlocked;
    int pin;
    QString accountNumber;
    QString cardFilePath;
    int incorrectPinEnterCounter;
public:
    enum CardState {readCard, brokenCard, noCard};

    //----Gettery----//
    QString getCardNumber();
    bool getIsCardBlocked();
    int getPin();
    QString getAccountNumber();
    QString getCardFilePath();

    //----Settery----//
    void setCardNumber(QString value);
    void setIsCardBlocked(bool value);
    void setPin(int value);
    void setAccountNumber(QString value);
    void setCardFilePath(QString value);

    CardState readCardFile(QString sourceFile = ""); //Czyta karte z dysku
    bool saveCardFile(); //Zapisuje kartę na dysk
    bool checkPin(int value); //Sprawdza pin

private:
    void blockCard(bool value); //Funkcja blokująca kartę po trzech nieudanych próbach sprawdzenia pinu

};

#endif // CKARTA_H
