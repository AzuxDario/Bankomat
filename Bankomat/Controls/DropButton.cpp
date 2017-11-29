#include "DropButton.h"

DropButton::DropButton(const QString &text, QWidget *parent) : QPushButton(text,parent)
{
    setAcceptDrops(true);
    directory = "";
}

void DropButton::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();
        directory = urlList.at(0).toLocalFile();
    }
    event->acceptProposedAction();
    emit dropped();
}
