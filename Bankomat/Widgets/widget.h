#ifndef WIDGET_H
#define WIDGET_H

#include "crdzen.h"
#include "DropButton.h"
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QMenuBar>
#include <QKeySequence>
#include <QLabel>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    bool wait; //Wartość true oznacza aby nie reagować na kliknięcia przycisków bankomatu. Służy do tworzenia ekranów ładowania
    bool isCardLoaded;
    bool isAccountLoaded;

public:
    Ui::Widget *ui;

    //----Zmienne od paska menu----//
    QMenuBar *menuBar;
    QMenu *pasekBankomat;
    QMenu *pasekKonta;
    QMenu *pasekPomoc;
    QAction *akcjaUzytoKarte;
    QAction *akcjaResetuj;
    QAction *akcjaWyjscie;
    QAction *akcjaZalozKonto;
    QAction *akcjaDodajPieniadze;
    QAction *akcjaInformacje;

    //----Okno do wyświetlania----//
    QLabel *okno;
    QLabel *pole;
    QLabel *tytul;
    QLabel *podpisA;
    QLabel *podpisB;
    QLabel *podpisC;
    QLabel *podpisD;
    QLabel *podpisE;
    QLabel *podpisF;
    QLabel *podpisG;
    QLabel *podpisH;

    //----Przyciski do obsługi----//
    QPushButton *przyciskA;
    QPushButton *przyciskB;
    QPushButton *przyciskC;
    QPushButton *przyciskD;
    QPushButton *przyciskE;
    QPushButton *przyciskF;
    QPushButton *przyciskG;
    QPushButton *przyciskH;

    //----Przyciski klawiatury----//
    QPushButton *przycisk1;
    QPushButton *przycisk2;
    QPushButton *przycisk3;
    QPushButton *przycisk4;
    QPushButton *przycisk5;
    QPushButton *przycisk6;
    QPushButton *przycisk7;
    QPushButton *przycisk8;
    QPushButton *przycisk9;
    QPushButton *przycisk0;
    QPushButton *przyciskCofnij;

    //----Przyciski od karty i pieniędzy----//
    DropButton *przyciskUzytoKarte;
    QPushButton *przyciskPieniadze;

    //----Tablica gdzie będzie wyświetlana wypłata----//
    QTableWidget *tablicaWyplaty;

    //----Rdzen----//
    CRdzen *rdzen;

public slots:
    void wyswietlOProgramie(); //Pokazuje okienko z informacjami o programie
    void wyswietlDodajKonto(); //Wyświetla okienko gdzie można utworzyć konto do testów
    void wyswieltDodajPieniadze(); //Pokazuje okienko gdzie można dołożyć pieniądze do bankomatu    
    void wyswietlEkran(CRdzen::StanBankomatu stan); //Wyświetla odpowiedni ekran zależnie od stanu bankomatu
    void wyswietlWyplate(QVector<int> pieniadze); //Wyświetla wypłacone pieniądze w elemencie QTableWidget
    void wyczyscTabliceWyplaty(); //Czyści tablice QTableWidget

    //----Funkcje obsługi kliknięć przycisków funkcyjnych bankomatu----//
    void przyciskAKliknieto();
    void przyciskBKliknieto();
    void przyciskCKliknieto();
    void przyciskDKliknieto();
    void przyciskEKliknieto();
    void przyciskFKliknieto();
    void przyciskGKliknieto();
    void przyciskHKliknieto();

    //----Przyciski obsługi kliknieć przycisków numerycznych bankomatu----//
    void przyciskNumerycznyKliknieto(int wartosc);
    void przycisk1Kliknieto();
    void przycisk2Kliknieto();
    void przycisk3Kliknieto();
    void przycisk4Kliknieto();
    void przycisk5Kliknieto();
    void przycisk6Kliknieto();
    void przycisk7Kliknieto();
    void przycisk8Kliknieto();
    void przycisk9Kliknieto();
    void przycisk0Kliknieto();
    void przyciskCofnijKliknieto();

    void przyciskUzytoKarteKliknieto(); //Funkcja obsługi kliknięcia przycisku "Karta"
    void upuszczonoKarteKliknieto(); //Funkcja obsługi upuszczenia na przycisk
    void przyciskPieniadzeKliknieto(); //Funkcja obsługi kliknięcia przycisku "Odbierz pieniądze"
    void ustawPoleWartosci(); //Ustawia wartość w polu na środku ekranu. Wyświetla pin lub kwotę
    void aktywujPrzyciskiKarty();
    void deaktywujPrzyciskiKarty();
    void resetujKliknieto(); //Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy

private slots:
    void ustawTekst(QString tytul, QString opcjaA, QString opcjaB, QString opcjaC, QString opcjaD, QString opcjaE, QString opcjaF, QString opcjaG, QString opcjaH); //Ustawia etykiety tekstowe ekranu
    void closeEvent(QCloseEvent *); //Zamyka program po zamknięciu głównego okna



};

#endif // WIDGET_H
