#include<QApplication>

class NotepadApp : public QApplication
{
Q_OBJECT
public:
    NotepadApp(int& argc, char**& argv);
    ~NotepadApp();
    
public slots:
    void about();
    void newWindowInstance();
    void changeMenu(bool newValue);
    void changeFont();

private:
    bool menu = true;
    QFont *font = nullptr;
    
signals:
    void menuChanged(bool newValue);
    void fontChanged(QFont *newFont);
};
