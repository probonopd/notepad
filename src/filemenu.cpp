#include "filemenu.hpp"

FileMenu::FileMenu()
{
    setTitle("&Plik");
    
    newAct = new QAction(QIcon::fromTheme("document-new"), tr("&Nowy"));
    newAct->setShortcut(QKeySequence::New);
	addAction(newAct);
	
	addSeparator();
	
	newWindowAct = new QAction(QIcon::fromTheme("window-new"), tr("&Nowe okno"));
    //newAct->setShortcut(QKeySequence::New);
	addAction(newWindowAct);
	
	addSeparator();
	
    openAct = new QAction(QIcon::fromTheme("document-open"), tr("&Otwórz..."));
    openAct->setShortcut(QKeySequence::Open);
	addAction(openAct);
	
	addSeparator();
	
// 	openSharedAct = new QAction(QIcon::fromTheme("document-open"), tr("&Otwórz z pamięci..."));
// 	addAction(openSharedAct);
//     
//     addSeparator();
    
    saveAct = new QAction(QIcon::fromTheme("document-save"), tr("&Zapisz"));
    saveAct->setShortcut(QKeySequence::Save);
	addAction(saveAct);
    
    saveasAct = new QAction(QIcon::fromTheme("document-save-as"), tr("&Zapisz jako..."));
    saveasAct->setShortcut(QKeySequence::SaveAs);
    addAction(saveasAct);
    
    saveAllAct = new QAction(QIcon::fromTheme("document-save-all"), tr("&Zapisz wszystko"));
	addAction(saveAllAct);
	
	addSeparator();
	
    saveSessionAct = new QAction(QIcon::fromTheme("document-save-all"), tr("&Zapisz sesje"));
	addAction(saveSessionAct);
	
	addSeparator();
	
    closeAct = new QAction(QIcon::fromTheme("window-close"), tr("&Zamknij okno"));
    closeAct->setShortcut(QKeySequence::Close);
    addAction(closeAct);
    
    addSeparator();
    
    quitAct = new QAction(QIcon::fromTheme("application-exit"), tr("&Zakończ"));
    quitAct->setShortcut(QKeySequence::Quit);
    addAction(quitAct);
    
    connect(newAct, &QAction::triggered, this, &FileMenu::newFileclick);
    connect(newWindowAct, &QAction::triggered, this, &FileMenu::newWindowClick);
	connect(openAct, &QAction::triggered, this, &FileMenu::openclick);
// 	connect(openSharedAct, &QAction::triggered, this, &FileMenu::openShared);
    connect(saveAct, &QAction::triggered, this, &FileMenu::saveclick);
    connect(saveasAct, &QAction::triggered, this, &FileMenu::saveasclick);
    connect(saveAllAct, &QAction::triggered, this, &FileMenu::saveAll);
    connect(saveSessionAct, &QAction::triggered, this, &FileMenu::saveSession);
    connect(closeAct, &QAction::triggered, this, &FileMenu::closeclick);
    connect(quitAct, &QAction::triggered, this, &FileMenu::quitclick);
}
FileMenu::~FileMenu()
{
}
