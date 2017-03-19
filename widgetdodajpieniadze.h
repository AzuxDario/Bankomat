#ifndef WIDGETDODAJPIENIADZE_H
#define WIDGETDODAJPIENIADZE_H

#include "widgetokno.h"
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include <QGroupBox>
#include <QGridLayout>
#include "ckasetapieniedzy.h"

namespace Ui {
class WidgetDodajPieniadze;
}

class WidgetDodajPieniadze : public WidgetOkno
{
    Q_OBJECT

public:
    explicit WidgetDodajPieniadze(CKasetaPieniedzy *kaseta, WidgetOkno *parent = 0);
    ~WidgetDodajPieniadze();

private:
    Ui::WidgetDodajPieniadze *ui;

    //----Przyciski----//
    QPushButton *przyciskOk;
    QPushButton *przyciskAnuluj;

    //----Layout----//
    QGridLayout *layoutPieniadzeObecne;
    QGridLayout *layoutPieniadzeDokladane;

    //----GroupBoxy----//
    QGroupBox *pieniadzeObecne;
    QGroupBox *pieniadzeDokladane;

    //----Pola gdzie będzie wartość obecna----//
    QLabel *obecneTekst200;
    QLabel *obecneTekst100;
    QLabel *obecneTekst50;
    QLabel *obecneTekst20;
    QLabel *obecneTekst10;
    QLabel *obecneTekst5;
    QLabel *obecneTekst2;
    QLabel *obecneTekst1;

    //----Labele opsiujące pola----//
    QLineEdit *obecnePole200;
    QLineEdit *obecnePole100;
    QLineEdit *obecnePole50;
    QLineEdit *obecnePole20;
    QLineEdit *obecnePole10;
    QLineEdit *obecnePole5;
    QLineEdit *obecnePole2;
    QLineEdit *obecnePole1;

    //----Pola gdzie będzie wartość dodawana----//
    QSpinBox *pole200;
    QSpinBox *pole100;
    QSpinBox *pole50;
    QSpinBox *pole20;
    QSpinBox *pole10;
    QSpinBox *pole5;
    QSpinBox *pole2;
    QSpinBox *pole1;

    //----Labele opsiujące pola----//
    QLabel *tekst200;
    QLabel *tekst100;
    QLabel *tekst50;
    QLabel *tekst20;
    QLabel *tekst10;
    QLabel *tekst5;
    QLabel *tekst2;
    QLabel *tekst1;

    //----Kaseta pieniędzy----//
    CKasetaPieniedzy *kaseta;

private slots:
    void zamknijOknoOk(); //Zamyka okno zachowując zmiany
    void zamknijOknoAnuluj(); //Zamyka okno nie zachowując zmian
    void closeEvent(QCloseEvent *); //Zamyka okno nie zachowując zmian
    void zerujPola(); //Zeruje wartości w polach
    void ustawObecnaIloscPieniedzy(); //Wpisuje w pola obecna ilosc pieniedzy
    void ustawMaksymalnaIloscDokladanychPieniedzy(); //Pilnuje aby nie można było włożyć więcej niż 1000 sztuk danego nominału
public slots:
    void pokazSie();
};

#endif // WIDGETDODAJPIENIADZE_H
