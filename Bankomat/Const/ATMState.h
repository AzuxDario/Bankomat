#ifndef ATMSTATE_H
#define ATMSTATE_H

enum class ATMState {insertCard, readingCard, noMoneyInATM, wrongCardFile, blockedCard, insertPin, checkingPin, wrongPin, chooseOperation, changePin, pinChanged, showAccountNumber, showBalance, insertAmountOfMoney, withdrawMoney, noEnoughMoney, removeCard};

#endif // ATMSTATE_H
