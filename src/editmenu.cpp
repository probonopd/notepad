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
#include "editmenu.hpp"

EditMenu::EditMenu()
{
    setTitle("&Edit");
    
    undoAct = new QAction(QIcon::fromTheme("edit-undo"), tr("&Undo"));
    undoAct->setShortcut(QKeySequence::Undo);
    undoAct->setEnabled(false);
    addAction(undoAct);
    
    redoAct = new QAction(QIcon::fromTheme("edit-redo"), tr("&Redo"));
    redoAct->setShortcut(QKeySequence::Redo); 
    redoAct->setEnabled(false);
    addAction(redoAct);
    
    addSeparator();
    
    cutAct = new QAction(QIcon::fromTheme("edit-cut"), tr("&Cut"));
    cutAct->setShortcut(QKeySequence::Cut);
    cutAct->setEnabled(false);
	addAction(cutAct);
    
    copyAct = new QAction(QIcon::fromTheme("edit-copy"), tr("&Copy"));
    copyAct->setShortcut(QKeySequence::Copy);
    copyAct->setEnabled(false);
	addAction(copyAct);
    
    pasteAct = new QAction(QIcon::fromTheme("edit-paste"), tr("&Paste"));
    pasteAct->setShortcut(QKeySequence::Paste);
	addAction(pasteAct);
	
	addSeparator();
	
    findAct = new QAction(QIcon::fromTheme("edit-find"), tr("&Find"));
    findAct->setShortcut(QKeySequence::Find);
	addAction(findAct);
	
    connect(undoAct, &QAction::triggered, this, &EditMenu::undo);
    connect(redoAct, &QAction::triggered, this, &EditMenu::redo);
    connect(cutAct, &QAction::triggered, this, &EditMenu::cut);
    connect(copyAct, &QAction::triggered, this, &EditMenu::copy);
    connect(pasteAct, &QAction::triggered, this, &EditMenu::paste);
    connect(findAct, &QAction::triggered, this, &EditMenu::find);
}
void EditMenu::undoAvailable(bool available)
{
    undoAct->setEnabled(available);
}
void EditMenu::redoAvailable(bool available)
{
    redoAct->setEnabled(available);
}
void EditMenu::copyAvailable(bool available)
{
    copyAct->setEnabled(available);
    cutAct->setEnabled(available);
}
EditMenu::~EditMenu()
{
}
