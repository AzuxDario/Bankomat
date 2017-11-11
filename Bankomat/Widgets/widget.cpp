#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    czekaj = false;
    czyKartaZaladowana = false;
    czyKontoZaladowane = false;

    //----Tworzenie paska menu----//
    pasekMenu = new QMenuBar(this);
    pasekMenu->setGeometry(0,0,1200,21);
    pasekBankomat = new QMenu(this);
    pasekKonta = new QMenu(this);
    pasekPomoc = new QMenu(this);

    pasekBankomat = pasekMenu->addMenu(tr("&Bankomat"));
    pasekKonta = pasekMenu->addMenu(tr("&Konta"));
    pasekPomoc = pasekMenu->addMenu(tr("&Pomoc"));

    //----Tworzenie akcji do paska menu----//
    akcjaUzytoKarte = new QAction("K&arta");
    akcjaUzytoKarte->setShortcut(QKeySequence(tr("Ctrl+A")));
    akcjaResetuj = new QAction("&Resetuj",this);
    akcjaResetuj->setShortcut(QKeySequence(tr("Ctrl+R")));
    akcjaWyjscie = new QAction("Wyjści&e",this);
    akcjaWyjscie->setShortcut(QKeySequence(tr("Ctrl+W")));
    akcjaZalozKonto = new QAction("&Załóż konto",this);
    akcjaZalozKonto->setShortcut(QKeySequence(tr("Ctrl+Z")));
    akcjaDodajPieniadze = new QAction("&Dodaj pieniądze");
    akcjaDodajPieniadze->setShortcut(QKeySequence(tr("Ctrl+D")));
    akcjaInformacje = new QAction("&Informacje",this);
    akcjaInformacje->setShortcut(QKeySequence(tr("Ctrl+I")));

    //----Przypisywnaia akcji do paska menu----//
    pasekBankomat->addAction(akcjaUzytoKarte);
    pasekBankomat->addAction(akcjaResetuj);
    pasekBankomat->addSeparator();
    pasekBankomat->addAction(akcjaWyjscie);
    pasekKonta->addAction(akcjaZalozKonto);
    pasekKonta->addSeparator();
    pasekKonta->addAction(akcjaDodajPieniadze);
    pasekPomoc->addAction(akcjaInformacje);

    //----Tworzenie okna gdzie będzie wyświetlane tło----//
    okno = new QLabel(this);
    okno->setGeometry(100,31,800,500);
    okno->setPixmap(QPixmap(":/bankomat/tło"));

    //----Tworzenie pola do wyświetlania pinu oraz kwoty do wypłaty----//
    pole = new QLabel(this);
    pole->setGeometry(200,200,600,35);
    pole->setStyleSheet("color:white;font-size:40px;");
    pole->setAlignment(Qt::AlignCenter);

    //----Tworzenie pól tekstowych na ekranie----//
    tytul = new QLabel(this);
    tytul->setGeometry(120,51,760,200);
    tytul->setStyleSheet("color:white;font-size:40px;");
    tytul->setWordWrap(true);
    tytul->setAlignment(Qt::AlignTop);

    podpisA = new QLabel(this);
    podpisA->setGeometry(120,211,380,60);
    podpisA->setStyleSheet("color:white;font-size:40px;");
    podpisB = new QLabel(this);
    podpisB->setGeometry(120,291,380,60);
    podpisB->setStyleSheet("color:white;font-size:40px;");
    podpisC = new QLabel(this);
    podpisC->setGeometry(120,371,380,60);
    podpisC->setStyleSheet("color:white;font-size:40px;");
    podpisD = new QLabel(this);
    podpisD->setGeometry(120,451,380,60);
    podpisD->setStyleSheet("color:white;font-size:40px;");
    podpisE = new QLabel(this);
    podpisE->setGeometry(500,211,380,60);
    podpisE->setStyleSheet("color:white;font-size:40px;");
    podpisE->setAlignment(Qt::AlignRight);
    podpisF = new QLabel(this);
    podpisF->setGeometry(500,291,380,60);
    podpisF->setStyleSheet("color:white;font-size:40px;");
    podpisF->setAlignment(Qt::AlignRight);
    podpisG = new QLabel(this);
    podpisG->setGeometry(500,371,380,60);
    podpisG->setStyleSheet("color:white;font-size:40px;");
    podpisG->setAlignment(Qt::AlignRight);
    podpisH = new QLabel(this);
    podpisH->setGeometry(500,451,380,60);
    podpisH->setStyleSheet("color:white;font-size:40px;");
    podpisH->setAlignment(Qt::AlignRight);

    //----Przyciski do obsługi----//
    przyciskA = new QPushButton(this);
    przyciskA->setGeometry(10,211,80,60);
    przyciskB = new QPushButton(this);
    przyciskB->setGeometry(10,291,80,60);
    przyciskC = new QPushButton(this);
    przyciskC->setGeometry(10,371,80,60);
    przyciskD = new QPushButton(this);
    przyciskD->setGeometry(10,451,80,60);
    przyciskE = new QPushButton(this);
    przyciskE->setGeometry(910,211,80,60);
    przyciskF = new QPushButton(this);
    przyciskF->setGeometry(910,291,80,60);
    przyciskG = new QPushButton(this);
    przyciskG->setGeometry(910,371,80,60);
    przyciskH = new QPushButton(this);
    przyciskH->setGeometry(910,451,80,60);

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
    connect(akcjaWyjscie,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
    connect(przyciskA,SIGNAL(clicked(bool)),this,SLOT(przyciskAKliknieto()));
    connect(przyciskB,SIGNAL(clicked(bool)),this,SLOT(przyciskBKliknieto()));
    connect(przyciskC,SIGNAL(clicked(bool)),this,SLOT(przyciskCKliknieto()));
    connect(przyciskD,SIGNAL(clicked(bool)),this,SLOT(przyciskDKliknieto()));
    connect(przyciskE,SIGNAL(clicked(bool)),this,SLOT(przyciskEKliknieto()));
    connect(przyciskF,SIGNAL(clicked(bool)),this,SLOT(przyciskFKliknieto()));
    connect(przyciskG,SIGNAL(clicked(bool)),this,SLOT(przyciskGKliknieto()));
    connect(przyciskH,SIGNAL(clicked(bool)),this,SLOT(przyciskHKliknieto()));

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
    connect(akcjaUzytoKarte,SIGNAL(triggered(bool)),this,SLOT(przyciskUzytoKarteKliknieto()));
    connect(akcjaResetuj,SIGNAL(triggered(bool)),this,SLOT(resetujKliknieto()));
    connect(akcjaZalozKonto,SIGNAL(triggered(bool)),this,SLOT(wyswietlDodajKonto()));
    connect(akcjaDodajPieniadze,SIGNAL(triggered(bool)),this,SLOT(wyswieltDodajPieniadze()));
    connect(akcjaInformacje,SIGNAL(triggered(bool)),this,SLOT(wyswietlOProgramie()));

    //--------Przyciski do obsługi karty oraz odbioru pieniędzy--------//
    connect(przyciskUzytoKarte,SIGNAL(clicked(bool)),this,SLOT(przyciskUzytoKarteKliknieto()));
    connect(przyciskUzytoKarte,SIGNAL(upuszczono()),this,SLOT(upuszczonoKarteKliknieto()));
    connect(przyciskPieniadze,SIGNAL(clicked(bool)),this,SLOT(przyciskPieniadzeKliknieto()));
}

Widget::~Widget()
{
    delete rdzen;

    //----Zmienne od paska menu----//
    delete akcjaUzytoKarte;
    delete akcjaResetuj;
    delete akcjaWyjscie;
    delete akcjaZalozKonto;
    delete akcjaDodajPieniadze;
    delete akcjaInformacje;
    delete pasekBankomat;
    delete pasekKonta;
    delete pasekPomoc;
    delete pasekMenu;

    //----Okno do wyświetlania----//
    delete okno;
    delete pole;
    delete tytul;
    delete podpisA;
    delete podpisB;
    delete podpisC;
    delete podpisD;
    delete podpisE;
    delete podpisF;
    delete podpisG;
    delete podpisH;

    //----Przyciski do obsługi----//
    delete przyciskA;
    delete przyciskB;
    delete przyciskC;
    delete przyciskD;
    delete przyciskE;
    delete przyciskF;
    delete przyciskG;
    delete przyciskH;

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
            czekaj = true;
            ustawTekst("Trwa odczyt danych z karty proszę czekać...","","","","","","","","");
            QTimer::singleShot(3000,([&](){ustawTekst("Nie można odczytać danych z karty upewnij się, że karta nie jest nieuszkodzona.","Cofnij","","","","","","",""); czekaj = false;}));
            break;
        case CRdzen::podajPin:
            deaktywujPrzyciskiKarty();
            if(czyKartaZaladowana == false)
            {
                czyKartaZaladowana = true;
                czekaj = true;
                ustawTekst("Trwa odczyt danych z karty proszę czekać...","","","","","","","","");
                QTimer::singleShot(3000,([&](){ustawTekst("Podaj PIN","","","","","Zatwierdź","","",""); czekaj = false;}));
            }
            else
            {
                ustawTekst("Podaj PIN","","","","","Zatwierdź","","","");
            }
            break;
        case CRdzen::niepoprawnyPin:
            pole->setText(""); //Usunięcie wprowadzonego PINu z pola po niepoprawnym wprowadzdeniu
            czekaj = true;
            ustawTekst("Trwa sprawdzanie poprawności PINu, proszę czekać...","","","","","","","","");
            QTimer::singleShot(1500,([&](){ustawTekst("Pin niepoprawny spróbuj jeszcze raz.","Cofnij","","","","","","",""); czekaj = false;}));
            break;
        case CRdzen::kartaZablokowana:
            deaktywujPrzyciskiKarty();
            pole->setText(""); //Usunięcie wprowadzonego PINu z pola po niepoprawnym wprowadzdeniu
            czekaj = true;
            ustawTekst("Trwa sprawdzanie poprawności PINu, proszę czekać...","","","","","","","","");
            QTimer::singleShot(1500,([&]() {ustawTekst("Z uwagi na trzykrotnie złe wpisanie PINu karta została zablokowana.","Cofnij","","","","","","",""); czekaj = false;}));
            break;
        case CRdzen::wybierzOperacje:
            if(czyKontoZaladowane == false)
            {
                czyKontoZaladowane = true;
                pole->setText(""); //Usunięcie wprowadzonego PINu z pola
                czekaj = true;
                ustawTekst("Trwa sprawdzanie poprawności PINu, proszę czekać...","","","","","","","","");
                QTimer::singleShot(1500,([&]() {ustawTekst("Proszę wybrać operację","Wyjmij kartę","Pok. nr. konta","","","Saldo","Wypłata","Zmień PIN",""); czekaj = false;}));
            }
            else
            {
                pole->setText(""); //Usunięcie wprowadzonego PINu z pola
                ustawTekst("Proszę wybrać operację","Wyjmij kartę","Pok. nr. konta","","","Saldo","Wypłata","Zmień PIN","");
            }
            break;
        case CRdzen::zmienPin:
            ustawTekst("Podaj nowy czterocyfrowy PIN.","Cofnij","","","","Zatwierdź","","","");
            break;
        case CRdzen::zmienionoPin:
            pole->setText("");
            ustawTekst("PIN został zmieniony.","Cofnij","","","","","","","");
            break;
        case CRdzen::pokazNumerKonta:
            pole->setText(rdzen->zwrocNumerKonta());
            ustawTekst("Oto numer twojego konta","","Cofnij","","","","Wyjmij kartę","","");
            break;
        case CRdzen::wyswietlSaldo:
            pole->setText(QString::number(rdzen->zwrocStanKonta(),'f',2) + " zł");
            ustawTekst("Stan twojego konta wynosi:","Wyjmij kartę","","","","Cofnij","Wypłata","","");
            break;
        case CRdzen::wyplacGotowke:
            pole->setText("");
            ustawTekst("Proszę wpisać żądaną ilość gotówki do wypłaty. Maksymalnie 3000 zł.","Cofnij","","","","Wypłać","","","");
            break;
        case CRdzen::wybierzGotowke:
        {
            przyciskPieniadze->setEnabled(true);
            pole->setText(""); //Usunięcie wprowadzonego PINu z pola
            ustawTekst("Proszę odebrać pieniądze..","","","","","","","","");
            QVector<int> wyplata = rdzen->odbierzPieniadze();
            wyswietlWyplate(wyplata);;
            break;
        }
        case CRdzen::brakGotowki:
            pole->setText(""); //Usunięcie wprowadzonego PINu z pola
            ustawTekst("Nie masz wystarczającej ilości środków na koncie","Cofnij","","","","","","","");
            break;
        case CRdzen::wyjmijKarte:
            czyKartaZaladowana = false;
            czyKontoZaladowane = false;
            pole->setText("");
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
    if(czekaj == false)
    {
        wyswietlEkran(rdzen->przyciskAKliknieto());
    }
}

void Widget::przyciskBKliknieto()
{
    if(czekaj == false)
    {
        wyswietlEkran(rdzen->przyciskBKliknieto());
    }
}

void Widget::przyciskCKliknieto()
{
    if(czekaj == false)
    {
        wyswietlEkran(rdzen->przyciskCKliknieto());
    }
}

void Widget::przyciskDKliknieto()
{
    if(czekaj == false)
    {
        wyswietlEkran(rdzen->przyciskDKliknieto());
    }
}

void Widget::przyciskEKliknieto()
{
    if(czekaj == false)
    {
        wyswietlEkran(rdzen->przyciskEKliknieto());
    }
}

void Widget::przyciskFKliknieto()
{
    if(czekaj == false)
    {
        wyswietlEkran(rdzen->przyciskFKliknieto());
    }
}

void Widget::przyciskGKliknieto()
{
    if(czekaj == false)
    {
        wyswietlEkran(rdzen->przyciskGKliknieto());
    }
}

void Widget::przyciskHKliknieto()
{
    if(czekaj == false)
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
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(1);
    }
}

void Widget::przycisk2Kliknieto()
{
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(2);
    }
}

void Widget::przycisk3Kliknieto()
{
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(3);
    }
}

void Widget::przycisk4Kliknieto()
{
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(4);
    }
}

void Widget::przycisk5Kliknieto()
{
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(5);
    }
}

void Widget::przycisk6Kliknieto()
{
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(6);
    }
}

void Widget::przycisk7Kliknieto()
{
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(7);
    }
}

void Widget::przycisk8Kliknieto()
{
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(8);
    }
}

void Widget::przycisk9Kliknieto()
{
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(9);
    }
}

void Widget::przycisk0Kliknieto()
{
    if(czekaj == false)
    {
        przyciskNumerycznyKliknieto(0);
    }
}

void Widget::przyciskCofnijKliknieto()
{
    if(czekaj == false)
    {
        rdzen->przyciskCofnijKliknieto();
        ustawPoleWartosci();
    }
}

//----Funkcja obsługi kliknięcia przycisku "Karta"----//
void Widget::przyciskUzytoKarteKliknieto()
{
    if(czekaj == false)
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
    if(czekaj == false)
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
    if(czekaj == false)
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
        pole->setText(rdzen->zwrocPoleZagwiazdkowane());
        break;
    case CRdzen::wyplacGotowke:
        if(rdzen->zwrocPole() != "")
        {
            pole->setText(rdzen->zwrocPole() + " zł");
        }
        else
        {
            pole->setText("");
        }
        break;
    default:
        break;
    }
}

void Widget::aktywujPrzyciskiKarty()
{
    przyciskUzytoKarte->setEnabled(true);
    akcjaUzytoKarte->setEnabled(true);
}

void Widget::deaktywujPrzyciskiKarty()
{
    przyciskUzytoKarte->setDisabled(true);
    akcjaUzytoKarte->setDisabled(true);
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
    this->tytul->setText(tytul);
    podpisA->setText(opcjaA);
    podpisB->setText(opcjaB);
    podpisC->setText(opcjaC);
    podpisD->setText(opcjaD);
    podpisE->setText(opcjaE);
    podpisF->setText(opcjaF);
    podpisG->setText(opcjaG);
    podpisH->setText(opcjaH);
}

//--------Zamyka program po zamknięciu głównego okna--------//
void Widget::closeEvent(QCloseEvent *)
{
    qApp->quit();
}
