#ifndef CPRZYCISK_H
#define CPRZYCISK_H

#include <QPushButton>
#include <QObject>
#include <QMimeData>
#include <QDropEvent>

class CPrzycisk : public QPushButton
{
    Q_OBJECT
signals:
    void upuszczono();

public:
    CPrzycisk(const QString &text, QWidget *parent = Q_NULLPTR);
private:
    QString lokalizacja;

public:
    //----Getter-----//
    QString zwrocLokalizacje();

public slots:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // CPRZYCISK_H
