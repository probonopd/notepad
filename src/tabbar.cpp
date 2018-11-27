#include "tabbar.hpp"

TabBar::TabBar()
{
    setAcceptDrops(true);
}
TabBar::~TabBar()
{
}
void TabBar::mousePressEvent(QMouseEvent *event)
{
    if (tabAt(event->pos()) == -1) cardClicked = false;
    else cardClicked = true;
    QTabBar::mousePressEvent(event);
}
void TabBar::mouseMoveEvent(QMouseEvent *event)
{
    if (cardClicked)
    {
        if (!rect().contains(event->pos()))
        {
            QMimeData *data = new QMimeData;
            data->setColorData(QColor(0x906090));

            QDrag *drag = new QDrag(this);
            drag->setMimeData(data);
            drag->start();
            qDebug() << "Leave";
            delete drag;
        }
        else 
        {
            qDebug() << "AAA";
            setCursor(Qt::ClosedHandCursor);
            QTabBar::mouseMoveEvent(event);
        }
    }
    else QTabBar::mouseMoveEvent(event);
}
