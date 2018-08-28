#include "editmenu.hpp"

EditMenu::EditMenu()
{
    setTitle("&Edycja");
    
    undoAct = new QAction(QIcon::fromTheme("edit-undo"), tr("&Cofnij"));
    undoAct->setShortcut(QKeySequence::Undo);
    undoAct->setEnabled(false);
    addAction(undoAct);
    
    redoAct = new QAction(QIcon::fromTheme("edit-redo"), tr("&Powtórz"));
    redoAct->setShortcut(QKeySequence::Redo); 
    redoAct->setEnabled(false);
    addAction(redoAct);
    
    addSeparator();
    
    cutAct = new QAction(QIcon::fromTheme("edit-cut"), tr("&Wytnij"));
    cutAct->setShortcut(QKeySequence::Cut);
    cutAct->setEnabled(false);
	addAction(cutAct);
    
    copyAct = new QAction(QIcon::fromTheme("edit-copy"), tr("&Kopiuj"));
    copyAct->setShortcut(QKeySequence::Copy);
    copyAct->setEnabled(false);
	addAction(copyAct);
    
    pasteAct = new QAction(QIcon::fromTheme("edit-paste"), tr("&Wklej"));
    pasteAct->setShortcut(QKeySequence::Paste);
	addAction(pasteAct);
	
	addSeparator();
	
    findAct = new QAction(QIcon::fromTheme("edit-find"), tr("&Znajdź"));
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
