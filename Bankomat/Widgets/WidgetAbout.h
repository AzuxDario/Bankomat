#ifndef WIDGETABOUT_H
#define WIDGETABOUT_H

#include "WidgetWindow.h"
#include <QLabel>
#include <QPushButton>

namespace Ui {
    class WidgetOProgramie;
}

class WidgetAbout : public WidgetWindow
{
    Q_OBJECT

public:
    explicit WidgetAbout(WidgetWindow *parent = 0);
    ~WidgetAbout();

private:
    Ui::WidgetOProgramie *ui;

    //----Przyciski----//
    QPushButton *buttonOk;

    //----Pola tekstowe----//
    QLabel *labelText;

    //----Obrazek----//
    QLabel *labelImage
    ;
    //----Zmienne przechuwyjące ciągi znaków----//
    QString about;
};

#endif // WIDGETABOUT_H
