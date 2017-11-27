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
        atmState = wlozKarte;
    }
    else
    {
        atmState = brakSrodkowWBankomacie;
    }
    czyZmienionoStanBankomatu = true;
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
bool CRdzen::isATMStateChanged()
{
    return czyZmienionoStanBankomatu;
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
    case niepoprawnyPlikKarty:
        czyZmienionoStanBankomatu = true;
        return atmState = wlozKarte;
        break;
    //Cofnięcie okna w przypadku zablokowania karty
    case kartaZablokowana:
        czyZmienionoStanBankomatu = true;
        return atmState = wlozKarte;
        break;
    //Cofnięcie okna w przypadku gdy podano zły PIN
    case niepoprawnyPin:
        czyZmienionoStanBankomatu = true;
        return atmState = podajPin;
        break;
    //Wyjęcie karty w przypadku wybrania takiej operacji
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return atmState = wyjmijKarte;
        break;
    //Cofnięcie podczas zmiany Pinu
    case zmienPin:
        czyZmienionoStanBankomatu = true;
        valueField = "";
        return atmState = wybierzOperacje;
        break;
    //Cofnięcie po zmianie pinu
    case zmienionoPin:
        czyZmienionoStanBankomatu = true;
        return atmState = wybierzOperacje;
        break;
    //Wyjęcie karty podczas przeglądania salda
    case wyswietlSaldo:
        czyZmienionoStanBankomatu = true;
        return atmState = wyjmijKarte;
        break;
    //Cofnięcie do poprzedniego okna podczas wypłaty
    case wyplacGotowke:
        valueField = "";
        czyZmienionoStanBankomatu = true;
        return atmState = wybierzOperacje;
        break;
    //Cofnięcie do poprzednego okna gdy brak środków na koncie
    case brakGotowki:
        czyZmienionoStanBankomatu = true;
        return atmState = wybierzOperacje;
        break;
    default:
        czyZmienionoStanBankomatu = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonBPressed()
{
    switch(atmState)
    {
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return atmState = pokazNumerKonta;
        break;
    case pokazNumerKonta:
        czyZmienionoStanBankomatu = true;
        return atmState = wybierzOperacje;
        break;
    default:
        czyZmienionoStanBankomatu = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonCPressed()
{
    switch(atmState)
    {
    default:
        czyZmienionoStanBankomatu = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonDPressed()
{
    switch(atmState)
    {
    default:
        czyZmienionoStanBankomatu = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonEPressed()
{
    switch(atmState)
    {
    //Zatwierdzenie podczas wpisywania PINu
    case podajPin:
        czyZmienionoStanBankomatu = true;
        if(card->checkPin(valueField.toInt()))//Pin prawidłowy
        {
            //Poprawnie wprowadzono PIN i uzyskano dostęp do konta
            valueField = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            account = new Account(card->getAccountNumber());
            return atmState = wybierzOperacje;
        }
        else
        {
            valueField = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            if(card->getIsCardBlocked())//Czy konto zablokowane
            {
                card->saveCardFile();
                delete card;
                card = nullptr;
                return atmState = kartaZablokowana;
            }
            else
            {
                return atmState = niepoprawnyPin;
            }
        }
        break;
    //Wybranie operacji wyświetlenie salda
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return atmState = wyswietlSaldo;
        break;
    //Zatwierdzenie nowego pinu
    case zmienPin:
        if(valueField.length() == 4)
        {
            czyZmienionoStanBankomatu = true;
            card->setPin(valueField.toInt());
            card->saveCardFile();
            valueField = "";
            return atmState = zmienionoPin;
        }
        else
        {
            czyZmienionoStanBankomatu = false;
            return atmState;
        }
        break;
    //Powrót do wyboru operacji z okna wyświetlania salda
    case wyswietlSaldo:
        czyZmienionoStanBankomatu = true;
        return atmState = wybierzOperacje;
        break;
    //Wybrano wypłacenie podanej ilości gotówki
    case wyplacGotowke:
    {
        czyZmienionoStanBankomatu = true;
        //Sprawdź czy można wypłacić
        int kwota = valueField.toInt();
        valueField = "";
        if(moneyDispenser->payment(account, kwota) == MoneyDispenser::PaidMoney)
        {         
            return atmState = wybierzGotowke;
        }
        else
        {
            return atmState = brakGotowki;
        }
        break;
    }
    default:
        czyZmienionoStanBankomatu = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonFPressed()
{
    switch(atmState)
    {
    //Wybranie operacji wypłaty gotówki
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return atmState = wyplacGotowke;
        break;
    case wyswietlSaldo:
        valueField = "";
        czyZmienionoStanBankomatu = true;
        return atmState = wyplacGotowke;
        break;
    case pokazNumerKonta:
        czyZmienionoStanBankomatu = true;
        return atmState = wyjmijKarte;
        break;
    default:
        czyZmienionoStanBankomatu = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonGPressed()
{
    switch(atmState)
    {
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return atmState = zmienPin;
    default:
        czyZmienionoStanBankomatu = false;
        return atmState;
        break;
    }
}

CRdzen::ATMState CRdzen::buttonHPressed()
{
    switch(atmState)
    {
    default:
        czyZmienionoStanBankomatu = false;
        return atmState;
        break;
    }
}

void CRdzen::przyciskKliknieto(int wartosc)
{
    czyZmienionoStanBankomatu = false;
    switch(atmState)
    {
    case podajPin:
    case zmienPin:
        if(valueField.length() < 4)
        {
            valueField = valueField + QString::number(wartosc);
        }
        break;
    case wyplacGotowke:
        if(valueField.isEmpty() == true)
        {
          if(wartosc != 0)
            {
                valueField = valueField + QString::number(wartosc);
            }
        }
        else if((valueField.at(0) == '1') || (valueField.at(0) == '2'))
        {
            if(valueField.length() < 4)
            {
                valueField = valueField + QString::number(wartosc);
            }
        }
        else if((valueField.length() == 3) && (valueField.at(0) == '3'))
        {
            if((valueField.at(1) == '0') && (valueField.at(2) == '0') && (wartosc == 0))
            {
                valueField = valueField + QString::number(wartosc);
            }
        }
        else
        {
            if(valueField.length() < 3)
            {
                valueField = valueField + QString::number(wartosc);
            }
        }
        break;
    default:
        break;
    }
}

void CRdzen::przyciskCofnijKliknieto()
{
    if(valueField.isEmpty() == false)
    {
        valueField.remove(valueField.length()-1,1);
    }
}

//----Funkcja informująca o użyciu karty----//
CRdzen::ATMState CRdzen::uzytoKarte(QString lokalizacja)
{
    if(atmState == wlozKarte)
    {
        czyZmienionoStanBankomatu = true;
        card = new Card();
        Card::CardState stanKarty = card->readCardFile(lokalizacja);
        switch(stanKarty)
        {
        case Card::readCard:
            if(card->getIsCardBlocked() == true)
            {
                return atmState = kartaZablokowana;
            }
            return atmState = podajPin;
            break;
        case Card::brokenCard:
            delete card;
            card = nullptr;
            return atmState = niepoprawnyPlikKarty;
            break;
        case Card::noCard:
            czyZmienionoStanBankomatu = false;
            return atmState = wlozKarte;
            break;
        }
    }
    else if(atmState == wyjmijKarte)
    {
        czyZmienionoStanBankomatu = true;
        delete card;
        card = nullptr;
        delete account;
        account = nullptr;
        return atmState = wlozKarte;
    }
    return atmState;
}

//----Funkcja informująca o odebraniu pieniędzy----//
CRdzen::ATMState CRdzen::odebranoPieniadze()
{
    if(atmState == wybierzGotowke)
    {
        czyZmienionoStanBankomatu = true;
        return atmState = wyjmijKarte;
    }
    czyZmienionoStanBankomatu = false;
    return atmState;
}

//----Zwraca wektor z ilością wypłaconych pieniędzy gdzie na indeksie 0 jest 200zł----//
QVector<int> CRdzen::odbierzPieniadze()
{
    return moneyDispenser->getLastPayment();
}

//----Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy----//
void CRdzen::resetujKliknieto()
{
    if(atmState == brakSrodkowWBankomacie)
    {
        if(moneyDispenser->isEnoughCash() == true)
        {
            czyZmienionoStanBankomatu = true;
            atmState = wlozKarte;
        }
        else
        {
           czyZmienionoStanBankomatu = false;
        }
    }
}
