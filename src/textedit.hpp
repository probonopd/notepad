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

class Textedit : public QPlainTextEdit
{
Q_OBJECT
public:
	Textedit();
	~Textedit();
    bool openfile(QString fileurl);
    void saveclick();
    void saveas();
    void printClick();
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
    void paintOnPrinter(QPrinter *printer);
signals:
    void tabtextchange(Textedit *textedit,  QString newtext,  bool edited);
};

#endif // TEXTEDIT_HPP
