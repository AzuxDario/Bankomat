#ifndef WIDGETADDMONEY_H
#define WIDGETADDMONEY_H

#include "WidgetWindow.h"
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include <QGroupBox>
#include <QGridLayout>
#include "MoneyBox.h"

namespace Ui {
class WidgetDodajPieniadze;
}

class WidgetAddMoney : public WidgetWindow
{
    Q_OBJECT

public:
    explicit WidgetAddMoney(MoneyBox *moneyBox, WidgetWindow *parent = 0);
    ~WidgetAddMoney();

private:
    Ui::WidgetDodajPieniadze *ui;

    //----Przyciski----//
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    //----Layout----//
    QGridLayout *layoutPresentMoney;
    QGridLayout *layoutAddMoney;

    //----GroupBoxy----//
    QGroupBox *groupPresentMoney;
    QGroupBox *groupAddMoney;

    //----Pola gdzie będzie wartość obecna----//
    QLabel *labelPresent200;
    QLabel *labelPresent100;
    QLabel *labelPresent50;
    QLabel *labelPresent20;
    QLabel *labelPresent10;
    QLabel *labelPresent5;
    QLabel *labelPresent2;
    QLabel *labelPresent1;

    //----Labele opsiujące pola----//
    QLineEdit *editPresent200;
    QLineEdit *editPresent100;
    QLineEdit *editPresent50;
    QLineEdit *editPresent20;
    QLineEdit *editPresent10;
    QLineEdit *editPresent5;
    QLineEdit *editPresent2;
    QLineEdit *editPresent1;

    //----Pola gdzie będzie wartość dodawana----//
    QSpinBox *editAdd200;
    QSpinBox *editAdd100;
    QSpinBox *editAdd50;
    QSpinBox *editAdd20;
    QSpinBox *editAdd10;
    QSpinBox *editAdd5;
    QSpinBox *editAdd2;
    QSpinBox *editAdd1;

    //----Labele opsiujące pola----//
    QLabel *labelAdd200;
    QLabel *labelAdd100;
    QLabel *labelAdd50;
    QLabel *labelAdd20;
    QLabel *labelAdd10;
    QLabel *labelAdd5;
    QLabel *labelAdd2;
    QLabel *labelAdd1;

    //----Kaseta pieniędzy----//
    MoneyBox *kaseta;

private slots:
    void zamknijOknoOk(); //Zamyka okno zachowując zmiany
    void zamknijOknoAnuluj(); //Zamyka okno nie zachowując zmian
    void closeEvent(QCloseEvent *); //Zamyka okno nie zachowując zmian
    void zerujPola(); //Zeruje wartości w polach
    void ustawObecnaIloscPieniedzy(); //Wpisuje w pola obecna ilosc pieniedzy
    void ustawMaksymalnaIloscDokladanychPieniedzy(); //Pilnuje aby nie można było włożyć więcej niż 1000 sztuk danego nominału
public slots:
    void showWindow();
};

#endif // WIDGETADDMONEY_H
