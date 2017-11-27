#include "Card.h"

Card::Card()
{
    incorrectPinEnterCounter = 0;
}

//--------Gettery--------//
QString Card::getCardNumber()
{
    return cardNumber;
}

bool Card::getIsCardBlocked()
{
    return isCardBlocked;
}

int Card::getPin()
{
    return pin;
}

QString Card::getAccountNumber()
{
    return accountNumber;
}

QString Card::getCardFilePath()
{
    return cardFilePath;
}

//--------Settery--------//
void Card::setCardNumber(QString value)
{
    cardNumber = value;
}

void Card::setIsCardBlocked(bool value)
{
    isCardBlocked = value;
}

void Card::setPin(int value)
{
    pin = value;
}

void Card::setAccountNumber(QString value)
{
    accountNumber = value;
}

void Card::setCardFilePath(QString value)
{
    cardFilePath = value;
}

//----Czyta karte z dysku----//
Card::CardState Card::readCardFile(QString sourceFile)
{
    cardFilePath = sourceFile;
    if(cardFilePath != "")
    {
        int positionOfDotExtension = sourceFile.lastIndexOf(".");
        if(sourceFile.mid(positionOfDotExtension) != ".card") //Sprawdzenie czy poz zmienna lokalizacja na pweno jest karta
        {
            return noCard;
        }
    }
    if(cardFilePath == "")
    {
        cardFilePath = QFileDialog::getOpenFileName(nullptr,"Wybierz kartę","","Karta (*.card)");
    }
    QFile cardFile(cardFilePath);
    if(cardFilePath.isNull() == false)
    {
        int line = 0;
        if(cardFile.open(QIODevice::ReadOnly))
        {

            QTextStream fileContent(&cardFile);
            while(fileContent.atEnd() == 0)
            {
                line++;
                if(line == 1)
                {
                    cardNumber = fileContent.readLine();
                }
                else if(line == 2)
                {
                    isCardBlocked = fileContent.readLine().split(" ")[0].toInt();
                }
                else if(line == 3)
                {
                    pin = fileContent.readLine().split(" ")[0].toInt();
                }
                else if(line == 4)
                {
                    accountNumber = fileContent.readLine();
                }
                else
                {
                    break;
                }
            }
            cardFile.close();
        }
        if(line == 4)
        {
            return readCard; //Gdy wczytano dwa ustawienia z karty oznacza to że jest poprawna
        }
        else
        {
            return brokenCard;//Gdy wczytano inną ilość lub karta ma więcej linii oznacza to, że jest niepoprawna
        }
    }
    else
    {
        return noCard; //Jeżeli nie wybrano pliku to karta jest niepoprawna
    }
}

//----Zapisuje kartę na dysk----//
bool Card::saveCardFile()
{
    QFile cardFile(cardFilePath);
    if(cardFilePath.isNull() == false)
    {
        if(cardFile.open(QIODevice::WriteOnly))
        {
            QTextStream fileContent(&cardFile);
            fileContent << cardNumber << endl;
            if(incorrectPinEnterCounter >= 3)
            {
               fileContent << "1" << endl;
            }
            else
            {
               fileContent << "0" << endl;
            }
            fileContent << pin << endl;
            fileContent << accountNumber;
            cardFile.close();
            return true;
        }
    }
    return false;
}

//----Sprawdza pin----//
bool Card::checkPin(int value)
{
    if(pin == value)
    {
        return true;
    }
    else
    {
        incorrectPinEnterCounter++;
        if(incorrectPinEnterCounter >= 3)
        {
            blockCard(true);
        }
        return false;
    }
}

//----Funkcja blokująca kartę po trzech nieudanych próbach sprawdzenia pinu----//
void Card::blockCard(bool value)
{
    isCardBlocked = value;
}
