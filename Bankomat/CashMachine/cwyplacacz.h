#ifndef CWYPLACACZ_H
#define CWYPLACACZ_H

#include "MoneyBox.h"
#include "Account.h"

class CWyplacacz
{
private:
    MoneyBox *kaseta;
    QVector<int> ostatniaWyplata;
    int poziomyNominalow[10];
public:
    enum WynikWyplaty {brakSrodkow, wyplaconoPieniadze};
public:
    CWyplacacz(MoneyBox *kaseta);

    //----Gettery----//
    QVector<int> zwrocOstatniaWyplate();

    bool czyWystarczyGotowki(); //Sprawdza czy w bankomacie jest wystarczająca ilośc gotówki
    WynikWyplaty dokonajWyplaty(Account *konto, int kwota); //Inicjuje wypłątę z konta sprawdzając czy stan konta jest wystarczający
private:
    void wyplacPieniadze(int kwota); //Wyznacza jakimi nominałami wyznaczyć pieniądze z konta

};

#endif // CWYPLACACZ_H
