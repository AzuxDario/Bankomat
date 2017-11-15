#include "WidgetAddMoney.h"
#include "ui_widgetdodajpieniadze.h"

WidgetAddMoney::WidgetAddMoney(MoneyBox *moneyBox, WidgetWindow *parent) :
    WidgetWindow(parent),
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
    buttonOk = new QPushButton("Ok",this);
    buttonOk->setGeometry(100,315,100,30);
    buttonCancel = new QPushButton("Anuluj",this);
    buttonCancel->setGeometry(250,315,100,30);

    //----Pola gdzie będzie wartość obecna----//
    labelPresent200 = new QLabel("200 zł");
    labelPresent100 = new QLabel("100 zł");
    labelPresent50 = new QLabel("50 zł");
    labelPresent20 = new QLabel("20 zł");
    labelPresent10 = new QLabel("10 zł");
    labelPresent5 = new QLabel("5 zł");
    labelPresent2 = new QLabel("2 zł");
    labelPresent1 = new QLabel("1 zł");

    //----Labele opsiujące pola----//
    editPresent200 = new QLineEdit();
    editPresent200->setReadOnly(true);
    editPresent100 = new QLineEdit();
    editPresent100->setReadOnly(true);
    editPresent50 = new QLineEdit();
    editPresent50->setReadOnly(true);
    editPresent20 = new QLineEdit();
    editPresent20->setReadOnly(true);
    editPresent10 = new QLineEdit();
    editPresent10->setReadOnly(true);
    editPresent5 = new QLineEdit();
    editPresent5->setReadOnly(true);
    editPresent2 = new QLineEdit();
    editPresent2->setReadOnly(true);
    editPresent1 = new QLineEdit();
    editPresent1->setReadOnly(true);

    //----Labele opsiujące pola----//
    labelAdd200 = new QLabel("200 zł");
    labelAdd100 = new QLabel("100 zł");
    labelAdd50 = new QLabel("50 zł");
    labelAdd20 = new QLabel("20 zł");
    labelAdd10 = new QLabel("10 zł");
    labelAdd5 = new QLabel("5 zł");
    labelAdd2 = new QLabel("2 zł");
    labelAdd1 = new QLabel("1 zł");

    //----Pola gdzie będzie wartość dodawana----//
    editAdd200 = new QSpinBox();
    editAdd100 = new QSpinBox();
    editAdd50 = new QSpinBox();
    editAdd20 = new QSpinBox();
    editAdd10 = new QSpinBox();
    editAdd5 = new QSpinBox();
    editAdd2 = new QSpinBox();
    editAdd1 = new QSpinBox();


    //----Layout----//
    layoutPresentMoney = new QGridLayout();
    layoutPresentMoney->addWidget(labelPresent200,0,0);
    layoutPresentMoney->addWidget(labelPresent100,1,0);
    layoutPresentMoney->addWidget(labelPresent50,2,0);
    layoutPresentMoney->addWidget(labelPresent20,3,0);
    layoutPresentMoney->addWidget(labelPresent10,4,0);
    layoutPresentMoney->addWidget(labelPresent5,5,0);
    layoutPresentMoney->addWidget(labelPresent2,6,0);
    layoutPresentMoney->addWidget(labelPresent1,7,0);
    layoutPresentMoney->addWidget(editPresent200,0,1);
    layoutPresentMoney->addWidget(editPresent100,1,1);
    layoutPresentMoney->addWidget(editPresent50,2,1);
    layoutPresentMoney->addWidget(editPresent20,3,1);
    layoutPresentMoney->addWidget(editPresent10,4,1);
    layoutPresentMoney->addWidget(editPresent5,5,1);
    layoutPresentMoney->addWidget(editPresent2,6,1);
    layoutPresentMoney->addWidget(editPresent1,7,1);
    layoutPresentMoney->setHorizontalSpacing(60);

    layoutAddMoney = new QGridLayout();
    layoutAddMoney->addWidget(labelAdd200,0,0);
    layoutAddMoney->addWidget(labelAdd100,1,0);
    layoutAddMoney->addWidget(labelAdd50,2,0);
    layoutAddMoney->addWidget(labelAdd20,3,0);
    layoutAddMoney->addWidget(labelAdd10,4,0);
    layoutAddMoney->addWidget(labelAdd5,5,0);
    layoutAddMoney->addWidget(labelAdd2,6,0);
    layoutAddMoney->addWidget(labelAdd1,7,0);
    layoutAddMoney->addWidget(editAdd200,0,1);
    layoutAddMoney->addWidget(editAdd100,1,1);
    layoutAddMoney->addWidget(editAdd50,2,1);
    layoutAddMoney->addWidget(editAdd20,3,1);
    layoutAddMoney->addWidget(editAdd10,4,1);
    layoutAddMoney->addWidget(editAdd5,5,1);
    layoutAddMoney->addWidget(editAdd2,6,1);
    layoutAddMoney->addWidget(editAdd1,7,1);

    //----GroupBoxy----//
    groupPresentMoney = new QGroupBox("Obecna ilość pieniędzy",this);
    groupPresentMoney->setGeometry(20,10,205,300);
    groupPresentMoney->setLayout(layoutPresentMoney);
    groupAddMoney = new QGroupBox("Dołóż pieniądze",this);
    groupAddMoney->setGeometry(225,10,205,300);
    groupAddMoney->setLayout(layoutAddMoney);

    //----Kaseta pieniędzy----//
    this->kaseta = moneyBox;
    setPresentMoney();
    setMaxLimitOfAddMoney();

    //----Przypisanie przycisków do slotów----//
    connect(buttonOk,SIGNAL(clicked(bool)),this,SLOT(closeWindowOk()));
    connect(buttonCancel,SIGNAL(clicked(bool)),this,SLOT(closeWindowCancel()));

    this->showWindow();
}

WidgetAddMoney::~WidgetAddMoney()
{

}

//----Zamyka okno zachowując zmiany----//
void WidgetAddMoney::closeWindowOk()
{
    QVector<int> money;
    money << editAdd200->value() << editAdd100->value() << editAdd50->value() << editAdd20->value() << editAdd10->value() << editAdd5->value() << editAdd2->value() << editAdd1->value();
    kaseta->addMoney(money);
    clearFields();
    this->close();
}

//----Zamyka okno nie zachowując zmian----//
void WidgetAddMoney::closeWindowCancel()
{
    clearFields();
    this->close();
}

//----Zamyka okno nie zachowując zmian----//
void WidgetAddMoney::closeEvent(QCloseEvent *)
{
    clearFields();
    this->close();
}

//----Zeruje wartości w polach----//
void WidgetAddMoney::clearFields()
{
    editAdd200->setValue(0);
    editAdd100->setValue(0);
    editAdd50 ->setValue(0);
    editAdd20->setValue(0);
    editAdd10->setValue(0);
    editAdd5->setValue(0);
    editAdd2->setValue(0);
    editAdd1->setValue(0);
}

//----Wpisuje w pola obecna ilosc pieniedzy----//
void WidgetAddMoney::setPresentMoney()
{
    QVector<int> money = kaseta->getNumberOfDenominations();
    editPresent200->setText(QString::number(money.at(0)));
    editPresent100->setText(QString::number(money.at(1)));
    editPresent50 ->setText(QString::number(money.at(2)));
    editPresent20->setText(QString::number(money.at(3)));
    editPresent10->setText(QString::number(money.at(4)));
    editPresent5->setText(QString::number(money.at(5)));
    editPresent2->setText(QString::number(money.at(6)));
    editPresent1->setText(QString::number(money.at(7)));
}

//----Pilnuje aby nie można było włożyć więcej niż 1000 sztuk danego nominału----//
void WidgetAddMoney::setMaxLimitOfAddMoney()
{
    QVector<int> money = kaseta->getNumberOfDenominations();
    editAdd200->setMaximum(1000 - money.at(0));
    editAdd100->setMaximum(1000 - money.at(1));
    editAdd50->setMaximum(1000 - money.at(2));
    editAdd20->setMaximum(1000 - money.at(3));
    editAdd10->setMaximum(1000 - money.at(4));
    editAdd5->setMaximum(1000 - money.at(5));
    editAdd2->setMaximum(1000 - money.at(6));
    editAdd1->setMaximum(1000 - money.at(7));
}

void WidgetAddMoney::showWindow()
{
    if(this->isVisible()) //Jeżeli okno jest widoczne
    {
        this->activateWindow(); //Niech stanie się aktywne
    }
    else //Jeżeli okno było stworzone i nie jest widoczne wywołaj je
    {
        setPresentMoney();
        this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
        this->show();
    }
}
