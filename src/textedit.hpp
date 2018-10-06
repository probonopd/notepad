/*
notepad - Simple text editor with tabs
Copyright (C) 2018  256Michael

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <QPushButton>
#include <QInputDialog>
#include <KTextEditor/Document>
#include <KTextEditor/Editor>
#include <KTextEditor/View>
#include <QVBoxLayout>

class Textedit : public QWidget
{
Q_OBJECT
public:
	Textedit();
	~Textedit();
    QPushButton *button = nullptr;
    QString documentTitle();
    bool isEdited() {return doc->isModified();};
    QUrl Url() {return doc->url();};
    bool isUndoAvailable(){return canUndo;};
    bool isRedoAvailable(){return canRedo;};
    bool isCopyAvailable(){return canCopy;};
    bool openfile(QUrl fileurl);
    void save();
    void saveas();
    void find();
    void undo();
    void redo();
    void copy();
    void cut();
    void paste();
    
private:
    KTextEditor::Editor *editor;
    KTextEditor::Document *doc;
    KTextEditor::View *view;
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
    void undoAvailable(bool available);
    void redoAvailable(bool available);
    void copyAvailable(bool available);
};

#endif // TEXTEDIT_HPP
