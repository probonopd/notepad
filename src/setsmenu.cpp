#include "setsmenu.hpp"

SetsMenu::SetsMenu()
{
    setTitle("&Ustawienia");
        
    fontAct = new QAction(QIcon::fromTheme("font-select-symbolic"), tr("&Czcionka"));
	addAction(fontAct);
	
	menuAct = new QAction(tr("&Pasek menu"));
	menuAct->setCheckable(true);
	addAction(menuAct);
	
	connect(fontAct, &QAction::triggered, this, &SetsMenu::font);
	connect(menuAct, &QAction::toggled, this, &SetsMenu::menuChange);
}
SetsMenu::~SetsMenu()
{
}
