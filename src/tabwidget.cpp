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
#include "tabwidget.hpp"

#include <QApplication>

TabWidget::TabWidget(QFont *font)
{
    connect(this, &QTabWidget::tabCloseRequested, this, &TabWidget::closetab); 
    connect(this, &QTabWidget::currentChanged, this, &TabWidget::onCurrentChange);
    setTabsClosable(true);
	setMovable(true);
    setDocumentMode(true);
    setFont(font);
    newFileCreate();
}
TabWidget::~TabWidget()
{
}
 void TabWidget::openFiles(QList<QUrl> files)
{
    Textedit *w;
    Textedit *d = (Textedit*)currentWidget();
    for(int i = 0; i<files.count(); i++)
    {
        bool alreadyOpen = false;
        for(int j = 0; j<count(); j++)
        {
            w = (Textedit*)widget(j);
            if(w->Url() == files.at(i)) {
                alreadyOpen = true;
                break;
            }
        }
        if(!alreadyOpen)
        {
            w = new Textedit();
            if(w->openfile(files.at(i)))
            {
                addTab(w,files.at(i).toString().mid(files.at(i).toString().lastIndexOf('/')+1));
                connect(w, &Textedit::tabtextchange, this, &TabWidget::changetabname);
                if (font != nullptr) w->setFont(*font);
                d = w;
            }
            else{
                delete w;
                w = d; 
            }
        }
    }
    if(count() == 0) newFileCreate();
    if(files.count()!=0)
    {
        Textedit *b = (Textedit*)currentWidget();
        if (b != d && b->Url().isEmpty() && !b->isEdited()) delete b;
        setCurrentWidget(d);
        emit currentTextChanged(d->documentTitle());
    }
}
void TabWidget::newFileCreate()
{
    Textedit *w = new Textedit();
    addTab(w, w->documentTitle());
    connect(w, &Textedit::tabtextchange, this, &TabWidget::changetabname);
    setCurrentWidget(w);
    if (font != nullptr) w->setFont(*font);
}
void TabWidget::openFilesClicked()
{
    QList<QUrl> files = QFileDialog::getOpenFileUrls(
        this,
        tr("Select files to open"),
        QString(),
        tr("All files(*);;Text file(*.txt)"));
	if (!files.empty())
    {
		openFiles(files);
	}
}
void TabWidget::saveclick()
{
    Textedit *w = (Textedit*) currentWidget();
    w->save();
}
void TabWidget::saveas()
{
    Textedit *w = (Textedit*) currentWidget();
    w->saveas();
}
void TabWidget::saveAll()
{
    for(int i =0; i<count(); i++) 
    {
        Textedit *w = (Textedit*) widget(i);
        w->save();
    }
}
void TabWidget::saveSession()
{
    QFile file(qApp->applicationDirPath()+"/session");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        Textedit *w;
        for(int i =0; i<count(); i++) 
        {
            w = (Textedit*) widget(i);
            stream << w->Url().toString();
        }
        file.close();
    }
}
void TabWidget::openSession() {
    QFile file(qApp->applicationDirPath()+"/session");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QList<QUrl> files;
        while (!stream.atEnd()) {
            QUrl file(stream.readLine());
            files.append(file);
        }
       openFiles(files);
    }
}
void TabWidget::undo()
{
    Textedit *w = (Textedit*) currentWidget();
    w->undo();
}
void TabWidget::redo()
{
    Textedit *w = (Textedit*) currentWidget();
    w->redo();
}
void TabWidget::cut()
{
    Textedit *w = (Textedit*) currentWidget();
    w->cut();
}
void TabWidget::copy()
{
    Textedit *w = (Textedit*) currentWidget();
    w->copy();
}
void TabWidget::paste()
{
    Textedit *w = (Textedit*) currentWidget();
    w->paste();
}
void TabWidget::setFont(QFont *newFont)
{
    font = newFont;
    Textedit *w;
    for(int i =0; i<count(); i++) 
    {
        w = (Textedit*) widget(i);
        w->setFont(*font);
    }
}
void TabWidget::setMenu(QMenu *menu)
{
	if (menu !=  nullptr) {
        	button = new QPushButton(tr("Menu"),this);
        	button->setMenu(menu);
        	setCornerWidget(button, Qt::TopLeftCorner);
        	button->show();
    	}
	else{
            setCornerWidget(0, Qt::TopLeftCorner);
            if (button != nullptr)
            {
                delete button;
                button = nullptr;
            }
	}
}
void TabWidget::closetab(int index)
{
    Textedit* b = (Textedit*) widget(index);
    if (b->isEdited()) 
    {
        QMessageBox *message = new QMessageBox(QMessageBox::Warning, tr("Closing tab"), tr("Would you like to save changes in file")+" \"" +tabText(index).remove("&")+"\" ?",QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel ); 
        int result = message->exec();
        delete message;
        if (result == 0x00000800)
        {
            b->save();
            if (count() == 1) newFileCreate();
            removeTab(index);
            delete b;
        }
        else if (result == 0x00800000)
        {
            if (count() == 1) newFileCreate();
            removeTab(index);
            delete b;
        }
    }
    else 
    {
        if (count() == 1) newFileCreate();
        removeTab(index);
        delete b;
    }
}
void TabWidget::changetabname(Textedit* textedit,  QString newtext, bool edited)
{
    setTabText(indexOf(textedit),  newtext);
    if (indexOf(textedit) == currentIndex())
    {
        if (edited) newtext = "*"+newtext;
        emit currentTextChanged(newtext);
            
    }
    if (edited)
    {
        if (textedit->button == nullptr)
        {
            textedit->button = new QPushButton(QIcon::fromTheme("document-save"), "", this);
            textedit->button->setFlat(true);
            connect(textedit->button, &QPushButton::clicked, textedit, &Textedit::save);
            tabBar()->setTabButton(indexOf(textedit), QTabBar::LeftSide, textedit->button);
        }
    }
    else{
        tabBar()->setTabButton(indexOf(textedit), QTabBar::LeftSide, 0);
        delete textedit->button;
        textedit->button = nullptr;
    }
}
void TabWidget::onCurrentChange()
{
    Textedit* w = (Textedit*) currentWidget(); 
    disconnect(0, 0, this, SLOT(undoAvailable));
    connect(w, &Textedit::undoAvailable, this, &TabWidget::undoAvailable);
    emit undoAvailable(w->isUndoAvailable());
    disconnect(0, 0, this, SLOT(redoAvailable));
    connect(w, &Textedit::redoAvailable, this, &TabWidget::redoAvailable);
    emit undoAvailable(w->isRedoAvailable());
    disconnect(0, 0, this, SLOT(copyAvailable));
    connect(w, &Textedit::copyAvailable, this, &TabWidget::copyAvailable);
    emit copyAvailable(w->isCopyAvailable());
    emit currentTextChanged(w->documentTitle());
}
void TabWidget::closeEvent(QCloseEvent *event)
{
    bool edited = false;
    for (int i = 0;i<count() && !edited;i++)
    {
        Textedit *w = (Textedit*) widget(i);
        if (w->isEdited()) edited = true;
    }
    if (edited)
    {
        QMessageBox *message = new QMessageBox(QMessageBox::Warning, tr("Closing notepad"), tr("Would you like to safe chages in files?"),QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, this); 
        int result = message->exec();
        delete message;
        if (result == 0x00000800)
        {
            saveAll();
            event->accept();
        }
        else if (result == 0x00800000) event->accept();
        else event->ignore();
    }
    else event->accept();
}
