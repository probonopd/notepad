#include <QMenu>

class HelpMenu:public QMenu
{
Q_OBJECT
public:
    HelpMenu();
    ~HelpMenu(); 

private:
    QAction *aboutAct, *aboutQtAct;
    
signals:
    void about();
    void aboutQt();
};
