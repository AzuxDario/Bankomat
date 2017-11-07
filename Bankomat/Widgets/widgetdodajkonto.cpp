#include "widgetdodajkonto.h"
#include "ui_widgetdodajkonto.h"

WidgetDodajKonto::WidgetDodajKonto(WidgetOkno *parent) :
    WidgetOkno(parent),
    ui(new Ui::WidgetDodajKonto)
{
    ui->setupUi(this);

    //----Inicjalizacja okna----//
    setWindowTitle(QString::fromUtf8("Załóż konto"));
    setWindowIcon(QIcon(":/bankomat/ikona"));
    setMaximumSize(300,250);
    setMinimumSize(300,250);

    //----Przyciski----//
    przyciskOk = new QPushButton("Utwórz",this);
    przyciskOk->setGeometry(25,205,100,30);
    przyciskAnuluj = new QPushButton("Anuluj",this);
    przyciskAnuluj->setGeometry(175,205,100,30);

    //----Labele opsiujące pola----//
    imie = new QLabel("Imie");
    nazwisko = new QLabel("Nazwisko");
    pin = new QLabel("PIN");
    stanKonta = new QLabel("Stan konta");

    //----Pola do wpisania wartości----//
    podajImie = new QLineEdit();
    podajNazwisko = new QLineEdit();
    podajPin = new QSpinBox();
    podajStanKonta = new QDoubleSpinBox();

    podajPin->setMinimum(1000);
    podajPin->setMaximum(9999);

    podajStanKonta->setMaximum(50000);

    //----Layout----//
    layout = new QGridLayout();
    layout->addWidget(imie,0,0);
    layout->addWidget(nazwisko,1,0);
    layout->addWidget(pin,2,0);
    layout->addWidget(stanKonta,3,0);
    layout->addWidget(podajImie,0,1);
    layout->addWidget(podajNazwisko,1,1);
    layout->addWidget(podajPin,2,1);
    layout->addWidget(podajStanKonta,3,1);

    //----GroupBox----//
    grupa = new QGroupBox("Podaj dane",this);
    grupa->setGeometry(10,10,280,190);
    grupa->setLayout(layout);

    karta = nullptr;
    konto = nullptr;

    //----Przypisanie przycisków do slotów----//
    connect(przyciskOk,SIGNAL(clicked(bool)),this,SLOT(zamknijOknoOk()));
    connect(przyciskAnuluj,SIGNAL(clicked(bool)),this,SLOT(zamknijOknoAnuluj()));

    this->pokazSie();
}

WidgetDodajKonto::~WidgetDodajKonto()
{
    //----Przyciski----//
    delete przyciskOk;
    delete przyciskAnuluj;

    //----Labele opsiujące pola----//
    delete imie;
    delete nazwisko;
    delete pin;
    delete stanKonta;

    //----Pola do wpisania wartości----//
    delete podajImie;
    delete podajNazwisko;
    delete podajPin;
    delete podajStanKonta;

    //----Layout----//
    delete layout;

    //----GroupBox----//
    delete grupa;

    delete ui;
}

//----Zamyka okno zachowując zmiany----//
void WidgetDodajKonto::zamknijOknoOk()
{
    QString nazwaPliku = QFileDialog::getSaveFileName(this, "Wybierz miejsce do zapisuj karty","","Karta (*.card)");
    if(nazwaPliku != "")
    {
        utworzKonto(nazwaPliku);
        int wartosc;
        QMessageBox okno("Informacja","Utworzono konto",QMessageBox::Information,QMessageBox::Ok|QMessageBox::Default,0,0);
        wartosc = okno.exec();
        if(wartosc == QMessageBox::Ok)
        {
            okno.close();
        }
        zerujPola();
        this->close();
    }
}

//----Zamyka okno nie zachowując zmian----//
void WidgetDodajKonto::zamknijOknoAnuluj()
{
    zerujPola();
    this->close();
}

//----Zamyka okno nie zachowując zmian----//
void WidgetDodajKonto::closeEvent(QCloseEvent *)
{
    zerujPola();
    this->close();
}

//----Zeruje wartości w polach----//
void WidgetDodajKonto::zerujPola()
{
    podajImie->setText("");
    podajNazwisko->setText("");
    podajPin->setValue(1000);
    podajStanKonta->setValue(0);
}

//----Procedura zapisu plików karty i konta----//
bool WidgetDodajKonto::utworzKonto(QString nazwaPliku)
{
    bool zwracanaWartosc = true;
    QString numerKonta = "223434678" + QDate::currentDate().toString("yyyyMMdd") + QTime::currentTime().toString("HHmmsszzz");
    QString numerKarty = "22" + QDate::currentDate().toString("yyyyMMdd") + QTime::currentTime().toString("HHmmss");
    konto = new CKonto();
    konto->ustawImie(podajImie->text());
    konto->ustawNazwisko(podajNazwisko->text());
    konto->ustawNumerKonta(numerKonta);
    konto->ustawStanKonta(podajStanKonta->value());
    zwracanaWartosc = konto->zapiszKonto();
    delete konto;
    karta = new Card();
    karta->setCardNumber(numerKarty);
    karta->setIsCardBlocked(false);
    karta->setAccountNumber(numerKonta);
    karta->setPin(podajPin->value());
    karta->setCardFilePath(nazwaPliku);
    zwracanaWartosc = karta->saveCardFile();
    delete karta;
    return zwracanaWartosc;
}
