#include "cprzycisk.h"

CPrzycisk::CPrzycisk(const QString &text, QWidget *parent) : QPushButton(text,parent)
{
    setAcceptDrops(true);
    lokalizacja = "";
}

//--------Getter---------//
QString CPrzycisk::zwrocLokalizacje()
{
    return lokalizacja;
}

void CPrzycisk::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void CPrzycisk::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}
void CPrzycisk::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();
        lokalizacja = urlList.at(0).toLocalFile();
    }
    event->acceptProposedAction();
    emit upuszczono();
}
