#include "widgetokno.h"

WidgetOkno::WidgetOkno(QWidget *parent) : QWidget(parent)
{

}

void WidgetOkno::zamknijOkno()
{
    this->close();
}

void WidgetOkno::pokazSie()
{
    if(this->isVisible()) //Jeżeli okno jest widoczne
    {
        this->activateWindow(); //Niech stanie się aktywne
    }
    else //Jeżeli okno było stworzone i nie jest widoczne wywołaj je
    {
        this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
        this->show();
    }
}
