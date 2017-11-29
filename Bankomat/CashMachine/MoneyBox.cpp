#include "MoneyBox.h"

MoneyBox::MoneyBox()
{
    valueOfDenominations = {200,100,50,20,10,5,2,1};
    readMoneyBox();
}

MoneyBox::~MoneyBox()
{
    writeMoneyBox();
}

//--------Gettery--------//
QVector<int> MoneyBox::getNumberOfDenominations()
{
    readMoneyBox();
    return numberOfDenominations;
}

//--------Settery--------//
void MoneyBox::setNumberOfDenominations(QVector<int> value)
{
    numberOfDenominations = value;
    writeMoneyBox();
}

void MoneyBox::addMoney(QVector<int> value)
{
    for(int i = 0; i < numberOfDenominations.count(); i++)
    {
        numberOfDenominations[i] += value[i];
    }
    writeMoneyBox();
}

//----Odczytuje informacje o ilości pieniędzy z dysku----//
void MoneyBox::readMoneyBox()
{
    numberOfDenominations.clear();
    QFile moneyBoxFilePath("money.mon");
    if(moneyBoxFilePath.open(QIODevice::ReadOnly))
    {
        QTextStream fileContent(&moneyBoxFilePath);
        numberOfDenominations.push_back(fileContent.readLine().toInt());
        numberOfDenominations.push_back(fileContent.readLine().toInt());
        numberOfDenominations.push_back(fileContent.readLine().toInt());
        numberOfDenominations.push_back(fileContent.readLine().toInt());
        numberOfDenominations.push_back(fileContent.readLine().toInt());
        numberOfDenominations.push_back(fileContent.readLine().toInt());
        numberOfDenominations.push_back(fileContent.readLine().toInt());
        numberOfDenominations.push_back(fileContent.readLine().toInt());
        moneyBoxFilePath.close();
    }
}

//----Zapisuje informację o ilości pieniędzy na dysk----//
void MoneyBox::writeMoneyBox()
{
    QFile moneyBoxFilePath("money.mon");
    if(moneyBoxFilePath.open(QIODevice::WriteOnly))
    {
        QTextStream fileContent(&moneyBoxFilePath);
        fileContent << numberOfDenominations[0] << endl;
        fileContent << numberOfDenominations[1] << endl;
        fileContent << numberOfDenominations[2] << endl;
        fileContent << numberOfDenominations[3] << endl;
        fileContent << numberOfDenominations[4] << endl;
        fileContent << numberOfDenominations[5] << endl;
        fileContent << numberOfDenominations[6] << endl;
        fileContent << numberOfDenominations[7];
        moneyBoxFilePath.close();
    }
}
