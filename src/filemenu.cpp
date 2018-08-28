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
#include "filemenu.hpp"

FileMenu::FileMenu()
{
    setTitle("&Plik");
    
    newAct = new QAction(QIcon::fromTheme("document-new"), tr("&Nowy"));
    newAct->setShortcut(QKeySequence::New);
	addAction(newAct);
	
	addSeparator();
	
	newWindowAct = new QAction(QIcon::fromTheme("window-new"), tr("&Nowe okno"));
    //newAct->setShortcut(QKeySequence::New);
	addAction(newWindowAct);
	
	addSeparator();
	
    openAct = new QAction(QIcon::fromTheme("document-open"), tr("&Otwórz..."));
    openAct->setShortcut(QKeySequence::Open);
	addAction(openAct);
	
	addSeparator();
	
// 	openSharedAct = new QAction(QIcon::fromTheme("document-open"), tr("&Otwórz z pamięci..."));
// 	addAction(openSharedAct);
//     
//     addSeparator();
    
    saveAct = new QAction(QIcon::fromTheme("document-save"), tr("&Zapisz"));
    saveAct->setShortcut(QKeySequence::Save);
	addAction(saveAct);
    
    saveasAct = new QAction(QIcon::fromTheme("document-save-as"), tr("&Zapisz jako..."));
    saveasAct->setShortcut(QKeySequence::SaveAs);
    addAction(saveasAct);
    
    saveAllAct = new QAction(QIcon::fromTheme("document-save-all"), tr("&Zapisz wszystko"));
	addAction(saveAllAct);
	
	addSeparator();
	
    saveSessionAct = new QAction(QIcon::fromTheme("document-save-all"), tr("&Zapisz sesje"));
	addAction(saveSessionAct);
	
	addSeparator();
	
    closeAct = new QAction(QIcon::fromTheme("window-close"), tr("&Zamknij okno"));
    closeAct->setShortcut(QKeySequence::Close);
    addAction(closeAct);
    
    addSeparator();
    
    quitAct = new QAction(QIcon::fromTheme("application-exit"), tr("&Zakończ"));
    quitAct->setShortcut(QKeySequence::Quit);
    addAction(quitAct);
    
    connect(newAct, &QAction::triggered, this, &FileMenu::newFileclick);
    connect(newWindowAct, &QAction::triggered, this, &FileMenu::newWindowClick);
	connect(openAct, &QAction::triggered, this, &FileMenu::openclick);
// 	connect(openSharedAct, &QAction::triggered, this, &FileMenu::openShared);
    connect(saveAct, &QAction::triggered, this, &FileMenu::saveclick);
    connect(saveasAct, &QAction::triggered, this, &FileMenu::saveasclick);
    connect(saveAllAct, &QAction::triggered, this, &FileMenu::saveAll);
    connect(saveSessionAct, &QAction::triggered, this, &FileMenu::saveSession);
    connect(closeAct, &QAction::triggered, this, &FileMenu::closeclick);
    connect(quitAct, &QAction::triggered, this, &FileMenu::quitclick);
}
FileMenu::~FileMenu()
{
}
