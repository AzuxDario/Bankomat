#include "WidgetAbout.h"
#include "ui_widgetoprogramie.h"

WidgetAbout::WidgetAbout(WidgetWindow *parent) :
    WidgetWindow(parent),
    ui(new Ui::WidgetOProgramie)
{
    ui->setupUi(this);
    about = "Nazwa programu: Bankomat<br />Program jest symulatorem działania bankomatu.<br />Autor: Paweł Miękina";

    //----Inicjalizacja okna----//
    setWindowTitle(QString::fromUtf8("O programie"));
    setWindowIcon(QIcon(":/bankomat/ikona"));
    setMaximumSize(500,210);
    setMinimumSize(500,210);

    //----Okno z tekstem----//
    labelText = new QLabel(about,this);
    labelText->setGeometry(148,10,342,128);
    labelText->setWordWrap(true);

    //----Przycisk----//
    buttonOk = new QPushButton("Ok",this);
    buttonOk->setGeometry(180,170,140,30);

    //----Obrazek----//
    labelImage = new QLabel(this);
    labelImage->setGeometry(10,10,128,128);
    labelImage->setPixmap(QPixmap(":/bankomat/ikona128x128"));

    //----Przypisanie przycisków do slotów----//
    connect(buttonOk,SIGNAL(clicked()),this,SLOT(closeWindow()));

    this->showWindow();
}

WidgetAbout::~WidgetAbout()
{

}
