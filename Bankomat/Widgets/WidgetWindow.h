#ifndef WIDGETWIDNOW_H
#define WIDGETWIDNOW_H

#include <QWidget>
#include <QDesktopWidget>
#include <QApplication>

class WidgetWindow : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetWindow(QWidget *parent = 0);

signals:

private slots:
    void closeWindow(); //Zamyka okno

public slots:
    void showWindow(); //Pokazuje już utworzone okno
};

#endif // WIDGETWIDNOW_H
