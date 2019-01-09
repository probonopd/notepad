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
#pragma once
#include <QMenu>

class HelpMenu:public QMenu
{
Q_OBJECT
public:
    HelpMenu();
    ~HelpMenu(); 

private:
    QAction *aboutAct, *aboutQtAct;
    
signals:
    void about();
    void aboutQt();
};
