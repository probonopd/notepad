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

class FileMenu:public QMenu
{
Q_OBJECT 
public:
    FileMenu();
    ~FileMenu();
    
signals:
    void newWindowClick();
	void newFileclick();
	void openclick();
	void saveclick();
	void saveasclick();
    void saveAll();
    void saveSession();
    void openSession();
    void print();
    void closeclick();
    void quitclick();
    
private:
    QAction *newAct, *newWindowAct, *openAct, *saveAct, *saveasAct, *saveAllAct,*saveSessionAct, *openSessionAct, *printAct, *closeAct, *quitAct;
};
