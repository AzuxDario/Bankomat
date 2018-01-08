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
    QString getDirectory() {return directory;}

public slots:
    void dragEnterEvent(QDragEnterEvent *event) {event->acceptProposedAction();}
    void dragMoveEvent(QDragMoveEvent *event) {event->acceptProposedAction();}
    void dropEvent(QDropEvent *event);
};

#endif // CPRZYCISK_H
