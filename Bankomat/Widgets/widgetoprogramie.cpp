#include "widgetoprogramie.h"
#include "ui_widgetoprogramie.h"

WidgetOProgramie::WidgetOProgramie(WidgetOkno *parent) :
    WidgetOkno(parent),
    ui(new Ui::WidgetOProgramie)
{
    ui->setupUi(this);
    trescOkienkaInformacyjengo = "Nazwa programu: Bankomat<br />Program jest symulatorem działania bankomatu.<br />Autor: Paweł Miękina";

    //----Inicjalizacja okna----//
    setWindowTitle(QString::fromUtf8("O programie"));
    setWindowIcon(QIcon(":/bankomat/ikona"));
    setMaximumSize(500,210);
    setMinimumSize(500,210);

    //----Okno z tekstem----//
    poleText = new QLabel(trescOkienkaInformacyjengo,this);
    poleText->setGeometry(148,10,342,128);
    poleText->setWordWrap(true);

    //----Przycisk----//
    przyciskOk = new QPushButton("Ok",this);
    przyciskOk->setGeometry(180,170,140,30);

    //----Obrazek----//
    poleObrazek = new QLabel(this);
    poleObrazek->setGeometry(10,10,128,128);
    poleObrazek->setPixmap(QPixmap(":/bankomat/ikona128x128"));

    //----Przypisanie przycisków do slotów----//
    connect(przyciskOk,SIGNAL(clicked()),this,SLOT(zamknijOkno()));

    this->pokazSie();
}

WidgetOProgramie::~WidgetOProgramie()
{
    //----Przyciski----//
    delete przyciskOk;

    //----Pola tekstowe----//
    delete poleText;

    //----Obrazek----//
    delete poleObrazek;

    delete ui;
}
