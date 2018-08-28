#include"notepadapp.hpp"
#include<QMessageBox>
#include "mainwindow.hpp"
#include <iostream>
#include <QCommandLineParser>
#include <QLabel>
#include <QList>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QFontDialog>


NotepadApp::NotepadApp(int& argc, char**& argv)
  : QApplication::QApplication(argc, argv)
{
    setApplicationName("Notatnik");
    setApplicationDisplayName("Notatnik");
    setApplicationVersion("0.5 Beta");
    setWindowIcon(QIcon::fromTheme("accessories-text-editor"));
//     QList<QUrl> *files = nullptr;
//     if (argc != 0)
//     {
//         files = new QList<QUrl>();
//         for(int i = 1;i<argc;i++)
//         {
//             files->append(QUrl(argv[i]));
//         }     
//     }
    QCommandLineParser parser;
    parser.setApplicationDescription("Prosty edytor tekstu");
    parser.addHelpOption();
    parser.addVersionOption();
    //Add information to help page
    parser.addPositionalArgument("files", QCoreApplication::translate("main", "Files to open."));
    parser.process(*this);
    const QStringList args = this->arguments();
    QStringList *files = new QStringList;
    for (int i = 1;i<args.size();i++)
    {
        files->append(args.at(i));
    }
    QFile file(applicationDirPath()+"/config");
    
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString a = stream.readLine();
        if (a != "" ) {
            font = new QFont();
            font->fromString(a);
        }
        a = stream.readLine();
        if (a=="true")
            menu = true;

        else menu = false;
        file.close();
    } 
    MainWindow *window = new MainWindow(menu, font,  files);
    window->show();
}

NotepadApp::~NotepadApp()
{
    QFile file(applicationDirPath()+"/config");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        if(font!=nullptr) stream << font->toString();
        stream << "\n";
        if(menu)  
        {
           stream<<"true";
        }
        else stream<<"false";
        file.close();
    }
}
void NotepadApp::about()
{
    QMessageBox::about(activeWindow(), tr("O notatniku"),
            tr("Notatnik-Prosty edytor tekstu"));
}
void NotepadApp::newWindowInstance()
{
    MainWindow *newWindow = new MainWindow(menu, font);
    newWindow -> show();
}
void NotepadApp::changeMenu(bool newValue)
{
    menu = newValue;
    emit menuChanged(menu);
}
void NotepadApp::changeFont()
{
    bool ok;
    if (font ==  nullptr) font = new QFont();
    *font = QFontDialog::getFont(&ok, *font, activeWindow());
    if (ok) {
        emit fontChanged(font);
    }
}
