#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
 
#include <QApplication>
#include <QObject>
#include <QMainWindow>
#include <QMenuBar>
#include "filemenu.hpp"
#include "editmenu.hpp"
#include "setsmenu.hpp"
#include "helpmenu.hpp"
#include "tabwidget.hpp"
#include <QSharedMemory>
#include <thread>

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow(bool useMenu, /*QSharedMemory *memory = nullptr,*/QFont *font, QStringList *files = nullptr);
	~MainWindow();
	
private slots:
    void closeEvent(QCloseEvent *event);
    void menu(bool useMenuBar = true);
// 	void openShared();
    
private:
//     QSharedMemory *sharedMemory;
//     std::thread *t1;
//     bool runThread = true;
//     void threadFunction();
	FileMenu *fileMenu=nullptr;
	EditMenu *editMenu;
	SetsMenu *setsMenu;
	HelpMenu *helpMenu;
	QMenuBar *menubar=nullptr;
	TabWidget *tabwidget;
};



#endif // MAINWINDOW_HPP
