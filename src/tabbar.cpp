/*
notepad - Simple text editor with tabs
Copyright (C) 2018-2019  256Michael

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "tabbar.hpp"

TabBar::TabBar(QWidget *parent)
  : QTabBar::QTabBar(parent)
{
    setAcceptDrops(true);
    setChangeCurrentOnDrag(true);
}
TabBar::~TabBar()
{
}
void TabBar::mousePressEvent(QMouseEvent *event)
{
    if (tabAt(event->pos()) != -1&&event->button() == Qt::LeftButton) cardClicked = true;
    else cardClicked = false;
    QTabBar::mousePressEvent(event);
    qDebug()<<"Pressed";
}
void TabBar::mouseMoveEvent(QMouseEvent *event)
{
    if (cardClicked&&event->buttons() == Qt::LeftButton)
    {
        if (!rect().contains(event->pos()))
        {
            unsetCursor();
            if(!tabDetached){
                emit tabDragOut();
                tabDetached=true;
            }
        }
        else 
        {
            setCursor(Qt::DragMoveCursor);
            QTabBar::mouseMoveEvent(event);
        }
    }
    else
    {
        QTabBar::mouseMoveEvent(event);
        unsetCursor();
    }
}
void TabBar::mouseReleaseEvent(QMouseEvent *event)
{
    tabDetached=false;
    unsetCursor();
    QTabBar::mouseReleaseEvent(event);
}
void TabBar::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-notepad-textedit")||event->mimeData()->hasUrls()) event->ignore();
    else QTabBar::dragEnterEvent(event);
}
void TabBar::dropEvent(QDropEvent *event)
{
    event->ignore();
}
