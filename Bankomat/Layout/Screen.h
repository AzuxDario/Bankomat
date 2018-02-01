#ifndef SCREEN_H
#define SCREEN_H

#include <QString>

class Screen
{
private:
    QString mainText;
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
    Screen(QString mainText, QString textA, QString textB, QString textC, QString textD, QString textE, QString textF, QString textG, QString textH);

    void setMainText(QString value) {mainText = value;}
    void setTextA(QString value) {textA = value;}
    void setTextB(QString value) {textB = value;}
    void setTextC(QString value) {textC = value;}
    void setTextD(QString value) {textD = value;}
    void setTextE(QString value) {textE = value;}
    void setTextF(QString value) {textF = value;}
    void setTextG(QString value) {textG = value;}
    void setTextH(QString value) {textH = value;}
    QString getMainText() {return mainText;}
    QString getTextA() {return textA;}
    QString getTextB() {return textB;}
    QString getTextC() {return textC;}
    QString getTextD() {return textD;}
    QString getTextE() {return textE;}
    QString getTextF() {return textF;}
    QString getTextG() {return textG;}
    QString getTextH() {return textH;}
};

#endif // SCREEN_H
