#include <QMenu>

class FileMenu:public QMenu
{
Q_OBJECT 
public:
    FileMenu();
    ~FileMenu();
    
signals:
    void newWindowClick();
	void newFileclick();
	void openclick();
	/*void openShared();*/
	void saveclick();
	void saveasclick();
    void saveAll();
    void saveSession();
    void closeclick();
    void quitclick();
    
private:
    QAction *newAct, *newWindowAct, *openAct, /**openSharedAct,*/ *saveAct, *saveasAct, *saveAllAct,*saveSessionAct, *closeAct, *quitAct;
};
