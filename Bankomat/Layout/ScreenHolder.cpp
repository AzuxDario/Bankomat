#include "ScreenHolder.h"

ScreenHolder::ScreenHolder()
{
    map = new QMap<ATMState,Screen*>();
    map->insert(ATMState::insertCard,new Screen("Witaj w bankomacie. Proszę włożyć kartę.","","","","","","","",""));
    map->insert(ATMState::noMoneyInATM,new Screen("Przepraszamy bankomat nieczynny","","","","","","","",""));
    map->insert(ATMState::wrongCardFile,new Screen("Nie można odczytać danych z karty upewnij się, że karta nie jest nieuszkodzona.","Cofnij","","","","","","",""));
    map->insert(ATMState::insertPin,new Screen("Podaj PIN","","","","","Zatwierdź","","",""));
    map->insert(ATMState::wrongPin,new Screen("Pin niepoprawny spróbuj jeszcze raz.","Cofnij","","","","","","",""));
}

Screen* ScreenHolder::getScreen(ATMState state)
{
    if(map->find(state) != map->end())
    {
        return map->value(state);
    }
    return nullptr;
}
