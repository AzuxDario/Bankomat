#ifndef WIDGETOPROGRAMIE_H
#define WIDGETOPROGRAMIE_H

#include "widgetokno.h"
#include <QLabel>
#include <QPushButton>

namespace Ui {
    class WidgetOProgramie;
}

class WidgetOProgramie : public WidgetOkno
{
    Q_OBJECT

public:
    explicit WidgetOProgramie(WidgetOkno *parent = 0);
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
