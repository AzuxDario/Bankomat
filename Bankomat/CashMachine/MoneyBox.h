#ifndef MONEYBOX_H
#define MONEYBOX_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>

class MoneyBox
{
private:
    QVector<int> numberOfDenominations;
    QVector<int> valueOfDenominations;
public:
    MoneyBox();
    ~MoneyBox();

    //----Gettery----//
    QVector<int> getNumberOfDenominations();
    QVector<int> getValueOfDenominations();

    //----Settery----//
    void setNumberOfDenominations(QVector<int> value);
    void addMoney(QVector<int> value);

    void readMoneyBox(); //Odczytuje informacje o ilości pieniędzy z dysku
    void writeMoneyBox(); //Zapisuje informację o ilości pieniędzy na dysk
};

#endif // MONEYBOX_H
