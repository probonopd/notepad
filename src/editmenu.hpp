#include <QMenu>

class EditMenu : public QMenu
{
Q_OBJECT
public:
    EditMenu();
    ~EditMenu();
    
signals:
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void find();
    
private:
    QAction *undoAct, *redoAct, *cutAct, *copyAct , *pasteAct, *findAct;
    
public slots:
    void undoAvailable(bool available);
    void redoAvailable(bool available);
    void copyAvailable(bool available);
};
