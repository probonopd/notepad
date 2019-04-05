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

class EditMenu : public QMenu
{
Q_OBJECT
public:
    EditMenu();
    ~EditMenu();
    
signals:
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void find();
    
private:
    QAction undoAct, redoAct, cutAct, copyAct , pasteAct, findAct;
    
public slots:
    void undoAvailable(bool available);
    void redoAvailable(bool available);
    void copyAvailable(bool available);
};
