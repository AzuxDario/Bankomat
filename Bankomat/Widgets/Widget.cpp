#include "Widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    wait = false;
    isCardLoaded = false;
    isAccountLoaded = false;

    //----Tworzenie paska menu----//
    menuBar = new QMenuBar(this);
    menuBar->setGeometry(0,0,1200,21);
    menuCashMachine = new QMenu(this);
    menuAccounts = new QMenu(this);
    menuHelp = new QMenu(this);

    menuCashMachine = menuBar->addMenu(tr("&Bankomat"));
    menuAccounts = menuBar->addMenu(tr("&Konta"));
    menuHelp = menuBar->addMenu(tr("&Pomoc"));

    //----Tworzenie akcji do paska menu----//
    actionCardUsed = new QAction("K&arta");
    actionCardUsed->setShortcut(QKeySequence(tr("Ctrl+A")));
    actionReset = new QAction("&Resetuj",this);
    actionReset->setShortcut(QKeySequence(tr("Ctrl+R")));
    actionExit = new QAction("Wyjści&e",this);
    actionExit->setShortcut(QKeySequence(tr("Ctrl+W")));
    actionCreateAccount = new QAction("&Załóż konto",this);
    actionCreateAccount->setShortcut(QKeySequence(tr("Ctrl+Z")));
    actionAddMoney = new QAction("&Dodaj pieniądze");
    actionAddMoney->setShortcut(QKeySequence(tr("Ctrl+D")));
    actionInformation = new QAction("&Informacje",this);
    actionInformation->setShortcut(QKeySequence(tr("Ctrl+I")));

    //----Przypisywnaia akcji do paska menu----//
    menuCashMachine->addAction(actionCardUsed);
    menuCashMachine->addAction(actionReset);
    menuCashMachine->addSeparator();
    menuCashMachine->addAction(actionExit);
    menuAccounts->addAction(actionCreateAccount);
    menuAccounts->addSeparator();
    menuAccounts->addAction(actionAddMoney);
    menuHelp->addAction(actionInformation);

    //----Tworzenie okna gdzie będzie wyświetlane tło----//
    window = new QLabel(this);
    window->setGeometry(100,31,800,500);
    window->setPixmap(QPixmap(":/bankomat/tło"));

    //----Tworzenie pola do wyświetlania pinu oraz kwoty do wypłaty----//
    field = new QLabel(this);
    field->setGeometry(200,200,600,35);
    field->setStyleSheet("color:white;font-size:40px;");
    field->setAlignment(Qt::AlignCenter);

    //----Tworzenie pól tekstowych na ekranie----//
    title = new QLabel(this);
    title->setGeometry(120,51,760,200);
    title->setStyleSheet("color:white;font-size:40px;");
    title->setWordWrap(true);
    title->setAlignment(Qt::AlignTop);

    optionA = new QLabel(this);
    optionA->setGeometry(120,211,380,60);
    optionA->setStyleSheet("color:white;font-size:40px;");
    optionB = new QLabel(this);
    optionB->setGeometry(120,291,380,60);
    optionB->setStyleSheet("color:white;font-size:40px;");
    optionC = new QLabel(this);
    optionC->setGeometry(120,371,380,60);
    optionC->setStyleSheet("color:white;font-size:40px;");
    optionD = new QLabel(this);
    optionD->setGeometry(120,451,380,60);
    optionD->setStyleSheet("color:white;font-size:40px;");
    optionE = new QLabel(this);
    optionE->setGeometry(500,211,380,60);
    optionE->setStyleSheet("color:white;font-size:40px;");
    optionE->setAlignment(Qt::AlignRight);
    optionF = new QLabel(this);
    optionF->setGeometry(500,291,380,60);
    optionF->setStyleSheet("color:white;font-size:40px;");
    optionF->setAlignment(Qt::AlignRight);
    optionG = new QLabel(this);
    optionG->setGeometry(500,371,380,60);
    optionG->setStyleSheet("color:white;font-size:40px;");
    optionG->setAlignment(Qt::AlignRight);
    optionH = new QLabel(this);
    optionH->setGeometry(500,451,380,60);
    optionH->setStyleSheet("color:white;font-size:40px;");
    optionH->setAlignment(Qt::AlignRight);

    //----Przyciski do obsługi----//
    buttonA = new QPushButton(this);
    buttonA->setGeometry(10,211,80,60);
    buttonB = new QPushButton(this);
    buttonB->setGeometry(10,291,80,60);
    buttonC = new QPushButton(this);
    buttonC->setGeometry(10,371,80,60);
    buttonD = new QPushButton(this);
    buttonD->setGeometry(10,451,80,60);
    buttonE = new QPushButton(this);
    buttonE->setGeometry(910,211,80,60);
    buttonF = new QPushButton(this);
    buttonF->setGeometry(910,291,80,60);
    buttonG = new QPushButton(this);
    buttonG->setGeometry(910,371,80,60);
    buttonH = new QPushButton(this);
    buttonH->setGeometry(910,451,80,60);

    //----Przyciski klawiatury----//
    przycisk1 = new QPushButton("1",this);
    przycisk1->setGeometry(404,541,57,57);
    przycisk1->setStyleSheet("font-size:40px;");
    przycisk2 = new QPushButton("2",this);
    przycisk2->setGeometry(471,541,57,57);
    przycisk2->setStyleSheet("font-size:40px;");
    przycisk3 = new QPushButton("3",this);
    przycisk3->setGeometry(538,541,57,57);
    przycisk3->setStyleSheet("font-size:40px;");
    przycisk4 = new QPushButton("4",this);
    przycisk4->setGeometry(404,608,57,57);
    przycisk4->setStyleSheet("font-size:40px;");
    przycisk5 = new QPushButton("5",this);
    przycisk5->setGeometry(471,608,57,57);
    przycisk5->setStyleSheet("font-size:40px;");
    przycisk6 = new QPushButton("6",this);
    przycisk6->setGeometry(538,608,57,57);
    przycisk6->setStyleSheet("font-size:40px;");
    przycisk7 = new QPushButton("7",this);
    przycisk7->setGeometry(404,675,57,57);
    przycisk7->setStyleSheet("font-size:40px;");
    przycisk8 = new QPushButton("8",this);
    przycisk8->setGeometry(471,675,57,57);
    przycisk8->setStyleSheet("font-size:40px;");
    przycisk9 = new QPushButton("9",this);
    przycisk9->setGeometry(538,675,57,57);
    przycisk9->setStyleSheet("font-size:40px;");
    przycisk0 = new QPushButton("0",this);
    przycisk0->setGeometry(471,742,57,57);
    przycisk0->setStyleSheet("font-size:40px;");
    przyciskCofnij = new QPushButton("←",this);
    przyciskCofnij->setGeometry(538,742,57,57);
    przyciskCofnij->setStyleSheet("font-size:40px;");

    //----Przyciski do obsługi karty oraz odbioru pieniędzy----//
    przyciskUzytoKarte = new DropButton("Karta",this);
    przyciskUzytoKarte->setGeometry(700,541,200,124);
    przyciskUzytoKarte->setStyleSheet("font-size:40px;");
    przyciskPieniadze = new QPushButton("Odbierz\npieniądze",this);
    przyciskPieniadze->setGeometry(700,675,200,124);
    przyciskPieniadze->setStyleSheet("font-size:40px;");
    przyciskPieniadze->setDisabled(true);

    //----Tworzenie tablicy gdzie będą pokazywane wypłacone nominały----//
    tablicaWyplaty = new QTableWidget(this);
    tablicaWyplaty->setGeometry(100,541,140,265);
    tablicaWyplaty->setColumnCount(1);
    tablicaWyplaty->setRowCount(8);
    tablicaWyplaty->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QStringList listaWierszy;
    listaWierszy << "200zł" << "100zł" << "50zł" << "20zł" << "10zł" << "5zł" << "2zł" << "1zł" ;
    tablicaWyplaty->setVerticalHeaderLabels(listaWierszy);
    QStringList listaKolumn;
    listaKolumn << "Ilość";
    tablicaWyplaty->setHorizontalHeaderLabels(listaKolumn);
    tablicaWyplaty->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //----Tworzenie obiektu rdzenia aplikacji----//
    rdzen = new CRdzen(this);

    //----Wyświetlenie obecnego ekranu dopasowanego do stanu bankomatu----//
    wyswietlEkran(rdzen->zwrocStanBankomatu());

    //----Przypisanie przycisków do slotów----//
    //--------Menu--------//
    connect(actionExit,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
    connect(buttonA,SIGNAL(clicked(bool)),this,SLOT(przyciskAKliknieto()));
    connect(buttonB,SIGNAL(clicked(bool)),this,SLOT(przyciskBKliknieto()));
    connect(buttonC,SIGNAL(clicked(bool)),this,SLOT(przyciskCKliknieto()));
    connect(buttonD,SIGNAL(clicked(bool)),this,SLOT(przyciskDKliknieto()));
    connect(buttonE,SIGNAL(clicked(bool)),this,SLOT(przyciskEKliknieto()));
    connect(buttonF,SIGNAL(clicked(bool)),this,SLOT(przyciskFKliknieto()));
    connect(buttonG,SIGNAL(clicked(bool)),this,SLOT(przyciskGKliknieto()));
    connect(buttonH,SIGNAL(clicked(bool)),this,SLOT(przyciskHKliknieto()));

    //--------Przyciski klawiatury--------//
    connect(przycisk1,SIGNAL(clicked(bool)),this,SLOT(przycisk1Kliknieto()));
    connect(przycisk2,SIGNAL(clicked(bool)),this,SLOT(przycisk2Kliknieto()));
    connect(przycisk3,SIGNAL(clicked(bool)),this,SLOT(przycisk3Kliknieto()));
    connect(przycisk4,SIGNAL(clicked(bool)),this,SLOT(przycisk4Kliknieto()));
    connect(przycisk5,SIGNAL(clicked(bool)),this,SLOT(przycisk5Kliknieto()));
    connect(przycisk6,SIGNAL(clicked(bool)),this,SLOT(przycisk6Kliknieto()));
    connect(przycisk7,SIGNAL(clicked(bool)),this,SLOT(przycisk7Kliknieto()));
    connect(przycisk8,SIGNAL(clicked(bool)),this,SLOT(przycisk8Kliknieto()));
    connect(przycisk9,SIGNAL(clicked(bool)),this,SLOT(przycisk9Kliknieto()));
    connect(przycisk0,SIGNAL(clicked(bool)),this,SLOT(przycisk0Kliknieto()));
    connect(przyciskCofnij,SIGNAL(clicked(bool)),this,SLOT(przyciskCofnijKliknieto()));

    //--------Akcje--------//
    connect(actionCardUsed,SIGNAL(triggered(bool)),this,SLOT(przyciskUzytoKarteKliknieto()));
    connect(actionReset,SIGNAL(triggered(bool)),this,SLOT(resetujKliknieto()));
    connect(actionCreateAccount,SIGNAL(triggered(bool)),this,SLOT(wyswietlDodajKonto()));
    connect(actionAddMoney,SIGNAL(triggered(bool)),this,SLOT(wyswieltDodajPieniadze()));
    connect(actionInformation,SIGNAL(triggered(bool)),this,SLOT(wyswietlOProgramie()));

    //--------Przyciski do obsługi karty oraz odbioru pieniędzy--------//
    connect(przyciskUzytoKarte,SIGNAL(clicked(bool)),this,SLOT(przyciskUzytoKarteKliknieto()));
    connect(przyciskUzytoKarte,SIGNAL(dropped()),this,SLOT(upuszczonoKarteKliknieto()));
    connect(przyciskPieniadze,SIGNAL(clicked(bool)),this,SLOT(przyciskPieniadzeKliknieto()));
}

Widget::~Widget()
{
    delete rdzen;

    //----Zmienne od paska menu----//
    delete actionCardUsed;
    delete actionReset;
    delete actionExit;
    delete actionCreateAccount;
    delete actionAddMoney;
    delete actionInformation;
    delete menuCashMachine;
    delete menuAccounts;
    delete menuHelp;
    delete menuBar;

    //----Okno do wyświetlania----//
    delete window;
    delete field;
    delete title;
    delete optionA;
    delete optionB;
    delete optionC;
    delete optionD;
    delete optionE;
    delete optionF;
    delete optionG;
    delete optionH;

    //----Przyciski do obsługi----//
    delete buttonA;
    delete buttonB;
    delete buttonC;
    delete buttonD;
    delete buttonE;
    delete buttonF;
    delete buttonG;
    delete buttonH;

    //----Przyciski klawiatury----//
    delete przycisk1;
    delete przycisk2;
    delete przycisk3;
    delete przycisk4;
    delete przycisk5;
    delete przycisk6;
    delete przycisk7;
    delete przycisk8;
    delete przycisk9;
    delete przycisk0;
    delete przyciskCofnij;

    //----Przyciski od karty i pieniędzy----//
    delete przyciskUzytoKarte;
    delete przyciskPieniadze;

    //----Tablica gdzie będzie wyświetlana wypłata----//
    delete tablicaWyplaty;

    delete ui;
}

//----Pokazuje okienko z informacjami o programie----//
void Widget::wyswietlOProgramie()
{
    rdzen->wyswietlOProgramie();
}

//----Wyświetla okienko gdzie można utworzyć konto do testów----//
void Widget::wyswietlDodajKonto()
{
    rdzen->wyswietlDodajKonto();
}

//----Pokazuje okienko gdzie można dołożyć pieniądze do bankomatu----//
void Widget::wyswieltDodajPieniadze()
{
    rdzen->wyswietlDodajPieniadze();
}

//----Wyświetla odpowiedni ekran zależnie od stanu bankomatu----//
void Widget::wyswietlEkran(CRdzen::StanBankomatu stan)
{
    if(rdzen->zwrocCzyZmienionoStanBankomatu() == true)
    {
        switch(stan)
        {
        case CRdzen::wlozKarte:
            aktywujPrzyciskiKarty();
            ustawTekst("Witaj w bankomacie. Proszę włożyć kartę.","","","","","","","","");
            break;
        case CRdzen::brakSrodkowWBankomacie:
            ustawTekst("Przepraszamy bankomat nieczynny","","","","","","","","");
            break;
        case CRdzen::niepoprawnyPlikKarty:
            deaktywujPrzyciskiKarty();
            wait = true;
            ustawTekst("Trwa odczyt danych z karty proszę czekać...","","","","","","","","");
            QTimer::singleShot(3000,([&](){ustawTekst("Nie można odczytać danych z karty upewnij się, że karta nie jest nieuszkodzona.","Cofnij","","","","","","",""); wait = false;}));
            break;
        case CRdzen::podajPin:
            deaktywujPrzyciskiKarty();
            if(isCardLoaded == false)
            {
                isCardLoaded = true;
                wait = true;
                ustawTekst("Trwa odczyt danych z karty proszę czekać...","","","","","","","","");
                QTimer::singleShot(3000,([&](){ustawTekst("Podaj PIN","","","","","Zatwierdź","","",""); wait = false;}));
            }
            else
            {
                ustawTekst("Podaj PIN","","","","","Zatwierdź","","","");
            }
            break;
        case CRdzen::niepoprawnyPin:
            field->setText(""); //Usunięcie wprowadzonego PINu z pola po niepoprawnym wprowadzdeniu
            wait = true;
            ustawTekst("Trwa sprawdzanie poprawności PINu, proszę czekać...","","","","","","","","");
            QTimer::singleShot(1500,([&](){ustawTekst("Pin niepoprawny spróbuj jeszcze raz.","Cofnij","","","","","","",""); wait = false;}));
            break;
        case CRdzen::kartaZablokowana:
            deaktywujPrzyciskiKarty();
            field->setText(""); //Usunięcie wprowadzonego PINu z pola po niepoprawnym wprowadzdeniu
            wait = true;
            ustawTekst("Trwa sprawdzanie poprawności PINu, proszę czekać...","","","","","","","","");
            QTimer::singleShot(1500,([&]() {ustawTekst("Z uwagi na trzykrotnie złe wpisanie PINu karta została zablokowana.","Cofnij","","","","","","",""); wait = false;}));
            break;
        case CRdzen::wybierzOperacje:
            if(isAccountLoaded == false)
            {
                isAccountLoaded = true;
                field->setText(""); //Usunięcie wprowadzonego PINu z pola
                wait = true;
                ustawTekst("Trwa sprawdzanie poprawności PINu, proszę czekać...","","","","","","","","");
                QTimer::singleShot(1500,([&]() {ustawTekst("Proszę wybrać operację","Wyjmij kartę","Pok. nr. konta","","","Saldo","Wypłata","Zmień PIN",""); wait = false;}));
            }
            else
            {
                field->setText(""); //Usunięcie wprowadzonego PINu z pola
                ustawTekst("Proszę wybrać operację","Wyjmij kartę","Pok. nr. konta","","","Saldo","Wypłata","Zmień PIN","");
            }
            break;
        case CRdzen::zmienPin:
            ustawTekst("Podaj nowy czterocyfrowy PIN.","Cofnij","","","","Zatwierdź","","","");
            break;
        case CRdzen::zmienionoPin:
            field->setText("");
            ustawTekst("PIN został zmieniony.","Cofnij","","","","","","","");
            break;
        case CRdzen::pokazNumerKonta:
            field->setText(rdzen->zwrocNumerKonta());
            ustawTekst("Oto numer twojego konta","","Cofnij","","","","Wyjmij kartę","","");
            break;
        case CRdzen::wyswietlSaldo:
            field->setText(QString::number(rdzen->zwrocStanKonta(),'f',2) + " zł");
            ustawTekst("Stan twojego konta wynosi:","Wyjmij kartę","","","","Cofnij","Wypłata","","");
            break;
        case CRdzen::wyplacGotowke:
            field->setText("");
            ustawTekst("Proszę wpisać żądaną ilość gotówki do wypłaty. Maksymalnie 3000 zł.","Cofnij","","","","Wypłać","","","");
            break;
        case CRdzen::wybierzGotowke:
        {
            przyciskPieniadze->setEnabled(true);
            field->setText(""); //Usunięcie wprowadzonego PINu z pola
            ustawTekst("Proszę odebrać pieniądze..","","","","","","","","");
            QVector<int> wyplata = rdzen->odbierzPieniadze();
            wyswietlWyplate(wyplata);;
            break;
        }
        case CRdzen::brakGotowki:
            field->setText(""); //Usunięcie wprowadzonego PINu z pola
            ustawTekst("Nie masz wystarczającej ilości środków na koncie","Cofnij","","","","","","","");
            break;
        case CRdzen::wyjmijKarte:
            isCardLoaded = false;
            isAccountLoaded = false;
            field->setText("");
            aktywujPrzyciskiKarty();
            ustawTekst("Dziękujemy za skorzystanie z naszego bankomatu. Proszę odebreć kartę.","","","","","","","","");
            break;
        default:
            break;
        }
    }
}

//----Wyświetla wypłacone pieniądze w elemencie QTableWidget----//
void Widget::wyswietlWyplate(QVector<int> pieniadze)
{
    tablicaWyplaty->setItem(0,0,new QTableWidgetItem(QString::number(pieniadze[0])));
    tablicaWyplaty->setItem(1,0,new QTableWidgetItem(QString::number(pieniadze[1])));
    tablicaWyplaty->setItem(2,0,new QTableWidgetItem(QString::number(pieniadze[2])));
    tablicaWyplaty->setItem(3,0,new QTableWidgetItem(QString::number(pieniadze[3])));
    tablicaWyplaty->setItem(4,0,new QTableWidgetItem(QString::number(pieniadze[4])));
    tablicaWyplaty->setItem(5,0,new QTableWidgetItem(QString::number(pieniadze[5])));
    tablicaWyplaty->setItem(6,0,new QTableWidgetItem(QString::number(pieniadze[6])));
    tablicaWyplaty->setItem(7,0,new QTableWidgetItem(QString::number(pieniadze[7])));
}

//----Czyści tablice QTableWidget----//
void Widget::wyczyscTabliceWyplaty()
{
    tablicaWyplaty->clear();
    QStringList listaWierszy;
    listaWierszy << "200zł" << "100zł" << "50zł" << "20zł" << "10zł" << "5zł" << "2zł" << "1zł" ;
    tablicaWyplaty->setVerticalHeaderLabels(listaWierszy);
    QStringList listaKolumn;
    listaKolumn << "Ilość";
    tablicaWyplaty->setHorizontalHeaderLabels(listaKolumn);
}

//--------Funkcje obsługi kliknięć przycisków funkcyjnych bankomatu--------//
void Widget::przyciskAKliknieto()
{
    if(wait == false)
    {
        wyswietlEkran(rdzen->przyciskAKliknieto());
    }
}

void Widget::przyciskBKliknieto()
{
    if(wait == false)
    {
        wyswietlEkran(rdzen->przyciskBKliknieto());
    }
}

void Widget::przyciskCKliknieto()
{
    if(wait == false)
    {
        wyswietlEkran(rdzen->przyciskCKliknieto());
    }
}

void Widget::przyciskDKliknieto()
{
    if(wait == false)
    {
        wyswietlEkran(rdzen->przyciskDKliknieto());
    }
}

void Widget::przyciskEKliknieto()
{
    if(wait == false)
    {
        wyswietlEkran(rdzen->przyciskEKliknieto());
    }
}

void Widget::przyciskFKliknieto()
{
    if(wait == false)
    {
        wyswietlEkran(rdzen->przyciskFKliknieto());
    }
}

void Widget::przyciskGKliknieto()
{
    if(wait == false)
    {
        wyswietlEkran(rdzen->przyciskGKliknieto());
    }
}

void Widget::przyciskHKliknieto()
{
    if(wait == false)
    {
        wyswietlEkran(rdzen->przyciskHKliknieto());
    }
}

//--------Przyciski obsługi kliknieć przycisków numerycznych bankomatu--------//
void Widget::przyciskNumerycznyKliknieto(int wartosc)
{
    rdzen->przyciskKliknieto(wartosc);
    ustawPoleWartosci();
}

void Widget::przycisk1Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(1);
    }
}

void Widget::przycisk2Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(2);
    }
}

void Widget::przycisk3Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(3);
    }
}

void Widget::przycisk4Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(4);
    }
}

void Widget::przycisk5Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(5);
    }
}

void Widget::przycisk6Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(6);
    }
}

void Widget::przycisk7Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(7);
    }
}

void Widget::przycisk8Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(8);
    }
}

void Widget::przycisk9Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(9);
    }
}

void Widget::przycisk0Kliknieto()
{
    if(wait == false)
    {
        przyciskNumerycznyKliknieto(0);
    }
}

void Widget::przyciskCofnijKliknieto()
{
    if(wait == false)
    {
        rdzen->przyciskCofnijKliknieto();
        ustawPoleWartosci();
    }
}

//----Funkcja obsługi kliknięcia przycisku "Karta"----//
void Widget::przyciskUzytoKarteKliknieto()
{
    if(wait == false)
    {
        if((rdzen->zwrocStanBankomatu() == CRdzen::wlozKarte) || (rdzen->zwrocStanBankomatu() == CRdzen::wyjmijKarte))
        {
            rdzen->uzytoKarte();
            wyswietlEkran(rdzen->zwrocStanBankomatu());
        }
    }
}

//----Funkcja obsługi upuszczenia na przycisk----//
void Widget::upuszczonoKarteKliknieto()
{
    if(wait == false)
    {
        if(rdzen->zwrocStanBankomatu() == CRdzen::wlozKarte)
        {
            rdzen->uzytoKarte(przyciskUzytoKarte->getDirectory());
            wyswietlEkran(rdzen->zwrocStanBankomatu());
        }
    }
}

//----Funkcja obsługi kliknięcia przycisku "Odbierz pieniądze"----//
void Widget::przyciskPieniadzeKliknieto()
{
    if(wait == false)
    {
        if(rdzen->zwrocStanBankomatu() == CRdzen::wybierzGotowke)
        {
            rdzen->odebranoPieniadze();
            wyczyscTabliceWyplaty();
            przyciskPieniadze->setDisabled(true);
            wyswietlEkran(rdzen->zwrocStanBankomatu());
        }
    }
}

//----Ustawia wartość w polu na środku ekranu. Wyświetla pin lub kwotę----//
void Widget::ustawPoleWartosci()
{
    switch(rdzen->zwrocStanBankomatu())
    {
    case CRdzen::podajPin:
    case CRdzen::zmienPin:
        field->setText(rdzen->zwrocPoleZagwiazdkowane());
        break;
    case CRdzen::wyplacGotowke:
        if(rdzen->zwrocPole() != "")
        {
            field->setText(rdzen->zwrocPole() + " zł");
        }
        else
        {
            field->setText("");
        }
        break;
    default:
        break;
    }
}

void Widget::aktywujPrzyciskiKarty()
{
    przyciskUzytoKarte->setEnabled(true);
    actionCardUsed->setEnabled(true);
}

void Widget::deaktywujPrzyciskiKarty()
{
    przyciskUzytoKarte->setDisabled(true);
    actionCardUsed->setDisabled(true);
}

//----Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy----//
void Widget::resetujKliknieto()
{
    rdzen->resetujKliknieto();
    wyswietlEkran(rdzen->zwrocStanBankomatu());
}

//----Ustawia etykiety tekstowe ekranu----//
void Widget::ustawTekst(QString tytul, QString opcjaA, QString opcjaB, QString opcjaC, QString opcjaD, QString opcjaE, QString opcjaF, QString opcjaG, QString opcjaH)
{
    this->title->setText(tytul);
    optionA->setText(opcjaA);
    optionB->setText(opcjaB);
    optionC->setText(opcjaC);
    optionD->setText(opcjaD);
    optionE->setText(opcjaE);
    optionF->setText(opcjaF);
    optionG->setText(opcjaG);
    optionH->setText(opcjaH);
}

//--------Zamyka program po zamknięciu głównego okna--------//
void Widget::closeEvent(QCloseEvent *)
{
    qApp->quit();
}
