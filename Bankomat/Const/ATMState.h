#ifndef ATMSTATE_H
#define ATMSTATE_H

enum class ATMState {insertCard, noMoneyInATM, wrongCardFile, blockedCard, insertPin, wrongPin, chooseOperation, changePin, pinChanged, showAccountNumber, showBalance, insertAmountOfMoney, withdrawMoney, noEnoughMoney, removeCard};

#endif // ATMSTATE_H
