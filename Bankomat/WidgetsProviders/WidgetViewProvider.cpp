#include "WidgetViewProvider.h"

CRdzen::CRdzen(QObject *parent) : QObject(parent)
{

    pole = "";
    oknoOProgramie = nullptr;
    oknoDodajKonto = nullptr;
    oknoDodajPieniadze = nullptr;
    karta = nullptr;
    konto = nullptr;
    kaseta = new MoneyBox();
    wyplacacz = new MoneyDispenser(kaseta);
    if(wyplacacz->isEnoughCash() == true)
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
    delete wyplacacz;
    delete kaseta;
}

//--------Gettery--------//
//----Zwraca zawartość pola----//
QString CRdzen::zwrocPole()
{
    return pole;
}

//----Zwraca zawartość pola w postaci gwiazdek----//
QString CRdzen::zwrocPoleZagwiazdkowane()
{
    QString gwiazdki = "";
    for(int i = 0; i < pole.length(); i++)
    {
        gwiazdki += "*";
    }
    return gwiazdki;
}

//----Zwraca numer aktualnie załadowanego konta----//
QString CRdzen::zwrocNumerKonta()
{
    if(karta == nullptr)
    {
        return "";
    }
    else
    {
        return karta->getAccountNumber();
    }
}

//----Zwraca stan obecnie załadowanego konta----//
double CRdzen::zwrocStanKonta()
{
    if(konto != nullptr)
    {
        return konto->getBalance();
    }
    else
    {
        return -1;
    }
}

//----Zwraca stan bankomatu----//
CRdzen::StanBankomatu CRdzen::zwrocStanBankomatu()
{
    return stanBankomatu;
}

//----Zwraca czy zmieniono stan bankomatu----//
bool CRdzen::zwrocCzyZmienionoStanBankomatu()
{
    return czyZmienionoStanBankomatu;
}

//--------Settery--------//
//----Zmienia stan bankomatu----//
void CRdzen::zmienStanBankomatu(CRdzen::StanBankomatu stanBankomatu)
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
        oknoDodajPieniadze = new WidgetAddMoney(kaseta);
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
        pole = "";
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
        pole = "";
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
        if(karta->checkPin(pole.toInt()))//Pin prawidłowy
        {
            //Poprawnie wprowadzono PIN i uzyskano dostęp do konta
            pole = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            konto = new Account(karta->getAccountNumber());
            return stanBankomatu = wybierzOperacje;
        }
        else
        {
            pole = ""; //Usunięcie wprowadzonego PINu po sprawdzeniu
            if(karta->getIsCardBlocked())//Czy konto zablokowane
            {
                karta->saveCardFile();
                delete karta;
                karta = nullptr;
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
        if(pole.length() == 4)
        {
            czyZmienionoStanBankomatu = true;
            karta->setPin(pole.toInt());
            karta->saveCardFile();
            pole = "";
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
        int kwota = pole.toInt();
        pole = "";
        if(wyplacacz->payment(konto, kwota) == MoneyDispenser::PaidMoney)
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
        pole = "";
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
        if(pole.length() < 4)
        {
            pole = pole + QString::number(wartosc);
        }
        break;
    case wyplacGotowke:
        if(pole.isEmpty() == true)
        {
          if(wartosc != 0)
            {
                pole = pole + QString::number(wartosc);
            }
        }
        else if((pole.at(0) == '1') || (pole.at(0) == '2'))
        {
            if(pole.length() < 4)
            {
                pole = pole + QString::number(wartosc);
            }
        }
        else if((pole.length() == 3) && (pole.at(0) == '3'))
        {
            if((pole.at(1) == '0') && (pole.at(2) == '0') && (wartosc == 0))
            {
                pole = pole + QString::number(wartosc);
            }
        }
        else
        {
            if(pole.length() < 3)
            {
                pole = pole + QString::number(wartosc);
            }
        }
        break;
    default:
        break;
    }
}

void CRdzen::przyciskCofnijKliknieto()
{
    if(pole.isEmpty() == false)
    {
        pole.remove(pole.length()-1,1);
    }
}

//----Funkcja informująca o użyciu karty----//
CRdzen::StanBankomatu CRdzen::uzytoKarte(QString lokalizacja)
{
    if(stanBankomatu == wlozKarte)
    {
        czyZmienionoStanBankomatu = true;
        karta = new Card();
        Card::CardState stanKarty = karta->readCardFile(lokalizacja);
        switch(stanKarty)
        {
        case Card::readCard:
            if(karta->getIsCardBlocked() == true)
            {
                return stanBankomatu = kartaZablokowana;
            }
            return stanBankomatu = podajPin;
            break;
        case Card::brokenCard:
            delete karta;
            karta = nullptr;
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
        delete karta;
        karta = nullptr;
        delete konto;
        konto = nullptr;
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
    return wyplacacz->getLastPayment();
}

//----Resetuje stan bankomatu po tym gdy brakowało w nim pieniędzy----//
void CRdzen::resetujKliknieto()
{
    if(stanBankomatu == brakSrodkowWBankomacie)
    {
        if(wyplacacz->isEnoughCash() == true)
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
