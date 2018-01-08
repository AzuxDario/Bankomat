#ifndef CARD_H
#define CARD_H

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
    QString getCardNumber() {return cardNumber;}
    bool getIsCardBlocked() {return isCardBlocked;}
    int getPin() {return pin;}
    QString getAccountNumber() {return accountNumber;}
    QString getCardFilePath() {return cardFilePath;}

    //----Settery----//
    void setCardNumber(QString value) {cardNumber = value;}
    void setIsCardBlocked(bool value) {isCardBlocked = value;}
    void setPin(int value) {pin = value;}
    void setAccountNumber(QString value) {accountNumber = value;}
    void setCardFilePath(QString value) {cardFilePath = value;}

    CardState readCardFile(QString sourceFile = ""); //Czyta karte z dysku
    bool saveCardFile(); //Zapisuje kartę na dysk
    bool checkPin(int value); //Sprawdza pin

private:
    void blockCard(bool value) {isCardBlocked = value;} //Funkcja blokująca kartę po trzech nieudanych próbach sprawdzenia pinu

};

#endif // CARD_H
