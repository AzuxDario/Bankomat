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
    enum StanBankomatu {wlozKarte, brakSrodkowWBankomacie, niepoprawnyPlikKarty, kartaZablokowana, podajPin, niepoprawnyPin, wybierzOperacje, zmienPin, zmienionoPin, pokazNumerKonta, wyswietlSaldo, wybierzGotowke, wyplacGotowke, brakGotowki, wyjmijKarte};
private:
    StanBankomatu stanBankomatu; //Przechowuje obecny stan bankomatu
    QString valueField; //Pole zawierające obecnie wpisany pin lub kwotę do wypłaty
    Card *card;
    Account *account;
    MoneyDispenser *moneyDispenser; //Obiekt zajmujący się wypłacaniem pieniędzy
    MoneyBox *moneyBox;
    bool czyZmienionoStanBankomatu; //Zmienna przyjmująca wartość true, jeżeli klilnięcie przycisku spowodowało zmianę stanu bankomatu

    //----Zmienne wskazujące na okna----//
    WidgetAbout *oknoOProgramie;
    WidgetAddAccount *oknoDodajKonto;
    WidgetAddMoney *oknoDodajPieniadze;

signals:

public slots:
    //----Gettery----//
    QString getValueField(); //Zwraca zawartość pola
    QString getHiddenValueField(); //Zwraca zawartość pola w postaci gwiazdek
    QString getAccountNumber(); //Zwraca numer aktualnie załadowanego konta
    double getBalance(); //Zwraca stan obecnie załadowanego konta
    StanBankomatu getATMState(); //Zwraca stan bankomatu
    bool isATMStateChanged(); //Zwraca czy zmieniono stan bankomatu

    //----Settery----//
    void setATMState(StanBankomatu stanBankomatu); //Zmienia stan bankomatu

    //----Funkcje wyświetlające okna----//
    void wyswietlOProgramie(); //Pokazuje okienko z informacjami o programie
    void wyswietlDodajKonto(); //Wyświetla okienko gdzie można utworzyć konto do testów
    void wyswietlDodajPieniadze(); //Pokazuje okno gdzie można dołożyć pieniądze do bankomatu

    //----Funkcję obsługi przycisków bankomatu----//
    StanBankomatu przyciskAKliknieto();
    StanBankomatu przyciskBKliknieto();
    StanBankomatu przyciskCKliknieto();
    StanBankomatu przyciskDKliknieto();
    StanBankomatu przyciskEKliknieto();
    StanBankomatu przyciskFKliknieto();
    StanBankomatu przyciskGKliknieto();
    StanBankomatu przyciskHKliknieto();
    void przyciskKliknieto(int wartosc);
    void przyciskCofnijKliknieto();
    StanBankomatu uzytoKarte(QString lokalizacja = ""); //Funkcja informująca o użyciu karty
    StanBankomatu odebranoPieniadze(); //Funkcja informująca o odebraniu pieniędzy

    QVector<int> odbierzPieniadze(); //Zwraca wektor z ilością wypłaconych pieniędzy gdzie na indeksie 0 jest 200zł
    void resetujKliknieto(); //Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy

};

#endif // CRDZEN_H
