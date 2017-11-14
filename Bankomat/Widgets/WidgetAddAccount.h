#ifndef WIDGETADDACCOUNT_H
#define WIDGETADDACCOUNT_H

#include "WidgetWindow.h"
#include "Account.h"
#include "Card.h"
#include <QDate>
#include <QTime>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QMessageBox>

namespace Ui {
class WidgetDodajKonto;
}

class WidgetAddAccount : public WidgetWindow
{
    Q_OBJECT

public:
    explicit WidgetAddAccount(WidgetWindow *parent = 0);
    ~WidgetAddAccount();

private:
    Ui::WidgetDodajKonto *ui;

    //----Przyciski----//
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    //----Layout----//
    QGridLayout *layout;

    //----GroupBox----//
    QGroupBox *group;

    //----Labele opsiujące pola----//
    QLabel *name;
    QLabel *surname;
    QLabel *pin;
    QLabel *balance;

    //----Pola do wpisania wartości----//
    QLineEdit *lineEditName;
    QLineEdit *lineEditSurname;
    QSpinBox *spinBoxPin;
    QDoubleSpinBox *spinBoxBalance;

    Card *card;
    Account *account;

private slots:
    void closeWindowOk(); //Zamyka okno zachowując zmiany
    void closeWindowCancel(); //Zamyka okno nie zachowując zmian
    void closeEvent(QCloseEvent *); //Zamyka okno nie zachowując zmian
    void clearFields(); //Zeruje wartości w polach
    bool createAccount(QString fileName); //Procedura zapisu plików karty i konta

};

#endif // WIDGETADDACCOUNT_H
