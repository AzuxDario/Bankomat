#include "WidgetViewProvider.h"

CRdzen::CRdzen(QObject *parent) : QObject(parent)
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
        atmState = insertCard;
    }
    else
    {
        atmState = noMoneyInATM;
    }
    isATMStateChenged = true;
}

CRdzen::~CRdzen()
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
QString CRdzen::getValueField()
{
    return valueField;
}

//----Zwraca zawartość pola w postaci gwiazdek----//
QString CRdzen::getHiddenValueField()
{
    QString gwiazdki = "";
    for(int i = 0; i < valueField.length(); i++)
    {
        gwiazdki += "*";
    }
    return gwiazdki;
}

//----Zwraca numer aktualnie załadowanego konta----//
QString CRdzen::getAccountNumber()
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
double CRdzen::getBalance()
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
CRdzen::ATMState CRdzen::getATMState()
{
    return atmState;
}

//----Zwraca czy zmieniono stan bankomatu----//
bool CRdzen::getIsATMStateChanged()
{
    return isATMStateChenged;
}

//--------Settery--------//
//----Zmienia stan bankomatu----//
void CRdzen::setATMState(CRdzen::ATMState stanBankomatu)
{
    this->atmState = stanBankomatu;
}

//--------Funkcje wyświetlające okna--------//
void CRdzen::showWidgetAbout()
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
void CRdzen::showWidgetAddAccount()
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
void CRdzen::showWidgetAddMoney()
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
CRdzen::ATMState CRdzen::buttonAPressed()
{
    switch(atmState)
    {
    //Cofnięcie okna gdy plik karty jest zły lub uszkodzony
    case wrongCardFile:
        isATMStateChenged = true;
        return atmState = insertCard;
        break;
    //Cofnięcie okna w przypadku zablokowania karty
    case blockedCard:
        isATMStateChenged = true;
        return atmState = insertCard;
        break;
    //Cofnięcie okna w przypadku gdy podano zły PIN
    case wrongPin:
        isATMStateChenged = true;
        return atmState = insertPin;
        break;
    //Wyjęcie karty w przypadku wybrania takiej operacji
    case chooseOperation:
        isATMStateChenged = true;
        return atmState = removeCard;
        break;
    //Cofnięcie podczas zmiany Pinu
    case changePin:
        isATMStateChenged = true;
        valueField = "";
        return atmState = chooseOperation;
        break;
    //Cofnięcie po zmianie pinu
    case pinChanged:
        isATMStateChenged = true;
        return atmState = chooseOperation;
        break;
    //Wyjęcie karty podczas przeglądania salda
    case showBalance:
        isATMStateChenged = true;
        return atmState = removeCard;
        break;
    //Cofnięcie do poprzedniego okna podczas wypłaty
    case withdrawMoney:
        valueField = "";
        isATMStateChenged = true;
        return atmState = chooseOperation;
        break;
    //Cofnięcie do poprzednego okna gdy brak środków na koncie
    case noEnoughMoney:
        isATMStateChenged = true;
        return atmState = chooseOperation;
        break;
    default:
        isATMStateChenged = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonBPressed()
{
    switch(atmState)
    {
    case chooseOperation:
        isATMStateChenged = true;
        return atmState = showAccountNumber;
        break;
    case showAccountNumber:
        isATMStateChenged = true;
        return atmState = chooseOperation;
        break;
    default:
        isATMStateChenged = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonCPressed()
{
    switch(atmState)
    {
    default:
        isATMStateChenged = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonDPressed()
{
    switch(atmState)
    {
    default:
        isATMStateChenged = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonEPressed()
{
    switch(atmState)
    {
    //Zatwierdzenie podczas wpisywania PINu
    case insertPin:
        isATMStateChenged = true;
        if(card->checkPin(valueField.toInt()))//Pin prawidłowy
        {
            //Poprawnie wprowadzono PIN i uzyskano dostęp do konta
            valueField = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            account = new Account(card->getAccountNumber());
            return atmState = chooseOperation;
        }
        else
        {
            valueField = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            if(card->getIsCardBlocked())//Czy konto zablokowane
            {
                card->saveCardFile();
                delete card;
                card = nullptr;
                return atmState = blockedCard;
            }
            else
            {
                return atmState = wrongPin;
            }
        }
        break;
    //Wybranie operacji wyświetlenie salda
    case chooseOperation:
        isATMStateChenged = true;
        return atmState = showBalance;
        break;
    //Zatwierdzenie nowego pinu
    case changePin:
        if(valueField.length() == 4)
        {
            isATMStateChenged = true;
            card->setPin(valueField.toInt());
            card->saveCardFile();
            valueField = "";
            return atmState = pinChanged;
        }
        else
        {
            isATMStateChenged = false;
            return atmState;
        }
        break;
    //Powrót do wyboru operacji z okna wyświetlania salda
    case showBalance:
        isATMStateChenged = true;
        return atmState = chooseOperation;
        break;
    //Wybrano wypłacenie podanej ilości gotówki
    case withdrawMoney:
    {
        isATMStateChenged = true;
        //Sprawdź czy można wypłacić
        int kwota = valueField.toInt();
        valueField = "";
        if(moneyDispenser->payment(account, kwota) == MoneyDispenser::PaidMoney)
        {         
            return atmState = insertAmountOfMoney;
        }
        else
        {
            return atmState = noEnoughMoney;
        }
        break;
    }
    default:
        isATMStateChenged = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonFPressed()
{
    switch(atmState)
    {
    //Wybranie operacji wypłaty gotówki
    case chooseOperation:
        isATMStateChenged = true;
        return atmState = withdrawMoney;
        break;
    case showBalance:
        valueField = "";
        isATMStateChenged = true;
        return atmState = withdrawMoney;
        break;
    case showAccountNumber:
        isATMStateChenged = true;
        return atmState = removeCard;
        break;
    default:
        isATMStateChenged = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonGPressed()
{
    switch(atmState)
    {
    case chooseOperation:
        isATMStateChenged = true;
        return atmState = changePin;
    default:
        isATMStateChenged = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonHPressed()
{
    switch(atmState)
    {
    default:
        isATMStateChenged = false;
        return atmState;
        break;
    }
}

void CRdzen::buttonNumberPressed(int value)
{
    isATMStateChenged = false;
    switch(atmState)
    {
    case insertPin:
    case changePin:
        if(valueField.length() < 4)
        {
            valueField = valueField + QString::number(value);
        }
        break;
    case withdrawMoney:
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

void CRdzen::buttonUndoPressed()
{
    if(valueField.isEmpty() == false)
    {
        valueField.remove(valueField.length()-1,1);
    }
}

//----Funkcja informująca o użyciu karty----//
CRdzen::ATMState CRdzen::cardUsed(QString dir)
{
    if(atmState == insertCard)
    {
        isATMStateChenged = true;
        card = new Card();
        Card::CardState stanKarty = card->readCardFile(dir);
        switch(stanKarty)
        {
        case Card::readCard:
            if(card->getIsCardBlocked() == true)
            {
                return atmState = blockedCard;
            }
            return atmState = insertPin;
            break;
        case Card::brokenCard:
            delete card;
            card = nullptr;
            return atmState = wrongCardFile;
            break;
        case Card::noCard:
            isATMStateChenged = false;
            return atmState = insertCard;
            break;
        }
    }
    else if(atmState == removeCard)
    {
        isATMStateChenged = true;
        delete card;
        card = nullptr;
        delete account;
        account = nullptr;
        return atmState = insertCard;
    }
    return atmState;
}

//----Funkcja informująca o odebraniu pieniędzy----//
CRdzen::ATMState CRdzen::moneyReceived()
{
    if(atmState == insertAmountOfMoney)
    {
        isATMStateChenged = true;
        return atmState = removeCard;
    }
    isATMStateChenged = false;
    return atmState;
}

//----Zwraca wektor z ilością wypłaconych pieniędzy gdzie na indeksie 0 jest 200zł----//
QVector<int> CRdzen::getMoney()
{
    return moneyDispenser->getLastPayment();
}

//----Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy----//
void CRdzen::buttonResetPressed()
{
    if(atmState == noMoneyInATM)
    {
        if(moneyDispenser->isEnoughCash() == true)
        {
            isATMStateChenged = true;
            atmState = insertCard;
        }
        else
        {
           isATMStateChenged = false;
        }
    }
}
