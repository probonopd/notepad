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
#include "filemenu.hpp"

FileMenu::FileMenu()
:newAct(QIcon::fromTheme("document-new"), tr("&New")),
newWindowAct(QIcon::fromTheme("window-new"), tr("New &window")),
openAct(QIcon::fromTheme("document-open"), tr("&Open...")),
saveAct(QIcon::fromTheme("document-save"), tr("&Save")),
saveasAct(QIcon::fromTheme("document-save-as"), tr("Sa&ve as...")),
saveAllAct(QIcon::fromTheme("document-save-all"), tr("Save &all")),
saveSessionAct(QIcon::fromTheme("document-save"), tr("Sav&e session")),
openSessionAct(QIcon::fromTheme("document-open"), tr("O&pen session")),
printAct(QIcon::fromTheme("document-print"), tr("&Print")),
closeAct(QIcon::fromTheme("window-close"), tr("&Close window")),
quitAct(QIcon::fromTheme("application-exit"), tr("&Quit"))
{
    setTitle(tr("&File"));
    
    newAct.setShortcut(QKeySequence::New);
	addAction(&newAct);
	
	addSeparator();
	
    //newAct.setShortcut(QKeySequence::New);
	addAction(&newWindowAct);
	
	addSeparator();
	
    openAct.setShortcut(QKeySequence::Open);
	addAction(&openAct);
	
	addSeparator();

    saveAct.setShortcut(QKeySequence::Save);
	addAction(&saveAct);
    
    saveasAct.setShortcut(QKeySequence::SaveAs);
    addAction(&saveasAct);
    
	addAction(&saveAllAct);
	
	addSeparator();
	
	addAction(&saveSessionAct);
	
	addAction(&openSessionAct);
	
	addSeparator();
	
	printAct.setShortcut(QKeySequence::Print);
	addAction(&printAct);
	
	addSeparator();
	
    closeAct.setShortcut(QKeySequence::Close);
    addAction(&closeAct);
    
    addSeparator();
    
    quitAct.setShortcut(QKeySequence::Quit);
    addAction(&quitAct);
    
    connect(&newAct, &QAction::triggered, this, &FileMenu::newFileclick);
    connect(&newWindowAct, &QAction::triggered, this, &FileMenu::newWindowClick);
	connect(&openAct, &QAction::triggered, this, &FileMenu::openclick);
    connect(&saveAct, &QAction::triggered, this, &FileMenu::saveclick);
    connect(&saveasAct, &QAction::triggered, this, &FileMenu::saveasclick);
    connect(&saveAllAct, &QAction::triggered, this, &FileMenu::saveAll);
    connect(&saveSessionAct, &QAction::triggered, this, &FileMenu::saveSession);
    connect(&openSessionAct, &QAction::triggered, this, &FileMenu::openSession);
    connect(&printAct, &QAction::triggered, this, &FileMenu::print);
    connect(&closeAct, &QAction::triggered, this, &FileMenu::closeclick);
    connect(&quitAct, &QAction::triggered, this, &FileMenu::quitclick);
}
FileMenu::~FileMenu()
{
}
