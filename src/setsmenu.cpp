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
#include "setsmenu.hpp"

SetsMenu::SetsMenu(bool menuChecked, bool toolBarChecked)
{
    setTitle(tr("&Settings"));
        
    fontAct = new QAction(QIcon::fromTheme("font-select-symbolic"), tr("&Font"));
	addAction(fontAct);
	
	menuAct = new QAction(tr("&Menu bar"));
	menuAct->setCheckable(true);
	menuAct->setChecked(menuChecked);
	addAction(menuAct);
	
	toolBarAct = new QAction(tr("&Tool bar"));
	toolBarAct->setCheckable(true);
	toolBarAct->setChecked(toolBarChecked);
	addAction(toolBarAct);
	
	connect(fontAct, &QAction::triggered, this, &SetsMenu::font);
	connect(menuAct, &QAction::toggled, this, &SetsMenu::menuChange);
	connect(toolBarAct, &QAction::toggled, this, &SetsMenu::toolBarChange);
}
SetsMenu::~SetsMenu()
{
}
