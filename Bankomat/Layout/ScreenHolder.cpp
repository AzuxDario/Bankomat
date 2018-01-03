#include "ScreenHolder.h"

ScreenHolder::ScreenHolder()
{

}

Screen* ScreenHolder::getScreen(ATMState state)
{
    if(map->find(state) != map->end())
    {
        return map->value(state);
    }
    return nullptr;
}
