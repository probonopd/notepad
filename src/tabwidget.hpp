#ifndef TABWIDGET_HPP
# define TABWIDGET_HPP

#include <QTabWidget>
#include <QMessageBox>
#include <QTabBar>
#include "textedit.hpp"
#include <QFile>
#include <QTextStream>
#include <QFont>

class TabWidget: public QTabWidget
{
Q_OBJECT
public:
    TabWidget(QFont *font);
    void setMenu(QMenu *menu=nullptr);
    ~TabWidget();
    void openFiles(QStringList files);
    void closeEvent(QCloseEvent *event);
    
public slots:
	void newFileCreate();
    void openFilesClicked();
    void saveclick();
    void saveas();
    void saveAll();
    void saveSession();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void find();
    void setFont(QFont *newFont);

private:
    QPushButton *button = nullptr;
    QFont *font=nullptr;
    
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
