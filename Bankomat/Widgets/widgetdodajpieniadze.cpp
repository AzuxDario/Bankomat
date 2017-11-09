#include "widgetdodajpieniadze.h"
#include "ui_widgetdodajpieniadze.h"

WidgetDodajPieniadze::WidgetDodajPieniadze(MoneyBox *kaseta, WidgetOkno *parent) :
    WidgetOkno(parent),
    ui(new Ui::WidgetDodajPieniadze)
{
    ui->setupUi(this);

    //----Inicjalizacja okna----//
    setWindowTitle(QString::fromUtf8("Dodaj pieniądze"));
    setWindowIcon(QIcon(":/bankomat/ikona"));
    setMaximumSize(450,360);
    setMinimumSize(450,360);
    setWindowModality(Qt::ApplicationModal); //Sprawia że po aktywacji okna główne okno staje się nieklikalne

    //----Przyciski----//
    przyciskOk = new QPushButton("Ok",this);
    przyciskOk->setGeometry(100,315,100,30);
    przyciskAnuluj = new QPushButton("Anuluj",this);
    przyciskAnuluj->setGeometry(250,315,100,30);

    //----Pola gdzie będzie wartość obecna----//
    obecneTekst200 = new QLabel("200 zł");
    obecneTekst100 = new QLabel("100 zł");
    obecneTekst50 = new QLabel("50 zł");
    obecneTekst20 = new QLabel("20 zł");
    obecneTekst10 = new QLabel("10 zł");
    obecneTekst5 = new QLabel("5 zł");
    obecneTekst2 = new QLabel("2 zł");
    obecneTekst1 = new QLabel("1 zł");

    //----Labele opsiujące pola----//
    obecnePole200 = new QLineEdit();
    obecnePole200->setReadOnly(true);
    obecnePole100 = new QLineEdit();
    obecnePole100->setReadOnly(true);
    obecnePole50 = new QLineEdit();
    obecnePole50->setReadOnly(true);
    obecnePole20 = new QLineEdit();
    obecnePole20->setReadOnly(true);
    obecnePole10 = new QLineEdit();
    obecnePole10->setReadOnly(true);
    obecnePole5 = new QLineEdit();
    obecnePole5->setReadOnly(true);
    obecnePole2 = new QLineEdit();
    obecnePole2->setReadOnly(true);
    obecnePole1 = new QLineEdit();
    obecnePole1->setReadOnly(true);

    //----Labele opsiujące pola----//
    tekst200 = new QLabel("200 zł");
    tekst100 = new QLabel("100 zł");
    tekst50 = new QLabel("50 zł");
    tekst20 = new QLabel("20 zł");
    tekst10 = new QLabel("10 zł");
    tekst5 = new QLabel("5 zł");
    tekst2 = new QLabel("2 zł");
    tekst1 = new QLabel("1 zł");

    //----Pola gdzie będzie wartość dodawana----//
    pole200 = new QSpinBox();
    pole100 = new QSpinBox();
    pole50 = new QSpinBox();
    pole20 = new QSpinBox();
    pole10 = new QSpinBox();
    pole5 = new QSpinBox();
    pole2 = new QSpinBox();
    pole1 = new QSpinBox();


    //----Layout----//
    layoutPieniadzeObecne = new QGridLayout();
    layoutPieniadzeObecne->addWidget(obecneTekst200,0,0);
    layoutPieniadzeObecne->addWidget(obecneTekst100,1,0);
    layoutPieniadzeObecne->addWidget(obecneTekst50,2,0);
    layoutPieniadzeObecne->addWidget(obecneTekst20,3,0);
    layoutPieniadzeObecne->addWidget(obecneTekst10,4,0);
    layoutPieniadzeObecne->addWidget(obecneTekst5,5,0);
    layoutPieniadzeObecne->addWidget(obecneTekst2,6,0);
    layoutPieniadzeObecne->addWidget(obecneTekst1,7,0);
    layoutPieniadzeObecne->addWidget(obecnePole200,0,1);
    layoutPieniadzeObecne->addWidget(obecnePole100,1,1);
    layoutPieniadzeObecne->addWidget(obecnePole50,2,1);
    layoutPieniadzeObecne->addWidget(obecnePole20,3,1);
    layoutPieniadzeObecne->addWidget(obecnePole10,4,1);
    layoutPieniadzeObecne->addWidget(obecnePole5,5,1);
    layoutPieniadzeObecne->addWidget(obecnePole2,6,1);
    layoutPieniadzeObecne->addWidget(obecnePole1,7,1);
    layoutPieniadzeObecne->setHorizontalSpacing(60);

    layoutPieniadzeDokladane = new QGridLayout();
    layoutPieniadzeDokladane->addWidget(tekst200,0,0);
    layoutPieniadzeDokladane->addWidget(tekst100,1,0);
    layoutPieniadzeDokladane->addWidget(tekst50,2,0);
    layoutPieniadzeDokladane->addWidget(tekst20,3,0);
    layoutPieniadzeDokladane->addWidget(tekst10,4,0);
    layoutPieniadzeDokladane->addWidget(tekst5,5,0);
    layoutPieniadzeDokladane->addWidget(tekst2,6,0);
    layoutPieniadzeDokladane->addWidget(tekst1,7,0);
    layoutPieniadzeDokladane->addWidget(pole200,0,1);
    layoutPieniadzeDokladane->addWidget(pole100,1,1);
    layoutPieniadzeDokladane->addWidget(pole50,2,1);
    layoutPieniadzeDokladane->addWidget(pole20,3,1);
    layoutPieniadzeDokladane->addWidget(pole10,4,1);
    layoutPieniadzeDokladane->addWidget(pole5,5,1);
    layoutPieniadzeDokladane->addWidget(pole2,6,1);
    layoutPieniadzeDokladane->addWidget(pole1,7,1);

    //----GroupBoxy----//
    pieniadzeObecne = new QGroupBox("Obecna ilość pieniędzy",this);
    pieniadzeObecne->setGeometry(20,10,205,300);
    pieniadzeObecne->setLayout(layoutPieniadzeObecne);
    pieniadzeDokladane = new QGroupBox("Dołóż pieniądze",this);
    pieniadzeDokladane->setGeometry(225,10,205,300);
    pieniadzeDokladane->setLayout(layoutPieniadzeDokladane);

    //----Kaseta pieniędzy----//
    this->kaseta = kaseta;
    ustawObecnaIloscPieniedzy();
    ustawMaksymalnaIloscDokladanychPieniedzy();

    //----Przypisanie przycisków do slotów----//
    connect(przyciskOk,SIGNAL(clicked(bool)),this,SLOT(zamknijOknoOk()));
    connect(przyciskAnuluj,SIGNAL(clicked(bool)),this,SLOT(zamknijOknoAnuluj()));

    this->pokazSie();
}

WidgetDodajPieniadze::~WidgetDodajPieniadze()
{

    //----Pola gdzie będzie wartość obecna----//
    delete obecneTekst200;
    delete obecneTekst100;
    delete obecneTekst50;
    delete obecneTekst20;
    delete obecneTekst10;
    delete obecneTekst5;
    delete obecneTekst2;
    delete obecneTekst1;

    //----Labele opsiujące pola----//
    delete obecnePole200;
    delete obecnePole100;
    delete obecnePole50;
    delete obecnePole20;
    delete obecnePole10;
    delete obecnePole5;
    delete obecnePole2;
    delete obecnePole1;

    //----Pola gdzie będzie wartość dodawana----//
    delete pole200;
    delete pole100;
    delete pole50;
    delete pole20;
    delete pole10;
    delete pole5;
    delete pole2;
    delete pole1;

    //----Labele opsiujące pola----//
    delete tekst200;
    delete tekst100;
    delete tekst50;
    delete tekst20;
    delete tekst10;
    delete tekst5;
    delete tekst2;
    delete tekst1;

    //----Layout----//
    delete layoutPieniadzeObecne;
    delete layoutPieniadzeDokladane;

    //----GroupBoxy----//
    delete pieniadzeObecne;
    delete pieniadzeDokladane;

    //----Przyciski----//
    delete przyciskOk;
    delete przyciskAnuluj;

    delete ui;
}

//----Zamyka okno zachowując zmiany----//
void WidgetDodajPieniadze::zamknijOknoOk()
{
    QVector<int> pieniadze;
    pieniadze << pole200->value() << pole100->value() << pole50->value() << pole20->value() << pole10->value() << pole5->value() << pole2->value() << pole1->value();
    kaseta->addMoney(pieniadze);
    zerujPola();
    this->close();
}

//----Zamyka okno nie zachowując zmian----//
void WidgetDodajPieniadze::zamknijOknoAnuluj()
{
    zerujPola();
    this->close();
}

//----Zamyka okno nie zachowując zmian----//
void WidgetDodajPieniadze::closeEvent(QCloseEvent *)
{
    zerujPola();
    this->close();
}

//----Zeruje wartości w polach----//
void WidgetDodajPieniadze::zerujPola()
{
    pole200->setValue(0);
    pole100->setValue(0);
    pole50 ->setValue(0);
    pole20->setValue(0);
    pole10->setValue(0);
    pole5->setValue(0);
    pole2->setValue(0);
    pole1->setValue(0);
}

//----Wpisuje w pola obecna ilosc pieniedzy----//
void WidgetDodajPieniadze::ustawObecnaIloscPieniedzy()
{
    QVector<int> pieniadze = kaseta->getNumberOfDenominations();
    obecnePole200->setText(QString::number(pieniadze.at(0)));
    obecnePole100->setText(QString::number(pieniadze.at(1)));
    obecnePole50 ->setText(QString::number(pieniadze.at(2)));
    obecnePole20->setText(QString::number(pieniadze.at(3)));
    obecnePole10->setText(QString::number(pieniadze.at(4)));
    obecnePole5->setText(QString::number(pieniadze.at(5)));
    obecnePole2->setText(QString::number(pieniadze.at(6)));
    obecnePole1->setText(QString::number(pieniadze.at(7)));
}

//----Pilnuje aby nie można było włożyć więcej niż 1000 sztuk danego nominału----//
void WidgetDodajPieniadze::ustawMaksymalnaIloscDokladanychPieniedzy()
{
    QVector<int> pieniadze = kaseta->getNumberOfDenominations();
    pole200->setMaximum(1000 - pieniadze.at(0));
    pole100->setMaximum(1000 - pieniadze.at(1));
    pole50->setMaximum(1000 - pieniadze.at(2));
    pole20->setMaximum(1000 - pieniadze.at(3));
    pole10->setMaximum(1000 - pieniadze.at(4));
    pole5->setMaximum(1000 - pieniadze.at(5));
    pole2->setMaximum(1000 - pieniadze.at(6));
    pole1->setMaximum(1000 - pieniadze.at(7));
}

void WidgetDodajPieniadze::pokazSie()
{
    if(this->isVisible()) //Jeżeli okno jest widoczne
    {
        this->activateWindow(); //Niech stanie się aktywne
    }
    else //Jeżeli okno było stworzone i nie jest widoczne wywołaj je
    {
        ustawObecnaIloscPieniedzy();
        this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
        this->show();
    }
}
