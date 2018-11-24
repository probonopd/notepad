#include "tabbar.hpp"

TabBar::TabBar()
{
}
TabBar::~TabBar()
{
}
void TabBar::mouseMoveEvent(QMouseEvent *event)
{
    if (!rect().contains(event->pos()))
    {
        QMimeData *data = new QMimeData;
        data->setColorData(QColor(0x906090));

        QDrag *drag = new QDrag(this);
        drag->setMimeData(data);
        drag->start();
        qDebug() << "Leave";
    }
    else QTabBar::mouseMoveEvent(event);
}
