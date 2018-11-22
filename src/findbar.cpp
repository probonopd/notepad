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
#include "findbar.hpp"
#include <QTimer>

FindBar::FindBar()
{
    textLine = new QLineEdit(this);
    addWidget(textLine, 1);
    closeButton = new QPushButton(QIcon::fromTheme("window-close"), "", this);
    closeButton->setFlat(true);
    closeButton->setShortcut(QKeySequence("Esc"));
    addWidget(closeButton);
    
    connect(textLine, &QLineEdit::textChanged, this, &FindBar::find);
    connect(closeButton, &QPushButton::pressed, this, &FindBar::closeClicked);
    QTimer::singleShot(0, textLine, SLOT(setFocus()));
}
FindBar::~FindBar()
{
    delete textLine, closeButton;
}
