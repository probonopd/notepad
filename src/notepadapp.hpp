/*
notepad - Simple text editor with tabs
Copyright (C) 2018  256Michael

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
#include <QTranslator>
#include <QApplication>
#include <QMessageBox>
#include <QCommandLineParser>
#include <QLabel>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QFontDialog>
#include <QFileInfo>
#include <QLibraryInfo>

#include "mainwindow.hpp"

class NotepadApp : public QApplication
{
Q_OBJECT
public:
    NotepadApp(int& argc, char**& argv);
    ~NotepadApp();
    
public slots:
    void about();
    MainWindow* newWindowInstance();
    void changeMenu(bool newValue);
    void changeToolBar(bool newValue);
    void changeFont();

private:
    bool menu = true;
    bool toolBarEnabled = true;
    QFont *font = nullptr;
    
signals:
    void menuChanged(bool newValue);
    void toolBarChanged(bool newValue);
    void fontChanged(QFont *newFont);
};
