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
#ifndef TABWIDGET_HPP
# define TABWIDGET_HPP

#include <QTabWidget>
#include <QMessageBox>
#include <QTabBar>
#include <QFile>
#include <QTextStream>
#include <QFont>

#include "textedit.hpp"

class TabWidget: public QTabWidget
{
Q_OBJECT
public:
    TabWidget(QWidget *parent, QFont *font);
    ~TabWidget();
    void setMenu(QMenu *menu=nullptr);
    void openFiles(QStringList files);
    void closeEvent(QCloseEvent *event);
    
public slots:
	void newFileCreate();
    void openFilesClicked();
    void saveclick();
    void saveas();
    void saveAll();
    void saveSession();
    void openSession();
    void print();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void setFont(QFont *newFont);
    void find();

private:
    void removeTab(int index);
    QPushButton *button = nullptr;
    QFont *font=nullptr;
    Textedit *findEdit = nullptr;
    
private slots:
    void closetab(int index);
    void changetabname(Textedit* textedit,  QString newtext,  bool edited);
    void onCurrentChange();
    
signals:
    void currentTextChanged(QString newtext);
    void undoAvailable(bool available);
    void redoAvailable(bool available);
    void copyAvailable(bool available);
};

#endif
