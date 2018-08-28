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
#include "mainwindow.hpp"
#include<iostream>
#include"notepadapp.hpp"
#include <QCalendarWidget>
#include <QDockWidget>
#include <QToolBar>

MainWindow::MainWindow(bool useMenu, /*QSharedMemory *memory, */QFont *font, QStringList *files)
{
//     sharedMemory = memory;
    
	tabwidget = new TabWidget(font);
	
	//t1 = new std::thread(this, &MainWindow::threadFunction);

    connect(tabwidget,  &TabWidget::currentTextChanged, this,  &QMainWindow::setWindowTitle);
    
    fileMenu = new FileMenu();
    editMenu = new EditMenu();
    setsMenu = new SetsMenu();
    helpMenu = new HelpMenu();

    connect(fileMenu, &FileMenu::newFileclick, tabwidget, &TabWidget::newFileCreate);
    connect(fileMenu, &FileMenu::newWindowClick, (NotepadApp*) qApp, &NotepadApp::newWindowInstance);
    connect(fileMenu, &FileMenu::openclick, tabwidget, &TabWidget::openFilesClicked);
//     connect(fileMenu, &FileMenu::openShared, this, &MainWindow::openShared);
    connect(fileMenu, &FileMenu::saveclick, tabwidget, &TabWidget::saveclick);
    connect(fileMenu, &FileMenu::saveasclick, tabwidget, &TabWidget::saveas);
    connect(fileMenu, &FileMenu::saveAll, tabwidget, &TabWidget::saveAll);
    connect(fileMenu, &FileMenu::saveSession, tabwidget, &TabWidget::saveSession);
    connect(fileMenu, &FileMenu::closeclick, this, &MainWindow::close);
    connect(fileMenu, &FileMenu::quitclick, qApp, &QApplication::closeAllWindows);
    
    connect(editMenu, &EditMenu::undo, tabwidget, &TabWidget::undo);
    connect(editMenu, &EditMenu::redo, tabwidget, &TabWidget::redo);
    connect(editMenu, &EditMenu::cut, tabwidget, &TabWidget::cut);
    connect(editMenu, &EditMenu::copy, tabwidget, &TabWidget::copy);
    connect(editMenu, &EditMenu::paste, tabwidget, &TabWidget::paste);
    connect(editMenu, &EditMenu::find, tabwidget, &TabWidget::find);

    connect(setsMenu, &SetsMenu::font, (NotepadApp*) qApp, &NotepadApp::changeFont); 

    connect(helpMenu, &HelpMenu::about, (NotepadApp*) qApp, &NotepadApp::about);
    connect(helpMenu, &HelpMenu::aboutQt, qApp, &QApplication::aboutQt);

    connect(tabwidget,  &TabWidget::undoAvailable, editMenu,  &EditMenu::undoAvailable);
    connect(tabwidget,  &TabWidget::redoAvailable, editMenu,  &EditMenu::redoAvailable);
    connect(tabwidget,  &TabWidget::copyAvailable, editMenu,  &EditMenu::copyAvailable);
    
    connect(setsMenu, &SetsMenu::menuChange, (NotepadApp*)qApp, &NotepadApp::changeMenu);
    
    setCentralWidget(tabwidget);
    if (files != nullptr) 
    {
        tabwidget->openFiles(*files);
        delete files;
    }
    else tabwidget->newFileCreate();
    if (useMenu) setsMenu->menuAct->setChecked(true);
    menu(useMenu);
    connect((NotepadApp*)qApp, &NotepadApp::menuChanged, this, &MainWindow::menu);
    connect((NotepadApp*)qApp, &NotepadApp::fontChanged, tabwidget, &TabWidget::setFont);
    QCalendarWidget *a = new QCalendarWidget;
    QDockWidget *b = new QDockWidget("Kalendarz");
    b -> setWidget(a);
    addDockWidget(Qt::LeftDockWidgetArea, b);
    QCalendarWidget *c = new QCalendarWidget;
    QDockWidget *d = new QDockWidget("Kalendarz");
    d -> setWidget(c);
    addDockWidget(Qt::LeftDockWidgetArea, d);
    auto fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction("New");
}
void MainWindow::menu(bool useMenuBar)
{
	if(useMenuBar)
	{
        menubar = new QMenuBar();
        menubar -> addMenu(fileMenu);
        menubar -> addMenu(editMenu);
        menubar -> addMenu(setsMenu);
        menubar -> addMenu(helpMenu);
        setMenuBar(menubar);
		tabwidget->setMenu();
    }
    else{
        if(menubar!=nullptr)
		{
            delete menubar;
            menubar = nullptr;
		}
        QMenu *menu = new QMenu();
        menu -> addMenu(fileMenu);
        menu -> addMenu(editMenu);
        menu -> addMenu(setsMenu);
        menu -> addMenu(helpMenu);
		tabwidget->setMenu(menu);
    }
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    tabwidget->closeEvent(event);
}
// void MainWindow::openShared()
// {
//      sharedMemory->lock();
//      auto* w = (QList<QUrl> *) sharedMemory->data();
//      tabwidget->openFiles(*w);
//      sharedMemory->unlock();
// }
// void MainWindow::threadFunction()
// {
//     while (runThread)
//     {
//         std::cout <<"Masło";
//     }
// }
MainWindow::~MainWindow()
{
    //runThread = false;
    //t1->join();    
}
