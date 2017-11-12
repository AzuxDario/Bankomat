#ifndef WIDGETOPROGRAMIE_H
#define WIDGETOPROGRAMIE_H

#include "WidgetWindow.h"
#include <QLabel>
#include <QPushButton>

namespace Ui {
    class WidgetOProgramie;
}

class WidgetOProgramie : public WidgetWindow
{
    Q_OBJECT

public:
    explicit WidgetOProgramie(WidgetWindow *parent = 0);
    ~WidgetOProgramie();

private:
    Ui::WidgetOProgramie *ui;

    //----Przyciski----//
    QPushButton *przyciskOk;

    //----Pola tekstowe----//
    QLabel *poleText;

    //----Obrazek----//
    QLabel *poleObrazek
    ;
    //----Zmienne przechuwyjące ciągi znaków----//
    QString trescOkienkaInformacyjengo;
};

#endif // WIDGETOPROGRAMIE_H
