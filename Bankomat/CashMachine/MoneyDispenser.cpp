#include "MoneyDispenser.h"

MoneyDispenser::MoneyDispenser(MoneyBox *moneyBox)
{
    this->moneyBox = moneyBox;
    valueOfDenominations[0] = 800;
    valueOfDenominations[1] = 600;
    valueOfDenominations[2] = 400;
    valueOfDenominations[4] = 300;
    valueOfDenominations[5] = 200;
    valueOfDenominations[6] = 150;
    valueOfDenominations[7] = 100;
    valueOfDenominations[8] = 50;
    valueOfDenominations[9] = 0;
}


//----Sprawdza czy w bankomacie jest wystarczająca ilośc gotówki----//
bool MoneyDispenser::isEnoughCash()
{
    QVector<int> cash = moneyBox->getNumberOfDenominations();
    for(int i = 0; i < cash.count(); i++)
    {
        if(cash[i] < 10)
        {
            return false;
        }
    }
    return true;
}

//----Inicjuje wypłątę z konta sprawdzając czy stan konta jest wystarczający----//
MoneyDispenser::PaymentResult MoneyDispenser::payment(Account *account, int amount)
{
    if(account->getBalance() >= amount)
    {
        withdrawMoney(amount);
        account->withdraw(amount);
        return MoneyDispenser::PaidMoney;
    }
    else
    {
        return MoneyDispenser::NoFunds;
    }
}

//----Wyznacza jakimi nominałami wyznaczyć pieniądze z konta----//
void MoneyDispenser::withdrawMoney(int amount)
{
    int remainAmount = amount;
    QVector<int> numberOfDenominations = moneyBox->getNumberOfDenominations(); //Pobieramy ilosc banknotow z kasety
    QVector<int> valueOfDenominations = moneyBox->getValueOfDenominations(); //Pobieramy wartosc nominalow z kasety
    QVector<int> moneyToWithdraw = {0,0,0,0,0,0,0,0}; //Wynikowy wektor banknotow do wyplacenia
    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < numberOfDenominations.count(); i++) //Petla przechodzaca po wszystkich nominalach
        {
            while(numberOfDenominations[i] > valueOfDenominations[j]) //Wypłać najpierw nominałami, których poziom jest wysoki
            {
                if(remainAmount == 0) //Jeżeli pozostała do wypłacenia kwota jest równa zero to zakończ pętle
                {
                    moneyBox->setNumberOfDenominations(numberOfDenominations); //Zwracamy kasecie pozostala ilosc nominalow po wyplacie
                    lastPayment.clear();
                    lastPayment = moneyToWithdraw; //Przypisujemy wynik
                    return;
                }
                if(valueOfDenominations[i] > remainAmount) //Jeżeli nominał jest zbyt duży kończymy pętle while
                {
                    break;
                }
                if(remainAmount - valueOfDenominations[i] >= 0) //Jeżeli można wypłacić danym banknotem to dodajemy go do wektora wynikowego
                {
                    remainAmount -= valueOfDenominations[i];
                    moneyToWithdraw[i]++;
                    numberOfDenominations[i]--;
                }
            }
        }
    }
}
