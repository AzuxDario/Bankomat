#include "WidgetViewProvider.h"

WidgetViewProvider::WidgetViewProvider(QObject *parent) : QObject(parent)
{

    valueField = "";
    widgetAbout = nullptr;
    widgetAddAccount = nullptr;
    widgetAddMoney = nullptr;
    card = nullptr;
    account = nullptr;
    moneyBox = new MoneyBox();
    moneyDispenser = new MoneyDispenser(moneyBox);
    if(moneyDispenser->isEnoughCash() == true)
    {
        atmState = ATMState::insertCard;
    }
    else
    {
        atmState = ATMState::noMoneyInATM;
    }
    isATMStateChanged = true;
}

WidgetViewProvider::~WidgetViewProvider()
{  
    if(widgetAbout != nullptr)
    {
        delete widgetAbout;
    }
    if(widgetAddMoney != nullptr)
    {
        delete widgetAddMoney;
    }
    if(widgetAddAccount != nullptr)
    {
        delete widgetAddAccount;
    }
    delete moneyDispenser;
    delete moneyBox;
}

//--------Gettery--------//
//----Zwraca zawartość pola----//
QString WidgetViewProvider::getValueField()
{
    return valueField;
}

//----Zwraca zawartość pola w postaci gwiazdek----//
QString WidgetViewProvider::getHiddenValueField()
{
    QString asterisks = "";
    for(int i = 0; i < valueField.length(); i++)
    {
        asterisks += "*";
    }
    return asterisks;
}

//----Zwraca numer aktualnie załadowanego konta----//
QString WidgetViewProvider::getAccountNumber()
{
    if(card == nullptr)
    {
        return "";
    }
    else
    {
        return card->getAccountNumber();
    }
}

//----Zwraca stan obecnie załadowanego konta----//
double WidgetViewProvider::getBalance()
{
    if(account != nullptr)
    {
        return account->getBalance();
    }
    else
    {
        return -1;
    }
}

//----Zwraca stan bankomatu----//
ATMState WidgetViewProvider::getATMState()
{
    return atmState;
}

//----Zwraca czy zmieniono stan bankomatu----//
bool WidgetViewProvider::getIsATMStateChanged()
{
    return isATMStateChanged;
}

//--------Settery--------//
//----Zmienia stan bankomatu----//
void WidgetViewProvider::setATMState(ATMState atmState)
{
    this->atmState = atmState;
}

//--------Funkcje wyświetlające okna--------//
void WidgetViewProvider::showWidgetAbout()
{
    if(widgetAbout == nullptr) //Jeżli okna nie ma stwórz je
    {
        widgetAbout = new WidgetAbout();
    }
    else
    {
        widgetAbout->showWindow();
    }
}

//----Wyświetla okienko gdzie można utworzyć konto do testów----//
void WidgetViewProvider::showWidgetAddAccount()
{
    if(widgetAddAccount == nullptr) //Jeżli okna nie ma stwórz je
    {
        widgetAddAccount = new WidgetAddAccount();
    }
    else
    {
        widgetAddAccount->showWindow();
    }
}

//----Pokazuje okno gdzie można dołożyć pieniądze do bankomatu----//
void WidgetViewProvider::showWidgetAddMoney()
{
    if(widgetAddMoney == nullptr) //Jeżli okna nie ma stwórz je
    {
        widgetAddMoney = new WidgetAddMoney(moneyBox);
    }
    else
    {
        widgetAddMoney->showWindow();
    }
}

//--------Funkcję obsługi przycisków bankomatu--------//
ATMState WidgetViewProvider::buttonAPressed()
{
    switch(atmState)
    {
    //Cofnięcie okna gdy plik karty jest zły lub uszkodzony
    case ATMState::wrongCardFile:
        isATMStateChanged = true;
        return atmState = ATMState::insertCard;
        break;
    //Cofnięcie okna w przypadku zablokowania karty
    case ATMState::blockedCard:
        isATMStateChanged = true;
        return atmState = ATMState::insertCard;
        break;
    //Cofnięcie okna w przypadku gdy podano zły PIN
    case ATMState::wrongPin:
        isATMStateChanged = true;
        return atmState = ATMState::insertPin;
        break;
    //Wyjęcie karty w przypadku wybrania takiej operacji
    case ATMState::chooseOperation:
        isATMStateChanged = true;
        return atmState = ATMState::removeCard;
        break;
    //Cofnięcie podczas zmiany Pinu
    case ATMState::changePin:
        isATMStateChanged = true;
        valueField = "";
        return atmState = ATMState::chooseOperation;
        break;
    //Cofnięcie po zmianie pinu
    case ATMState::pinChanged:
        isATMStateChanged = true;
        return atmState = ATMState::chooseOperation;
        break;
    //Wyjęcie karty podczas przeglądania salda
    case ATMState::showBalance:
        isATMStateChanged = true;
        return atmState = ATMState::removeCard;
        break;
    //Cofnięcie do poprzedniego okna podczas wypłaty
    case ATMState::withdrawMoney:
        valueField = "";
        isATMStateChanged = true;
        return atmState = ATMState::chooseOperation;
        break;
    //Cofnięcie do poprzednego okna gdy brak środków na koncie
    case ATMState::noEnoughMoney:
        isATMStateChanged = true;
        return atmState = ATMState::chooseOperation;
        break;
    default:
        isATMStateChanged = false;
        return atmState;
        break;
    }
}

ATMState WidgetViewProvider::buttonBPressed()
{
    switch(atmState)
    {
    case ATMState::chooseOperation:
        isATMStateChanged = true;
        return atmState = ATMState::showAccountNumber;
        break;
    case ATMState::showAccountNumber:
        isATMStateChanged = true;
        return atmState = ATMState::chooseOperation;
        break;
    default:
        isATMStateChanged = false;
        return atmState;
        break;
    }
}

ATMState WidgetViewProvider::buttonCPressed()
{
    switch(atmState)
    {
    default:
        isATMStateChanged = false;
        return atmState;
        break;
    }
}

ATMState WidgetViewProvider::buttonDPressed()
{
    switch(atmState)
    {
    default:
        isATMStateChanged = false;
        return atmState;
        break;
    }
}

ATMState WidgetViewProvider::buttonEPressed()
{
    switch(atmState)
    {
    //Zatwierdzenie podczas wpisywania PINu
    case ATMState::insertPin:
        isATMStateChanged = true;
        if(card->checkPin(valueField.toInt()))//Pin prawidłowy
        {
            //Poprawnie wprowadzono PIN i uzyskano dostęp do konta
            valueField = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            account = new Account(card->getAccountNumber());
            return atmState = ATMState::chooseOperation;
        }
        else
        {
            valueField = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            if(card->getIsCardBlocked())//Czy konto zablokowane
            {
                card->saveCardFile();
                delete card;
                card = nullptr;
                return atmState = ATMState::blockedCard;
            }
            else
            {
                return atmState = ATMState::wrongPin;
            }
        }
        break;
    //Wybranie operacji wyświetlenie salda
    case ATMState::chooseOperation:
        isATMStateChanged = true;
        return atmState = ATMState::showBalance;
        break;
    //Zatwierdzenie nowego pinu
    case ATMState::changePin:
        if(valueField.length() == 4)
        {
            isATMStateChanged = true;
            card->setPin(valueField.toInt());
            card->saveCardFile();
            valueField = "";
            return atmState = ATMState::pinChanged;
        }
        else
        {
            isATMStateChanged = false;
            return atmState;
        }
        break;
    //Powrót do wyboru operacji z okna wyświetlania salda
    case ATMState::showBalance:
        isATMStateChanged = true;
        return atmState = ATMState::chooseOperation;
        break;
    //Wybrano wypłacenie podanej ilości gotówki
    case ATMState::withdrawMoney:
    {
        isATMStateChanged = true;
        //Sprawdź czy można wypłacić
        int amount = valueField.toInt();
        valueField = "";
        if(moneyDispenser->payment(account, amount) == MoneyDispenser::PaidMoney)
        {         
            return atmState = ATMState::insertAmountOfMoney;
        }
        else
        {
            return atmState = ATMState::noEnoughMoney;
        }
        break;
    }
    default:
        isATMStateChanged = false;
        return atmState;
        break;
    }
}

ATMState WidgetViewProvider::buttonFPressed()
{
    switch(atmState)
    {
    //Wybranie operacji wypłaty gotówki
    case ATMState::chooseOperation:
        isATMStateChanged = true;
        return atmState = ATMState::withdrawMoney;
        break;
    case ATMState::showBalance:
        valueField = "";
        isATMStateChanged = true;
        return atmState = ATMState::withdrawMoney;
        break;
    case ATMState::showAccountNumber:
        isATMStateChanged = true;
        return atmState = ATMState::removeCard;
        break;
    default:
        isATMStateChanged = false;
        return atmState;
        break;
    }
}

ATMState WidgetViewProvider::buttonGPressed()
{
    switch(atmState)
    {
    case ATMState::chooseOperation:
        isATMStateChanged = true;
        return atmState = ATMState::changePin;
    default:
        isATMStateChanged = false;
        return atmState;
        break;
    }
}

ATMState WidgetViewProvider::buttonHPressed()
{
    switch(atmState)
    {
    default:
        isATMStateChanged = false;
        return atmState;
        break;
    }
}

void WidgetViewProvider::buttonNumberPressed(int value)
{
    isATMStateChanged = false;
    switch(atmState)
    {
    case ATMState::insertPin:
    case ATMState::changePin:
        if(valueField.length() < 4)
        {
            valueField = valueField + QString::number(value);
        }
        break;
    case ATMState::withdrawMoney:
        if(valueField.isEmpty() == true)
        {
          if(value != 0)
            {
                valueField = valueField + QString::number(value);
            }
        }
        else if((valueField.at(0) == '1') || (valueField.at(0) == '2'))
        {
            if(valueField.length() < 4)
            {
                valueField = valueField + QString::number(value);
            }
        }
        else if((valueField.length() == 3) && (valueField.at(0) == '3'))
        {
            if((valueField.at(1) == '0') && (valueField.at(2) == '0') && (value == 0))
            {
                valueField = valueField + QString::number(value);
            }
        }
        else
        {
            if(valueField.length() < 3)
            {
                valueField = valueField + QString::number(value);
            }
        }
        break;
    default:
        break;
    }
}

void WidgetViewProvider::buttonUndoPressed()
{
    if(valueField.isEmpty() == false)
    {
        valueField.remove(valueField.length()-1,1);
    }
}

//----Funkcja informująca o użyciu karty----//
ATMState WidgetViewProvider::cardUsed(QString dir)
{
    if(atmState == ATMState::insertCard)
    {
        isATMStateChanged = true;
        card = new Card();
        Card::CardState cardState = card->readCardFile(dir);
        switch(cardState)
        {
        case Card::readCard:
            if(card->getIsCardBlocked() == true)
            {
                return atmState = ATMState::blockedCard;
            }
            return atmState = ATMState::insertPin;
            break;
        case Card::brokenCard:
            delete card;
            card = nullptr;
            return atmState = ATMState::wrongCardFile;
            break;
        case Card::noCard:
            isATMStateChanged = false;
            return atmState = ATMState::insertCard;
            break;
        }
    }
    else if(atmState == ATMState::removeCard)
    {
        isATMStateChanged = true;
        delete card;
        card = nullptr;
        delete account;
        account = nullptr;
        return atmState = ATMState::insertCard;
    }
    return atmState;
}

//----Funkcja informująca o odebraniu pieniędzy----//
ATMState WidgetViewProvider::moneyReceived()
{
    if(atmState == ATMState::insertAmountOfMoney)
    {
        isATMStateChanged = true;
        return atmState = ATMState::removeCard;
    }
    isATMStateChanged = false;
    return atmState;
}

//----Zwraca wektor z ilością wypłaconych pieniędzy gdzie na indeksie 0 jest 200zł----//
QVector<int> WidgetViewProvider::getMoney()
{
    return moneyDispenser->getLastPayment();
}

//----Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy----//
void WidgetViewProvider::buttonResetPressed()
{
    if(atmState == ATMState::noMoneyInATM)
    {
        if(moneyDispenser->isEnoughCash() == true)
        {
            isATMStateChanged = true;
            atmState = ATMState::insertCard;
        }
        else
        {
           isATMStateChanged = false;
        }
    }
}
