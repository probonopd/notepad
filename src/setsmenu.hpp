#include <QMenu>

class SetsMenu:public QMenu
{
Q_OBJECT
public:
    SetsMenu();
    ~SetsMenu();
    QAction *menuAct;
    
private:
    QAction *fontAct;
    
signals:
    void font();
    void menuChange(bool useMenuBar);
};
