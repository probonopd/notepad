#include "helpmenu.hpp"

HelpMenu::HelpMenu()
{
    setTitle("&Pomoc");
    
    aboutAct = new QAction(QIcon::fromTheme("accessories-text-editor"), tr("&O programie Notatnik"));
	addAction(aboutAct);
	
    aboutQtAct = new QAction(QIcon::fromTheme("accessories-text-editor"), tr("&O bibliotece Qt"));
	addAction(aboutQtAct);
	
    connect(aboutAct, &QAction::triggered, this, &HelpMenu::about);
    connect(aboutQtAct, &QAction::triggered, this, &HelpMenu::aboutQt);
}
HelpMenu::~HelpMenu()
{
}
