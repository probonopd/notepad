#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <QPlainTextEdit>
#include <QTextStream>
#include <QFileDialog>
#include <QPlainTextEdit>
#include <QDebug>
#include <QPushButton>

class Textedit : public QPlainTextEdit
{
Q_OBJECT
public:
	Textedit();
	~Textedit();
    bool openfile(QString fileurl);
    void saveclick();
    void saveas();
    bool isEdited() {return edited;};
    QString Url() {return url;};
    QPushButton *button = nullptr;
    bool isUndoAvailable(){return canUndo;};
    bool isRedoAvailable(){return canRedo;};
    bool isCopyAvailable(){return canCopy;};
private:
    QString url;
    bool edited = false;
    void save();
    bool canUndo=false;
    bool canRedo=false;
    bool canCopy=false;
private slots:
    void onchange();
    void setUndo(bool available);
    void setRedo(bool available);
    void setCopy(bool available);
signals:
    void tabtextchange(Textedit *textedit,  QString newtext,  bool edited);
};

#endif // TEXTEDIT_HPP
