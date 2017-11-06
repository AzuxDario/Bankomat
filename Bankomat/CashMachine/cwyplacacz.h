#ifndef CWYPLACACZ_H
#define CWYPLACACZ_H

#include "ckasetapieniedzy.h"
#include "ckonto.h"

class CWyplacacz
{
private:
    CKasetaPieniedzy *kaseta;
    QVector<int> ostatniaWyplata;
    int poziomyNominalow[10];
public:
    enum WynikWyplaty {brakSrodkow, wyplaconoPieniadze};
public:
    CWyplacacz(CKasetaPieniedzy *kaseta);

    //----Gettery----//
    QVector<int> zwrocOstatniaWyplate();

    bool czyWystarczyGotowki(); //Sprawdza czy w bankomacie jest wystarczająca ilośc gotówki
    WynikWyplaty dokonajWyplaty(CKonto *konto, int kwota); //Inicjuje wypłątę z konta sprawdzając czy stan konta jest wystarczający
private:
    void wyplacPieniadze(int kwota); //Wyznacza jakimi nominałami wyznaczyć pieniądze z konta

};

#endif // CWYPLACACZ_H
