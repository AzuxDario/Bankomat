#ifndef WIDGETOKNO_H
#define WIDGETOKNO_H

#include <QWidget>
#include <QDesktopWidget>
#include <QApplication>

class WidgetOkno : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetOkno(QWidget *parent = 0);

signals:

private slots:
    void zamknijOkno(); //Zamyka okno

public slots:
    void pokazSie(); //Pokazuje już utworzone okno
};

#endif // WIDGETOKNO_H
