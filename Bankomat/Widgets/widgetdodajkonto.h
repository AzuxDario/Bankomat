#ifndef WIDGETDODAJKONTO_H
#define WIDGETDODAJKONTO_H

#include "widgetokno.h"
#include "ckonto.h"
#include "ckarta.h"
#include <QDate>
#include <QTime>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QMessageBox>

namespace Ui {
class WidgetDodajKonto;
}

class WidgetDodajKonto : public WidgetOkno
{
    Q_OBJECT

public:
    explicit WidgetDodajKonto(WidgetOkno *parent = 0);
    ~WidgetDodajKonto();

private:
    Ui::WidgetDodajKonto *ui;

    //----Przyciski----//
    QPushButton *przyciskOk;
    QPushButton *przyciskAnuluj;

    //----Layout----//
    QGridLayout *layout;

    //----GroupBox----//
    QGroupBox *grupa;

    //----Labele opsiujące pola----//
    QLabel *imie;
    QLabel *nazwisko;
    QLabel *pin;
    QLabel *stanKonta;

    //----Pola do wpisania wartości----//
    QLineEdit *podajImie;
    QLineEdit *podajNazwisko;
    QSpinBox *podajPin;
    QDoubleSpinBox *podajStanKonta;

    CKarta *karta;
    CKonto *konto;

private slots:
    void zamknijOknoOk(); //Zamyka okno zachowując zmiany
    void zamknijOknoAnuluj(); //Zamyka okno nie zachowując zmian
    void closeEvent(QCloseEvent *); //Zamyka okno nie zachowując zmian
    void zerujPola(); //Zeruje wartości w polach
    bool utworzKonto(QString nazwaPliku); //Procedura zapisu plików karty i konta

};

#endif // WIDGETDODAJKONTO_H
