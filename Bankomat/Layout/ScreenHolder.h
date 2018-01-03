#ifndef SCREENHOLDER_H
#define SCREENHOLDER_H

#include "Screen.h"
#include "ATMState.h"
#include <QMap>

class ScreenHolder
{
private:
    QMap<ATMState,Screen*> *map;
public:
    ScreenHolder();
    Screen* getScreen(ATMState state);
};

#endif // SCREENHOLDER_H
