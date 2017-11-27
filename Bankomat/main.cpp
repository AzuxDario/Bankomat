//12.12.2016 - 12.01.2017
//Program Bankomat będący zaliczeniem projektu na C++ na 3 semestrze infofrmatyki na Politechince Rzeszowskiej

#include "Widget.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle(QString::fromUtf8("Bankomat"));
    w.setMinimumSize(1000,820);
    w.setMaximumSize(1000,820);
    w.setWindowIcon(QIcon(":/bankomat/ikona"));
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center()); //Przesuń na pozycję środek monitora odjąć środek okna
    w.show();

    return a.exec();
}
