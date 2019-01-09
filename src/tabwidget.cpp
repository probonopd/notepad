/*
notepad - Simple text editor with tabs
Copyright (C) 2018-2019  256Michael

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

TabWidget::TabWidget(QWidget *parent, QFont *font)
  : QTabWidget::QTabWidget(parent)
{
    setAcceptDrops(true);
    tabBar = new TabBar(this);
    setTabBar(tabBar);
    connect(this, &QTabWidget::tabCloseRequested, this, &TabWidget::closetab); 
    connect(this, &QTabWidget::currentChanged, this, &TabWidget::onCurrentChange);
    connect(tabBar, &TabBar::tabDragOut, this, &TabWidget::detachTab);
    setTabsClosable(true);
	setMovable(true);
    setDocumentMode(true);
    setFont(font);
    newFileCreate();
}
TabWidget::~TabWidget()
{
    if (button != nullptr)
        delete button, menu;
    delete tabBar;
}
 void TabWidget::openFiles(QStringList files)
{
    NotepadTab *w;
    NotepadTab *d = (NotepadTab*)currentWidget();
    for(int i = 0; i<files.count(); i++)
    {
        bool alreadyOpen = false;
        for(int j = 0; j<count(); j++)
        {
            w = (NotepadTab*)widget(j);
            if(w->Url() == files.at(i)) {
                alreadyOpen = true;
                break;
            }
        }
        if(!alreadyOpen)
        {
            w = new NotepadTab(this);
            if(w->openfile(files.at(i)))
            {
                addTab(w,w->documentTitle());
                connect(w, &NotepadTab::tabtextchange, this, &TabWidget::changetabname);
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
        NotepadTab *b = (NotepadTab*)currentWidget();
        if (b != d && b->Url().isEmpty() && !b->isEdited()) delete b;
        setCurrentWidget(d);
        emit currentTextChanged(d->documentTitle());
    }
}
void TabWidget::newFileCreate()
{
    NotepadTab *w = new NotepadTab(this);
    addTab(w,tr("new file"));
    connect(w, &NotepadTab::tabtextchange, this, &TabWidget::changetabname);
    setCurrentWidget(w);
    if (font != nullptr) w->setFont(*font);
}
void TabWidget::openFilesClicked()
{
    QStringList files = QFileDialog::getOpenFileNames(
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
    NotepadTab *w = (NotepadTab*) currentWidget();
    w->saveclick();
}
void TabWidget::saveas()
{
    NotepadTab *w = (NotepadTab*) currentWidget();
    w->saveas();
}
void TabWidget::saveAll()
{
    for(int i =0; i<count(); i++) 
    {
        NotepadTab *w = (NotepadTab*) widget(i);
        w->saveclick();
    }
}
void TabWidget::saveSession()
{
    QFile file(qApp->applicationDirPath()+"/session");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        NotepadTab *w;
        for(int i =0; i<count(); i++) 
        {
            w = (NotepadTab*) widget(i);
            stream << w->Url();
        }
        file.close();
    }
}
void TabWidget::openSession() {
    QFile file(qApp->applicationDirPath()+"/session");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QStringList files;
        while (!stream.atEnd()) {
            QString file = stream.readLine();
            files.append(file);
        }
        openFiles(files);
    }
}
void TabWidget::print()
{
    NotepadTab *w = (NotepadTab*) currentWidget();
    w->printClick();
}
void TabWidget::undo()
{
    NotepadTab *w = (NotepadTab*) currentWidget();
    w->undo();
}
void TabWidget::redo()
{
    NotepadTab *w = (NotepadTab*) currentWidget();
    w->redo();
}
void TabWidget::cut()
{
    NotepadTab *w = (NotepadTab*) currentWidget();
    w->cut();
}
void TabWidget::copy()
{
    NotepadTab *w = (NotepadTab*) currentWidget();
    w->copy();
}
void TabWidget::paste()
{
    NotepadTab *w = (NotepadTab*) currentWidget();
    w->paste();
}
void TabWidget::setFont(QFont *newFont)
{
    font = newFont;
    NotepadTab *w;
    for(int i =0; i<count(); i++) 
    {
        w = (NotepadTab*) widget(i);
        w->setFont(*font);
    }
}
void TabWidget::find()
{
    NotepadTab *w = (NotepadTab*) currentWidget();
    w->openFindBar();
}
void TabWidget::removeTab(int index)
{
    NotepadTab *w = (NotepadTab*) widget(index);
    delete w;
}
void TabWidget::setMenu(QMenu *menu)
{
	if (menu !=  nullptr) {
        this->menu = menu;
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

            delete this->menu;
            this->menu=nullptr;
        }
	}
}
void TabWidget::closetab(int index)
{
    NotepadTab* b = (NotepadTab*) widget(index);
    if (b->isEdited()) 
    {
        QMessageBox *message = new QMessageBox(QMessageBox::Warning, tr("Closing tab"), tr("Would you like to save changes in file")+" \"" +b->documentTitle()+"\" ?",QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel ); 
        int result = message->exec();
        delete message;
        if (result == 0x00000800)
        {
            b->saveclick();
            if (count() == 1) newFileCreate();
            removeTab(index);
        }
        else if (result == 0x00800000)
        {
            if (count() == 1) newFileCreate();
            removeTab(index);
        }
    }
    else 
    {
        if (count() == 1) newFileCreate();
        removeTab(index);
    }
}
void TabWidget::changetabname(NotepadTab* tab,  QString newtext, bool edited)
{
    setTabText(indexOf(tab),  newtext);
    if (indexOf(tab) == currentIndex())
    {
        if (edited) newtext = "*"+newtext;
        emit currentTextChanged(newtext);
            
    }
    if (edited)
    {
        if (tab->button == nullptr)
        {
            tab->button = new QPushButton(QIcon::fromTheme("document-save"), "", this);
            tab->button->setFlat(true);
            connect(tab->button, &QPushButton::clicked, tab, &NotepadTab::saveclick);
            tabBar->setTabButton(indexOf(tab), QTabBar::LeftSide, tab->button);
        }
    }
    else {
        tabBar()->setTabButton(indexOf(textedit), QTabBar::LeftSide, 0);
        if(button!=nullptr){
            delete textedit->button;
            textedit->button=nullptr;
        }
    }
}
void TabWidget::onCurrentChange()
{
    NotepadTab* w = (NotepadTab*) currentWidget(); 
    disconnect(0, 0, this, SLOT(undoAvailable));
    connect(w, &NotepadTab::undoAvailable, this, &TabWidget::undoAvailable);
    emit undoAvailable(w->isUndoAvailable());
    disconnect(0, 0, this, SLOT(redoAvailable));
    connect(w, &NotepadTab::redoAvailable, this, &TabWidget::redoAvailable);
    emit undoAvailable(w->isRedoAvailable());
    disconnect(0, 0, this, SLOT(copyAvailable));
    connect(w, &NotepadTab::copyAvailable, this, &TabWidget::copyAvailable);
    emit copyAvailable(w->isCopyAvailable());
    emit currentTextChanged(w->documentTitle());
}
void TabWidget::detachTab()
{
    QWidget *parentWidget = (QWidget*) parent();
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    NotepadTab *textedit = (NotepadTab*) currentWidget();
    stream<<*textedit;
    qDebug()<<array;
    if(count()!=1) delete textedit;
    else parentWidget->hide();
    QMimeData *data = new QMimeData();
    data->setData("application/x-notepad-textedit", array);
    QDrag *drag = new QDrag(this);
    drag->setMimeData(data);
    if(drag->exec()==Qt::IgnoreAction)
    {
        if(parentWidget->isHidden())
        {
            parentWidget->show();
        }
        delete drag;
    }
    else if(parentWidget->isHidden())
    {
        parentWidget->close();
    }
}
void TabWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-notepad-textedit"))
    {
        event->acceptProposedAction();
    }
}
void TabWidget::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-notepad-textedit"))
    {
        event->acceptProposedAction();
        NotepadTab *w = new NotepadTab(this);
        QByteArray array=event->mimeData()->data("application/x-notepad-textedit");
        qDebug()<<array;
        QDataStream stream(&array,QIODevice::ReadOnly);
//         QString string, string2;
//         bool edited;
//         stream>>string>>string2>>edited;
//         qDebug()<<string<<string2<<edited;
        stream>>*w;
        qDebug()<<w->documentTitle();
        addTab(w,w->documentTitle());
        connect(w, &NotepadTab::tabtextchange, this, &TabWidget::changetabname);
        setCurrentWidget(w);
        if (font != nullptr) w->setFont(*font);
        if (w->isEdited()) changetabname(w,  w->documentTitle(), true);
    }
}
void TabWidget::closeEvent(QCloseEvent *event)
{
    bool edited = false;
    for (int i = 0;i<count() && !edited;i++)
    {
        NotepadTab *w = (NotepadTab*) widget(i);
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
