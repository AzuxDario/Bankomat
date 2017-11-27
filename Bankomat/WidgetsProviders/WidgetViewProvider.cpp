#include "WidgetViewProvider.h"

CRdzen::CRdzen(QObject *parent) : QObject(parent)
{

    valueField = "";
    oknoOProgramie = nullptr;
    oknoDodajKonto = nullptr;
    oknoDodajPieniadze = nullptr;
    card = nullptr;
    account = nullptr;
    moneyBox = new MoneyBox();
    moneyDispenser = new MoneyDispenser(moneyBox);
    if(moneyDispenser->isEnoughCash() == true)
    {
        stanBankomatu = wlozKarte;
    }
    else
    {
        stanBankomatu = brakSrodkowWBankomacie;
    }
    czyZmienionoStanBankomatu = true;
}

CRdzen::~CRdzen()
{  
    if(oknoOProgramie != nullptr)
    {
        delete oknoOProgramie;
    }
    if(oknoDodajPieniadze != nullptr)
    {
        delete oknoDodajPieniadze;
    }
    if(oknoDodajKonto != nullptr)
    {
        delete oknoDodajKonto;
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
CRdzen::StanBankomatu CRdzen::getATMState()
{
    return stanBankomatu;
}

//----Zwraca czy zmieniono stan bankomatu----//
bool CRdzen::isATMStateChanged()
{
    return czyZmienionoStanBankomatu;
}

//--------Settery--------//
//----Zmienia stan bankomatu----//
void CRdzen::setATMState(CRdzen::StanBankomatu stanBankomatu)
{
    this->stanBankomatu = stanBankomatu;
}

//--------Funkcje wyświetlające okna--------//
void CRdzen::wyswietlOProgramie()
{
    if(oknoOProgramie == nullptr) //Jeżli okna nie ma stwórz je
    {
        oknoOProgramie = new WidgetAbout();
    }
    else
    {
        oknoOProgramie->showWindow();
    }
}

//----Wyświetla okienko gdzie można utworzyć konto do testów----//
void CRdzen::wyswietlDodajKonto()
{
    if(oknoDodajKonto == nullptr) //Jeżli okna nie ma stwórz je
    {
        oknoDodajKonto = new WidgetAddAccount();
    }
    else
    {
        oknoDodajKonto->showWindow();
    }
}

//----Pokazuje okno gdzie można dołożyć pieniądze do bankomatu----//
void CRdzen::wyswietlDodajPieniadze()
{
    if(oknoDodajPieniadze == nullptr) //Jeżli okna nie ma stwórz je
    {
        oknoDodajPieniadze = new WidgetAddMoney(moneyBox);
    }
    else
    {
        oknoDodajPieniadze->showWindow();
    }
}

//--------Funkcję obsługi przycisków bankomatu--------//
CRdzen::StanBankomatu CRdzen::przyciskAKliknieto()
{
    switch(stanBankomatu)
    {
    //Cofnięcie okna gdy plik karty jest zły lub uszkodzony
    case niepoprawnyPlikKarty:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wlozKarte;
        break;
    //Cofnięcie okna w przypadku zablokowania karty
    case kartaZablokowana:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wlozKarte;
        break;
    //Cofnięcie okna w przypadku gdy podano zły PIN
    case niepoprawnyPin:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = podajPin;
        break;
    //Wyjęcie karty w przypadku wybrania takiej operacji
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wyjmijKarte;
        break;
    //Cofnięcie podczas zmiany Pinu
    case zmienPin:
        czyZmienionoStanBankomatu = true;
        valueField = "";
        return stanBankomatu = wybierzOperacje;
        break;
    //Cofnięcie po zmianie pinu
    case zmienionoPin:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wybierzOperacje;
        break;
    //Wyjęcie karty podczas przeglądania salda
    case wyswietlSaldo:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wyjmijKarte;
        break;
    //Cofnięcie do poprzedniego okna podczas wypłaty
    case wyplacGotowke:
        valueField = "";
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wybierzOperacje;
        break;
    //Cofnięcie do poprzednego okna gdy brak środków na koncie
    case brakGotowki:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wybierzOperacje;
        break;
    default:
        czyZmienionoStanBankomatu = false;
        return stanBankomatu;
        break;
    }
}

CRdzen::StanBankomatu CRdzen::przyciskBKliknieto()
{
    switch(stanBankomatu)
    {
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = pokazNumerKonta;
        break;
    case pokazNumerKonta:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wybierzOperacje;
        break;
    default:
        czyZmienionoStanBankomatu = false;
        return stanBankomatu;
        break;
    }
}

CRdzen::StanBankomatu CRdzen::przyciskCKliknieto()
{
    switch(stanBankomatu)
    {
    default:
        czyZmienionoStanBankomatu = false;
        return stanBankomatu;
        break;
    }
}

CRdzen::StanBankomatu CRdzen::przyciskDKliknieto()
{
    switch(stanBankomatu)
    {
    default:
        czyZmienionoStanBankomatu = false;
        return stanBankomatu;
        break;
    }
}

CRdzen::StanBankomatu CRdzen::przyciskEKliknieto()
{
    switch(stanBankomatu)
    {
    //Zatwierdzenie podczas wpisywania PINu
    case podajPin:
        czyZmienionoStanBankomatu = true;
        if(card->checkPin(valueField.toInt()))//Pin prawidłowy
        {
            //Poprawnie wprowadzono PIN i uzyskano dostęp do konta
            valueField = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            account = new Account(card->getAccountNumber());
            return stanBankomatu = wybierzOperacje;
        }
        else
        {
            valueField = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            if(card->getIsCardBlocked())//Czy konto zablokowane
            {
                card->saveCardFile();
                delete card;
                card = nullptr;
                return stanBankomatu = kartaZablokowana;
            }
            else
            {
                return stanBankomatu = niepoprawnyPin;
            }
        }
        break;
    //Wybranie operacji wyświetlenie salda
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wyswietlSaldo;
        break;
    //Zatwierdzenie nowego pinu
    case zmienPin:
        if(valueField.length() == 4)
        {
            czyZmienionoStanBankomatu = true;
            card->setPin(valueField.toInt());
            card->saveCardFile();
            valueField = "";
            return stanBankomatu = zmienionoPin;
        }
        else
        {
            czyZmienionoStanBankomatu = false;
            return stanBankomatu;
        }
        break;
    //Powrót do wyboru operacji z okna wyświetlania salda
    case wyswietlSaldo:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wybierzOperacje;
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
            return stanBankomatu = wybierzGotowke;
        }
        else
        {
            return stanBankomatu = brakGotowki;
        }
        break;
    }
    default:
        czyZmienionoStanBankomatu = false;
        return stanBankomatu;
        break;
    }
}

CRdzen::StanBankomatu CRdzen::przyciskFKliknieto()
{
    switch(stanBankomatu)
    {
    //Wybranie operacji wypłaty gotówki
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wyplacGotowke;
        break;
    case wyswietlSaldo:
        valueField = "";
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wyplacGotowke;
        break;
    case pokazNumerKonta:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wyjmijKarte;
        break;
    default:
        czyZmienionoStanBankomatu = false;
        return stanBankomatu;
        break;
    }
}

CRdzen::StanBankomatu CRdzen::przyciskGKliknieto()
{
    switch(stanBankomatu)
    {
    case wybierzOperacje:
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = zmienPin;
    default:
        czyZmienionoStanBankomatu = false;
        return stanBankomatu;
        break;
    }
}

CRdzen::StanBankomatu CRdzen::przyciskHKliknieto()
{
    switch(stanBankomatu)
    {
    default:
        czyZmienionoStanBankomatu = false;
        return stanBankomatu;
        break;
    }
}

void CRdzen::przyciskKliknieto(int wartosc)
{
    czyZmienionoStanBankomatu = false;
    switch(stanBankomatu)
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
CRdzen::StanBankomatu CRdzen::uzytoKarte(QString lokalizacja)
{
    if(stanBankomatu == wlozKarte)
    {
        czyZmienionoStanBankomatu = true;
        card = new Card();
        Card::CardState stanKarty = card->readCardFile(lokalizacja);
        switch(stanKarty)
        {
        case Card::readCard:
            if(card->getIsCardBlocked() == true)
            {
                return stanBankomatu = kartaZablokowana;
            }
            return stanBankomatu = podajPin;
            break;
        case Card::brokenCard:
            delete card;
            card = nullptr;
            return stanBankomatu = niepoprawnyPlikKarty;
            break;
        case Card::noCard:
            czyZmienionoStanBankomatu = false;
            return stanBankomatu = wlozKarte;
            break;
        }
    }
    else if(stanBankomatu == wyjmijKarte)
    {
        czyZmienionoStanBankomatu = true;
        delete card;
        card = nullptr;
        delete account;
        account = nullptr;
        return stanBankomatu = wlozKarte;
    }
    return stanBankomatu;
}

//----Funkcja informująca o odebraniu pieniędzy----//
CRdzen::StanBankomatu CRdzen::odebranoPieniadze()
{
    if(stanBankomatu == wybierzGotowke)
    {
        czyZmienionoStanBankomatu = true;
        return stanBankomatu = wyjmijKarte;
    }
    czyZmienionoStanBankomatu = false;
    return stanBankomatu;
}

//----Zwraca wektor z ilością wypłaconych pieniędzy gdzie na indeksie 0 jest 200zł----//
QVector<int> CRdzen::odbierzPieniadze()
{
    return moneyDispenser->getLastPayment();
}

//----Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy----//
void CRdzen::resetujKliknieto()
{
    if(stanBankomatu == brakSrodkowWBankomacie)
    {
        if(moneyDispenser->isEnoughCash() == true)
        {
            czyZmienionoStanBankomatu = true;
            stanBankomatu = wlozKarte;
        }
        else
        {
           czyZmienionoStanBankomatu = false;
        }
    }
}
