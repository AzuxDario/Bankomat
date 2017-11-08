#include "Account.h"

Account::Account()
{

}

Account::Account(QString numerKonta)
{
    this->accountNumber = numerKonta;
    readAccount();
}

//--------Gettery--------//
QString Account::getName()
{
    return name;
}

QString Account::getSurname()
{
    return surname;
}

QString Account::getAccountNumber()
{
    return accountNumber;
}

double Account::getBalance()
{
    return balance;
}

//--------Settery--------//
void Account::setName(QString value)
{
    name = value;
}

void Account::setSurname(QString value)
{
    surname = value;
}

void Account::setAccountNumber(QString value)
{
    accountNumber = value;
}

void Account::setBalance(double value)
{
    balance = value;
}

//----Pobiera kwotę z konta----//
void Account::withdraw(double amount)
{
    balance -= amount;
    writeAccount();
}

//----Odczytuje plik konta z dysku----//
bool Account::readAccount()
{
    QString path = "";
    QFile accoutnFile(path + "accounts" + QDir::separator() + accountNumber + ".acc");
    if(accountNumber.isNull() == false)
    {
        if(accoutnFile.open(QIODevice::ReadOnly))
        {
            QTextStream fileContent(&accoutnFile);
            name = fileContent.readLine();
            surname = fileContent.readLine();
            balance = fileContent.readLine().toDouble();
            accoutnFile.close();
        }
        return true;
    }
    else
    {
        return false;
    }
}

//----Zapisuje plik konta na dysku----//
bool Account::writeAccount()
{
    QString path = "";
    QFile accountFile(path + "accounts" + QDir::separator() + accountNumber + ".acc");
    if(accountNumber.isNull() == false)
    {
        if(accountFile.open(QIODevice::WriteOnly))
        {
            QTextStream fileContent(&accountFile);
            fileContent << name << endl;
            fileContent << surname << endl;
            fileContent << balance;
            accountFile.close();
            return true;
        }
    }
    return false;
}
