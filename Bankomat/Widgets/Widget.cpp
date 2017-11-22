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
    button1 = new QPushButton("1",this);
    button1->setGeometry(404,541,57,57);
    button1->setStyleSheet("font-size:40px;");
    button2 = new QPushButton("2",this);
    button2->setGeometry(471,541,57,57);
    button2->setStyleSheet("font-size:40px;");
    button3 = new QPushButton("3",this);
    button3->setGeometry(538,541,57,57);
    button3->setStyleSheet("font-size:40px;");
    button4 = new QPushButton("4",this);
    button4->setGeometry(404,608,57,57);
    button4->setStyleSheet("font-size:40px;");
    button5 = new QPushButton("5",this);
    button5->setGeometry(471,608,57,57);
    button5->setStyleSheet("font-size:40px;");
    button6 = new QPushButton("6",this);
    button6->setGeometry(538,608,57,57);
    button6->setStyleSheet("font-size:40px;");
    button7 = new QPushButton("7",this);
    button7->setGeometry(404,675,57,57);
    button7->setStyleSheet("font-size:40px;");
    button8 = new QPushButton("8",this);
    button8->setGeometry(471,675,57,57);
    button8->setStyleSheet("font-size:40px;");
    button9 = new QPushButton("9",this);
    button9->setGeometry(538,675,57,57);
    button9->setStyleSheet("font-size:40px;");
    button0 = new QPushButton("0",this);
    button0->setGeometry(471,742,57,57);
    button0->setStyleSheet("font-size:40px;");
    buttonReturn = new QPushButton("←",this);
    buttonReturn->setGeometry(538,742,57,57);
    buttonReturn->setStyleSheet("font-size:40px;");

    //----Przyciski do obsługi karty oraz odbioru pieniędzy----//
    cardUsedButton = new DropButton("Karta",this);
    cardUsedButton->setGeometry(700,541,200,124);
    cardUsedButton->setStyleSheet("font-size:40px;");
    moneyButton = new QPushButton("Odbierz\npieniądze",this);
    moneyButton->setGeometry(700,675,200,124);
    moneyButton->setStyleSheet("font-size:40px;");
    moneyButton->setDisabled(true);

    //----Tworzenie tablicy gdzie będą pokazywane wypłacone nominały----//
    paymentTable = new QTableWidget(this);
    paymentTable->setGeometry(100,541,140,265);
    paymentTable->setColumnCount(1);
    paymentTable->setRowCount(8);
    paymentTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QStringList listaWierszy;
    listaWierszy << "200zł" << "100zł" << "50zł" << "20zł" << "10zł" << "5zł" << "2zł" << "1zł" ;
    paymentTable->setVerticalHeaderLabels(listaWierszy);
    QStringList listaKolumn;
    listaKolumn << "Ilość";
    paymentTable->setHorizontalHeaderLabels(listaKolumn);
    paymentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //----Tworzenie obiektu rdzenia aplikacji----//
    programCore = new CRdzen(this);

    //----Wyświetlenie obecnego ekranu dopasowanego do stanu bankomatu----//
    showCurrentScreen(programCore->zwrocStanBankomatu());

    //----Przypisanie przycisków do slotów----//
    //--------Menu--------//
    connect(actionExit,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
    connect(buttonA,SIGNAL(clicked(bool)),this,SLOT(buttonAPressed()));
    connect(buttonB,SIGNAL(clicked(bool)),this,SLOT(buttonBPressed()));
    connect(buttonC,SIGNAL(clicked(bool)),this,SLOT(buttonCPressed()));
    connect(buttonD,SIGNAL(clicked(bool)),this,SLOT(buttonDPressed()));
    connect(buttonE,SIGNAL(clicked(bool)),this,SLOT(buttonEPressed()));
    connect(buttonF,SIGNAL(clicked(bool)),this,SLOT(buttonFPressed()));
    connect(buttonG,SIGNAL(clicked(bool)),this,SLOT(buttonGPressed()));
    connect(buttonH,SIGNAL(clicked(bool)),this,SLOT(buttonHPressed()));

    //--------Przyciski klawiatury--------//
    connect(button1,SIGNAL(clicked(bool)),this,SLOT(button1Pressed()));
    connect(button2,SIGNAL(clicked(bool)),this,SLOT(button2Pressed()));
    connect(button3,SIGNAL(clicked(bool)),this,SLOT(button3Pressed()));
    connect(button4,SIGNAL(clicked(bool)),this,SLOT(button4Pressed()));
    connect(button5,SIGNAL(clicked(bool)),this,SLOT(button5Pressed()));
    connect(button6,SIGNAL(clicked(bool)),this,SLOT(button6Pressed()));
    connect(button7,SIGNAL(clicked(bool)),this,SLOT(button7Pressed()));
    connect(button8,SIGNAL(clicked(bool)),this,SLOT(button8Pressed()));
    connect(button9,SIGNAL(clicked(bool)),this,SLOT(button9Pressed()));
    connect(button0,SIGNAL(clicked(bool)),this,SLOT(button9Pressed()));
    connect(buttonReturn,SIGNAL(clicked(bool)),this,SLOT(buttonUndoPressed()));

    //--------Akcje--------//
    connect(actionCardUsed,SIGNAL(triggered(bool)),this,SLOT(przyciskUzytoKarteKliknieto()));
    connect(actionReset,SIGNAL(triggered(bool)),this,SLOT(resetujKliknieto()));
    connect(actionCreateAccount,SIGNAL(triggered(bool)),this,SLOT(showWidgetAddAccount()));
    connect(actionAddMoney,SIGNAL(triggered(bool)),this,SLOT(showWidgetAddMoney()));
    connect(actionInformation,SIGNAL(triggered(bool)),this,SLOT(showWidgetAbout()));

    //--------Przyciski do obsługi karty oraz odbioru pieniędzy--------//
    connect(cardUsedButton,SIGNAL(clicked(bool)),this,SLOT(przyciskUzytoKarteKliknieto()));
    connect(cardUsedButton,SIGNAL(dropped()),this,SLOT(upuszczonoKarteKliknieto()));
    connect(moneyButton,SIGNAL(clicked(bool)),this,SLOT(przyciskPieniadzeKliknieto()));
}

Widget::~Widget()
{
    delete programCore;

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
    delete button1;
    delete button2;
    delete button3;
    delete button4;
    delete button5;
    delete button6;
    delete button7;
    delete button8;
    delete button9;
    delete button0;
    delete buttonReturn;

    //----Przyciski od karty i pieniędzy----//
    delete cardUsedButton;
    delete moneyButton;

    //----Tablica gdzie będzie wyświetlana wypłata----//
    delete paymentTable;

    delete ui;
}

//----Pokazuje okienko z informacjami o programie----//
void Widget::showWidgetAbout()
{
    programCore->wyswietlOProgramie();
}

//----Wyświetla okienko gdzie można utworzyć konto do testów----//
void Widget::showWidgetAddAccount()
{
    programCore->wyswietlDodajKonto();
}

//----Pokazuje okienko gdzie można dołożyć pieniądze do bankomatu----//
void Widget::showWidgetAddMoney()
{
    programCore->wyswietlDodajPieniadze();
}

//----Wyświetla odpowiedni ekran zależnie od stanu bankomatu----//
void Widget::showCurrentScreen(CRdzen::StanBankomatu state)
{
    if(programCore->zwrocCzyZmienionoStanBankomatu() == true)
    {
        switch(state)
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
            field->setText(programCore->zwrocNumerKonta());
            ustawTekst("Oto numer twojego konta","","Cofnij","","","","Wyjmij kartę","","");
            break;
        case CRdzen::wyswietlSaldo:
            field->setText(QString::number(programCore->zwrocStanKonta(),'f',2) + " zł");
            ustawTekst("Stan twojego konta wynosi:","Wyjmij kartę","","","","Cofnij","Wypłata","","");
            break;
        case CRdzen::wyplacGotowke:
            field->setText("");
            ustawTekst("Proszę wpisać żądaną ilość gotówki do wypłaty. Maksymalnie 3000 zł.","Cofnij","","","","Wypłać","","","");
            break;
        case CRdzen::wybierzGotowke:
        {
            moneyButton->setEnabled(true);
            field->setText(""); //Usunięcie wprowadzonego PINu z pola
            ustawTekst("Proszę odebrać pieniądze..","","","","","","","","");
            QVector<int> wyplata = programCore->odbierzPieniadze();
            showPayment(wyplata);;
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
void Widget::showPayment(QVector<int> money)
{
    paymentTable->setItem(0,0,new QTableWidgetItem(QString::number(money[0])));
    paymentTable->setItem(1,0,new QTableWidgetItem(QString::number(money[1])));
    paymentTable->setItem(2,0,new QTableWidgetItem(QString::number(money[2])));
    paymentTable->setItem(3,0,new QTableWidgetItem(QString::number(money[3])));
    paymentTable->setItem(4,0,new QTableWidgetItem(QString::number(money[4])));
    paymentTable->setItem(5,0,new QTableWidgetItem(QString::number(money[5])));
    paymentTable->setItem(6,0,new QTableWidgetItem(QString::number(money[6])));
    paymentTable->setItem(7,0,new QTableWidgetItem(QString::number(money[7])));
}

//----Czyści tablice QTableWidget----//
void Widget::clearPaymentTable()
{
    paymentTable->clear();
    QStringList listaWierszy;
    listaWierszy << "200zł" << "100zł" << "50zł" << "20zł" << "10zł" << "5zł" << "2zł" << "1zł" ;
    paymentTable->setVerticalHeaderLabels(listaWierszy);
    QStringList listaKolumn;
    listaKolumn << "Ilość";
    paymentTable->setHorizontalHeaderLabels(listaKolumn);
}

//--------Funkcje obsługi kliknięć przycisków funkcyjnych bankomatu--------//
void Widget::buttonAPressed()
{
    if(wait == false)
    {
        showCurrentScreen(programCore->przyciskAKliknieto());
    }
}

void Widget::buttonBPressed()
{
    if(wait == false)
    {
        showCurrentScreen(programCore->przyciskBKliknieto());
    }
}

void Widget::buttonCPressed()
{
    if(wait == false)
    {
        showCurrentScreen(programCore->przyciskCKliknieto());
    }
}

void Widget::buttonDPressed()
{
    if(wait == false)
    {
        showCurrentScreen(programCore->przyciskDKliknieto());
    }
}

void Widget::buttonEPressed()
{
    if(wait == false)
    {
        showCurrentScreen(programCore->przyciskEKliknieto());
    }
}

void Widget::buttonFPressed()
{
    if(wait == false)
    {
        showCurrentScreen(programCore->przyciskFKliknieto());
    }
}

void Widget::buttonGPressed()
{
    if(wait == false)
    {
        showCurrentScreen(programCore->przyciskGKliknieto());
    }
}

void Widget::buttonHPressed()
{
    if(wait == false)
    {
        showCurrentScreen(programCore->przyciskHKliknieto());
    }
}

//--------Przyciski obsługi kliknieć przycisków numerycznych bankomatu--------//
void Widget::buttonNumberPressed(int value)
{
    programCore->przyciskKliknieto(value);
    ustawPoleWartosci();
}

void Widget::button1Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(1);
    }
}

void Widget::button2Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(2);
    }
}

void Widget::button3Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(3);
    }
}

void Widget::button4Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(4);
    }
}

void Widget::button5Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(5);
    }
}

void Widget::button6Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(6);
    }
}

void Widget::button7Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(7);
    }
}

void Widget::button8Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(8);
    }
}

void Widget::button9Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(9);
    }
}

void Widget::button0Pressed()
{
    if(wait == false)
    {
        buttonNumberPressed(0);
    }
}

void Widget::buttonUndoPressed()
{
    if(wait == false)
    {
        programCore->przyciskCofnijKliknieto();
        ustawPoleWartosci();
    }
}

//----Funkcja obsługi kliknięcia przycisku "Karta"----//
void Widget::przyciskUzytoKarteKliknieto()
{
    if(wait == false)
    {
        if((programCore->zwrocStanBankomatu() == CRdzen::wlozKarte) || (programCore->zwrocStanBankomatu() == CRdzen::wyjmijKarte))
        {
            programCore->uzytoKarte();
            showCurrentScreen(programCore->zwrocStanBankomatu());
        }
    }
}

//----Funkcja obsługi upuszczenia na przycisk----//
void Widget::upuszczonoKarteKliknieto()
{
    if(wait == false)
    {
        if(programCore->zwrocStanBankomatu() == CRdzen::wlozKarte)
        {
            programCore->uzytoKarte(cardUsedButton->getDirectory());
            showCurrentScreen(programCore->zwrocStanBankomatu());
        }
    }
}

//----Funkcja obsługi kliknięcia przycisku "Odbierz pieniądze"----//
void Widget::przyciskPieniadzeKliknieto()
{
    if(wait == false)
    {
        if(programCore->zwrocStanBankomatu() == CRdzen::wybierzGotowke)
        {
            programCore->odebranoPieniadze();
            clearPaymentTable();
            moneyButton->setDisabled(true);
            showCurrentScreen(programCore->zwrocStanBankomatu());
        }
    }
}

//----Ustawia wartość w polu na środku ekranu. Wyświetla pin lub kwotę----//
void Widget::ustawPoleWartosci()
{
    switch(programCore->zwrocStanBankomatu())
    {
    case CRdzen::podajPin:
    case CRdzen::zmienPin:
        field->setText(programCore->zwrocPoleZagwiazdkowane());
        break;
    case CRdzen::wyplacGotowke:
        if(programCore->zwrocPole() != "")
        {
            field->setText(programCore->zwrocPole() + " zł");
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
    cardUsedButton->setEnabled(true);
    actionCardUsed->setEnabled(true);
}

void Widget::deaktywujPrzyciskiKarty()
{
    cardUsedButton->setDisabled(true);
    actionCardUsed->setDisabled(true);
}

//----Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy----//
void Widget::resetujKliknieto()
{
    programCore->resetujKliknieto();
    showCurrentScreen(programCore->zwrocStanBankomatu());
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
