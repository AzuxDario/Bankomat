#ifndef WIDGET_H
#define WIDGET_H

#include "WidgetViewProvider.h"
#include "DropButton.h"
#include "ATMState.h"
#include "Screen.h"
#include "ScreenHolder.h"
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
    QMenu *menuCashMachine;
    QMenu *menuAccounts;
    QMenu *menuHelp;
    QAction *actionCardUsed;
    QAction *actionReset;
    QAction *actionExit;
    QAction *actionCreateAccount;
    QAction *actionAddMoney;
    QAction *actionInformation;

    //----Okno do wyświetlania----//
    QLabel *window;
    QLabel *field;
    QLabel *title;
    QLabel *optionA;
    QLabel *optionB;
    QLabel *optionC;
    QLabel *optionD;
    QLabel *optionE;
    QLabel *optionF;
    QLabel *optionG;
    QLabel *optionH;

    //----Przyciski do obsługi----//
    QPushButton *buttonA;
    QPushButton *buttonB;
    QPushButton *buttonC;
    QPushButton *buttonD;
    QPushButton *buttonE;
    QPushButton *buttonF;
    QPushButton *buttonG;
    QPushButton *buttonH;

    //----Przyciski klawiatury----//
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *button0;
    QPushButton *buttonReturn;

    //----Przyciski od karty i pieniędzy----//
    DropButton *cardUsedButton;
    QPushButton *moneyButton;

    //----Tablica gdzie będzie wyświetlana wypłata----//
    QTableWidget *paymentTable;

    //----Rdzeń programu----//
    WidgetViewProvider *programCore;

    ScreenHolder screenHolder;

public slots:
    void showWidgetAbout() {programCore->showWidgetAbout();} //Pokazuje okienko z informacjami o programie
    void showWidgetAddAccount() {programCore->showWidgetAddAccount();} //Wyświetla okienko gdzie można utworzyć konto do testów
    void showWidgetAddMoney() {programCore->showWidgetAddMoney();} //Pokazuje okienko gdzie można dołożyć pieniądze do bankomatu
    void showCurrentScreen(ATMState state); //Wyświetla odpowiedni ekran zależnie od stanu bankomatu
    void showPayment(QVector<int> money); //Wyświetla wypłacone pieniądze w elemencie QTableWidget
    void clearPaymentTable(); //Czyści tablice QTableWidget

    //----Funkcje obsługi kliknięć przycisków funkcyjnych bankomatu----//
    void buttonAPressed();
    void buttonBPressed();
    void buttonCPressed();
    void buttonDPressed();
    void buttonEPressed();
    void buttonFPressed();
    void buttonGPressed();
    void buttonHPressed();

    //----Przyciski obsługi kliknieć przycisków numerycznych bankomatu----//
    void buttonNumberPressed(int value);
    void button1Pressed();
    void button2Pressed();
    void button3Pressed();
    void button4Pressed();
    void button5Pressed();
    void button6Pressed();
    void button7Pressed();
    void button8Pressed();
    void button9Pressed();
    void button0Pressed();
    void buttonUndoPressed();

    void buttonCardUsedPressed(); //Funkcja obsługi kliknięcia przycisku "Karta"
    void cardDropped(); //Funkcja obsługi upuszczenia na przycisk
    void buttonMoneyPressed(); //Funkcja obsługi kliknięcia przycisku "Odbierz pieniądze"
    void setValueField(); //Ustawia wartość w polu na środku ekranu. Wyświetla pin lub kwotę
    void activeCardButton();
    void deactiveCardButton();
    void reset(); //Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy

private slots:
    void setText(QString title, QString textA, QString textB, QString textC, QString textD, QString textE, QString textF, QString textG, QString textH); //Ustawia etykiety tekstowe ekranu
    void setText(Screen *screen); //Ustawia etykiety tekstowe ekranu
    void closeEvent(QCloseEvent *) {qApp->quit();} //Zamyka program po zamknięciu głównego okna



};

#endif // WIDGET_H
