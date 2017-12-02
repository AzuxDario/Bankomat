#ifndef SCREEN_H
#define SCREEN_H

#include <QString>

class Screen
{
private:
    QString textA;
    QString textB;
    QString textC;
    QString textD;
    QString textE;
    QString textF;
    QString textG;
    QString textH;

public:
    Screen();

    void setTextA(QString value) {textA = value;}
    void setTextB(QString value) {textB = value;}
    void setTextC(QString value) {textC = value;}
    void setTextD(QString value) {textD = value;}
    void setTextE(QString value) {textE = value;}
    void setTextF(QString value) {textF = value;}
    void setTextG(QString value) {textG = value;}
    void setTextH(QString value) {textH = value;}
    QString getTextA() {return textA;}
    QString getTextB() {return textA;}
    QString getTextC() {return textA;}
    QString getTextD() {return textA;}
    QString getTextE() {return textA;}
    QString getTextF() {return textA;}
    QString getTextG() {return textA;}
    QString getTextH() {return textA;}
};

#endif // SCREEN_H
