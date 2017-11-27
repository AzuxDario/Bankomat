#include "WidgetAddAccount.h"
#include "ui_widgetdodajkonto.h"

WidgetAddAccount::WidgetAddAccount(WidgetWindow *parent) :
    WidgetWindow(parent),
    ui(new Ui::WidgetDodajKonto)
{
    ui->setupUi(this);

    //----Inicjalizacja okna----//
    setWindowTitle(QString::fromUtf8("Załóż konto"));
    setWindowIcon(QIcon(":/bankomat/ikona"));
    setMaximumSize(300,250);
    setMinimumSize(300,250);

    //----Przyciski----//
    buttonOk = new QPushButton("Utwórz",this);
    buttonOk->setGeometry(25,205,100,30);
    buttonCancel = new QPushButton("Anuluj",this);
    buttonCancel->setGeometry(175,205,100,30);

    //----Labele opsiujące pola----//
    name = new QLabel("Imie");
    surname = new QLabel("Nazwisko");
    pin = new QLabel("PIN");
    balance = new QLabel("Stan konta");

    //----Pola do wpisania wartości----//
    lineEditName = new QLineEdit();
    lineEditSurname = new QLineEdit();
    spinBoxPin = new QSpinBox();
    spinBoxBalance = new QDoubleSpinBox();

    spinBoxPin->setMinimum(1000);
    spinBoxPin->setMaximum(9999);

    spinBoxBalance->setMaximum(50000);

    //----Layout----//
    layout = new QGridLayout();
    layout->addWidget(name,0,0);
    layout->addWidget(surname,1,0);
    layout->addWidget(pin,2,0);
    layout->addWidget(balance,3,0);
    layout->addWidget(lineEditName,0,1);
    layout->addWidget(lineEditSurname,1,1);
    layout->addWidget(spinBoxPin,2,1);
    layout->addWidget(spinBoxBalance,3,1);

    //----GroupBox----//
    group = new QGroupBox("Podaj dane",this);
    group->setGeometry(10,10,280,190);
    group->setLayout(layout);

    card = nullptr;
    account = nullptr;

    //----Przypisanie przycisków do slotów----//
    connect(buttonOk,SIGNAL(clicked(bool)),this,SLOT(closeWindowOk()));
    connect(buttonCancel,SIGNAL(clicked(bool)),this,SLOT(closeWindowCancel()));

    this->showWindow();
}

WidgetAddAccount::~WidgetAddAccount()
{

}

//----Zamyka okno zachowując zmiany----//
void WidgetAddAccount::closeWindowOk()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Wybierz miejsce do zapisuj karty","","Karta (*.card)");
    if(fileName != "")
    {
        createAccount(fileName);
        int messageValue;
        QMessageBox message("Informacja","Utworzono konto",QMessageBox::Information,QMessageBox::Ok|QMessageBox::Default,0,0);
        messageValue = message.exec();
        if(messageValue == QMessageBox::Ok)
        {
            message.close();
        }
        clearFields();
        this->close();
    }
}

//----Zamyka okno nie zachowując zmian----//
void WidgetAddAccount::closeWindowCancel()
{
    clearFields();
    this->close();
}

//----Zamyka okno nie zachowując zmian----//
void WidgetAddAccount::closeEvent(QCloseEvent *)
{
    clearFields();
    this->close();
}

//----Zeruje wartości w polach----//
void WidgetAddAccount::clearFields()
{
    lineEditName->setText("");
    lineEditSurname->setText("");
    spinBoxPin->setValue(1000);
    spinBoxBalance->setValue(0);
}

//----Procedura zapisu plików karty i konta----//
bool WidgetAddAccount::createAccount(QString fileName)
{
    bool returnValue = true;
    QString accountNumber = "223434678" + QDate::currentDate().toString("yyyyMMdd") + QTime::currentTime().toString("HHmmsszzz");
    QString cardNumber = "22" + QDate::currentDate().toString("yyyyMMdd") + QTime::currentTime().toString("HHmmss");
    account = new Account();
    account->setName(lineEditName->text());
    account->setSurname(lineEditSurname->text());
    account->setAccountNumber(accountNumber);
    account->setBalance(spinBoxBalance->value());
    returnValue = account->writeAccount();
    delete account;
    card = new Card();
    card->setCardNumber(cardNumber);
    card->setIsCardBlocked(false);
    card->setAccountNumber(accountNumber);
    card->setPin(spinBoxPin->value());
    card->setCardFilePath(fileName);
    returnValue = card->saveCardFile();
    delete card;
    return returnValue;
}
