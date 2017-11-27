#ifndef CPRZYCISK_H
#define CPRZYCISK_H

#include <QPushButton>
#include <QObject>
#include <QMimeData>
#include <QDropEvent>

class DropButton : public QPushButton
{
    Q_OBJECT
signals:
    void dropped();

public:
    DropButton(const QString &text, QWidget *parent = Q_NULLPTR);
private:
    QString directory;

public:
    //----Getter-----//
    QString getDirectory();

public slots:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // CPRZYCISK_H
