#include "ScreenHolder.h"

ScreenHolder::ScreenHolder()
{
    map = new QMap<ATMState,Screen*>();
    map->insert(ATMState::insertPin,new Screen("Podaj PIN","","","","","Zatwierdź","","",""));
    map->insert(ATMState::noMoneyInATM,new Screen("Przepraszamy bankomat nieczynny","","","","","","","",""));
}

Screen* ScreenHolder::getScreen(ATMState state)
{
    if(map->find(state) != map->end())
    {
        return map->value(state);
    }
    return nullptr;
}
