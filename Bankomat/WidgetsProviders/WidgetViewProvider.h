#ifndef CRDZEN_H
#define CRDZEN_H

#include "Card.h"
#include "Account.h"
#include "MoneyDispenser.h"
#include "MoneyBox.h"
#include "WidgetAbout.h"
#include "WidgetAddAccount.h"
#include "WidgetAddMoney.h"
#include <QObject>
#include <QTimer>
#include <QString>
#include <QTimer>

class CRdzen : public QObject
{
    Q_OBJECT
public:
    explicit CRdzen(QObject *parent = 0);
    ~CRdzen();
    enum ATMState {insertCard, noMoneyInATM, wrongCardFile, blockedCard, insertPin, wrongPin, chooseOperation, changePin, pinChanged, showAccountNumber, showBalance, insertAmountOfMoney, withdrawMoney, noEnoughMoney, removeCard};
private:
    ATMState atmState; //Przechowuje obecny stan bankomatu
    QString valueField; //Pole zawierające obecnie wpisany pin lub kwotę do wypłaty
    Card *card;
    Account *account;
    MoneyDispenser *moneyDispenser; //Obiekt zajmujący się wypłacaniem pieniędzy
    MoneyBox *moneyBox;
    bool isATMStateChanged; //Zmienna przyjmująca wartość true, jeżeli klilnięcie przycisku spowodowało zmianę stanu bankomatu

    //----Zmienne wskazujące na okna----//
    WidgetAbout *widgetAbout;
    WidgetAddAccount *widgetAddAccount;
    WidgetAddMoney *widgetAddMoney;

signals:

public slots:
    //----Gettery----//
    QString getValueField(); //Zwraca zawartość pola
    QString getHiddenValueField(); //Zwraca zawartość pola w postaci gwiazdek
    QString getAccountNumber(); //Zwraca numer aktualnie załadowanego konta
    double getBalance(); //Zwraca stan obecnie załadowanego konta
    ATMState getATMState(); //Zwraca stan bankomatu
    bool getIsATMStateChanged(); //Zwraca czy zmieniono stan bankomatu

    //----Settery----//
    void setATMState(ATMState atmState); //Zmienia stan bankomatu

    //----Funkcje wyświetlające okna----//
    void showWidgetAbout(); //Pokazuje okienko z informacjami o programie
    void showWidgetAddAccount(); //Wyświetla okienko gdzie można utworzyć konto do testów
    void showWidgetAddMoney(); //Pokazuje okno gdzie można dołożyć pieniądze do bankomatu

    //----Funkcję obsługi przycisków bankomatu----//
    ATMState buttonAPressed();
    ATMState buttonBPressed();
    ATMState buttonCPressed();
    ATMState buttonDPressed();
    ATMState buttonEPressed();
    ATMState buttonFPressed();
    ATMState buttonGPressed();
    ATMState buttonHPressed();
    void buttonNumberPressed(int value);
    void buttonUndoPressed();
    ATMState cardUsed(QString dir = ""); //Funkcja informująca o użyciu karty
    ATMState moneyReceived(); //Funkcja informująca o odebraniu pieniędzy

    QVector<int> getMoney(); //Zwraca wektor z ilością wypłaconych pieniędzy gdzie na indeksie 0 jest 200zł
    void buttonResetPressed(); //Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy

};

#endif // CRDZEN_H
