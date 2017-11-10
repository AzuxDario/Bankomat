#ifndef MONEYDISPENSER_H
#define MONEYDISPENSER_H

#include "MoneyBox.h"
#include "Account.h"

class MoneyDispenser
{
private:
    MoneyBox *moneyBox;
    QVector<int> lastPayment;
    int valueOfDenominations[10];
public:
    enum PaymentResult {NoFunds, PaidMoney};
public:
    MoneyDispenser(MoneyBox *moneyBox);

    //----Gettery----//
    QVector<int> getLastPayment();

    bool isEnoughCash(); //Sprawdza czy w bankomacie jest wystarczająca ilośc gotówki
    PaymentResult payment(Account *account, int amount); //Inicjuje wypłątę z konta sprawdzając czy stan konta jest wystarczający
private:
    void withdrawMoney(int amount); //Wyznacza jakimi nominałami wyznaczyć pieniądze z konta

};

#endif // MONEYDISPENSER_H
