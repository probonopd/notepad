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

#include <QPlainTextEdit>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QPushButton>
#include <QPrintPreviewDialog>
#include <QPrinter>
#include <QPainter>
#include <QMainWindow>
#include <cmath>
#include <QTimer>
#include <QString>

#include "findbar.hpp"

class NotepadCard : public QMainWindow
{
Q_OBJECT
public:
	NotepadCard(QWidget *parent=nullptr);
    NotepadCard(const NotepadCard &textedit);
	~NotepadCard();
    bool openfile(QString fileurl);
    QString documentTitle() const;
    void saveclick();
    void saveas();
    void printClick();
    void openFindBar();
    void find(QString string);
    bool isEdited() const {return edited;};
    QString Url() const {return url;};
    QPushButton *button = nullptr;
    bool isUndoAvailable(){return canUndo;};
    bool isRedoAvailable(){return canRedo;};
    bool isCopyAvailable(){return canCopy;}; 
    void undo() {textedit->undo();};
    void redo() {textedit->redo();};
    void paste() {textedit->paste();};
    void copy() {textedit->copy();};
    void cut() {textedit->cut();};
    friend QDataStream & operator<< (QDataStream &stream, const NotepadCard &notepadCard);
    friend QDataStream & operator>> (QDataStream &stream, NotepadCard &notepadCard);
private:
    QPlainTextEdit *textedit;
    QString title;
    FindBar *findBar = nullptr;
    QString findText;
    QString url;
    bool edited = false;
    void save();
    bool canUndo=false;
    bool canRedo=false;
    bool canCopy=false;
private slots:
    void closeFindBar();
    void onchange();
    void setUndo(bool available);
    void setRedo(bool available);
    void setCopy(bool available);
    void paintOnPrinter(QPrinter *printer);
signals:
    void tabtextchange(NotepadCard *textedit,  QString newtext,  bool edited);
    void undoAvailable(bool value);
    void redoAvailable(bool value);
    void copyAvailable(bool value);
};

Q_DECLARE_METATYPE(NotepadCard)

#endif // TEXTEDIT_HPP
