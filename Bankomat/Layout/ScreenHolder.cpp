#include "ScreenHolder.h"

ScreenHolder::ScreenHolder()
{
    map = new QMap<ATMState,Screen*>();
    map->insert(ATMState::insertCard,new Screen("Witaj w bankomacie. Proszę włożyć kartę.","","","","","","","",""));
    map->insert(ATMState::noMoneyInATM,new Screen("Przepraszamy bankomat nieczynny","","","","","","","",""));
    map->insert(ATMState::wrongCardFile,new Screen("Nie można odczytać danych z karty upewnij się, że karta nie jest nieuszkodzona.","Cofnij","","","","","","",""));
    map->insert(ATMState::insertPin,new Screen("Podaj PIN","","","","","Zatwierdź","","",""));
    map->insert(ATMState::wrongPin,new Screen("Pin niepoprawny spróbuj jeszcze raz.","Cofnij","","","","","","",""));
    map->insert(ATMState::blockedCard,new Screen("Z uwagi na trzykrotnie złe wpisanie PINu karta została zablokowana.","Cofnij","","","","","","",""));
    map->insert(ATMState::chooseOperation,new Screen("Proszę wybrać operację","Wyjmij kartę","Pok. nr. konta","","","Saldo","Wypłata","Zmień PIN",""));
    map->insert(ATMState::changePin,new Screen("Podaj nowy czterocyfrowy PIN.","Cofnij","","","","Zatwierdź","","",""));
    map->insert(ATMState::pinChanged,new Screen("PIN został zmieniony.","Cofnij","","","","","","",""));
    map->insert(ATMState::showAccountNumber,new Screen("Oto numer twojego konta","","Cofnij","","","","Wyjmij kartę","",""));
    map->insert(ATMState::showBalance,new Screen("Stan twojego konta wynosi:","Wyjmij kartę","","","","Cofnij","Wypłata","",""));
    map->insert(ATMState::withdrawMoney,new Screen("Proszę wpisać żądaną ilość gotówki do wypłaty. Maksymalnie 3000 zł.","Cofnij","","","","Wypłać","","",""));
    map->insert(ATMState::insertAmountOfMoney,new Screen("Proszę odebrać pieniądze..","","","","","","","",""));
    map->insert(ATMState::noEnoughMoney,new Screen("Nie masz wystarczającej ilości środków na koncie","Cofnij","","","","","","",""));
    map->insert(ATMState::removeCard,new Screen("Dziękujemy za skorzystanie z naszego bankomatu. Proszę odebreć kartę.","","","","","","","",""));
}

Screen* ScreenHolder::getScreen(ATMState state)
{
    if(map->find(state) != map->end())
    {
        return map->value(state);
    }
    return nullptr;
}
