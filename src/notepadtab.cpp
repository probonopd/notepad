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

<<<<<<< HEAD:src/notepadtab.cpp
#include "notepadtab.hpp"

NotepadTab::NotepadTab(QWidget *parent)
  : QMainWindow::QMainWindow(parent),
  textedit(this)
{
    connect(&textedit, &QPlainTextEdit::textChanged, this, &Textedit::onchange);
    connect(&textedit, &QPlainTextEdit::undoAvailable, this, &Textedit::setUndo);
    connect(&textedit, &QPlainTextEdit::redoAvailable, this, &Textedit::setRedo);
    connect(&textedit, &QPlainTextEdit::copyAvailable, this, &Textedit::setCopy);
    connect(&textedit, &QPlainTextEdit::undoAvailable, this, &Textedit::undoAvailable);
    connect(&textedit, &QPlainTextEdit::redoAvailable, this, &Textedit::redoAvailable);
    connect(&textedit, &QPlainTextEdit::copyAvailable, this, &Textedit::copyAvailable);
    title=tr("new file");
    setCentralWidget(&textedit);
    QTimer::singleShot(0, &textedit, SLOT(setFocus()));
}
NotepadTab::NotepadTab(const NotepadTab &notepadTab)
  : NotepadTab::NotepadTab((QWidget*)notepadTab.parent())
{
    textedit->setDocumentTitle(notepadTab.documentTitle());
    url=notepadTab.url;
    edited=notepadTab.edited;
    textedit->setPlainText(notepadTab.textedit->toPlainText());
    findText=notepadTab.findText;
    if(notepadTab.findBar != nullptr) openFindBar();
}
bool NotepadTab::openfile(QString fileurl)
{
    url = fileurl;
    QFile file(url);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
        QTextStream stream(&file);
        textedit.setPlainText(stream.readAll());
        file.close();
        title=url.mid(url.lastIndexOf('/')+1);
        edited = false;
        return true;
     }
     else 
     {
         qDebug() << tr("Failed to open file ") << url;
         return false;
     }
}
QString NotepadTab::documentTitle() const
{
    return title;
}
void NotepadTab::saveclick()
{
    if(url.isEmpty()) saveas();
    else save();
}
void NotepadTab::saveas()
{
    QString a = tr("Save file ")+documentTitle();
    url=QFileDialog::getSaveFileName(this, a, QString(), tr("All files(*);;Text file(*.txt)"));
    save();
}
void NotepadTab::save()
{
    QFile file(url);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            QTextStream stream(&file);
            stream<<textedit.toPlainText();
            file.close();
            edited = false;
            title=url.mid(url.lastIndexOf('/')+1);
            emit tabtextchange(this,  documentTitle(), false);
    }
    else qDebug() << tr("Failed to save file ") << url;
}
void NotepadTab::printClick()
{
    QPrinter printer;
    printer.setDocName(documentTitle());
    QPrintPreviewDialog printDialog(&printer);
    connect(&printDialog, &QPrintPreviewDialog::paintRequested, this, &NotepadTab::paintOnPrinter);
    printDialog.exec();
}
void NotepadTab::openFindBar()
{
    if (findBar == nullptr)
    {
        findBar = new FindBar();
        setStatusBar(findBar);
        connect(findBar, &FindBar::find, this, &NotepadTab::find);
        connect(findBar, &FindBar::closeClicked, this, &NotepadTab::closeFindBar);
        findBar->setText(findText);
    }
    else QTimer::singleShot(0, findBar, SLOT(setFocus()));
}
void NotepadTab::closeFindBar()
{
    findText = findBar->text();
    find("");
    QTimer::singleShot(0, [this]{delete findBar, findBar = nullptr;});
}
void NotepadTab::find(QString string)
{
    int pos = 0;
    QList<QTextEdit::ExtraSelection> list;
    for(QTextCursor cursor = textedit.document()->find(string, pos);cursor.hasSelection();cursor = textedit.document()->find(string, pos))
    {
        QTextEdit::ExtraSelection selection;
        selection.cursor = cursor;
        QTextCharFormat format;
        format.setBackground(this->palette().brush(QPalette::Text));
        format.setForeground(this->palette().brush(QPalette::Window));
        selection.format = format;
        list.append(selection);
        pos = cursor.position();
    }
    textedit.setExtraSelections(list);
}
void NotepadTab::onchange()
{
        edited = true;
        emit tabtextchange(this,  documentTitle(), true);
}
void NotepadTab::setUndo(bool available)
{
    canUndo=available;
}
void NotepadTab::setRedo(bool available)
{
    canRedo=available;
}
void NotepadTab::setCopy(bool available)
{
    canCopy=available;
}
void NotepadTab::paintOnPrinter(QPrinter *printer)
{
    QPainter painter(printer);
    painter.setPen(Qt::black);
    painter.setFont(font());
    QString text = textedit.toPlainText();
    QTextStream stream(&text);
    int linesOnPage = floor(printer->pageRect(QPrinter::Point).height()/(font().pointSizeF()+1.7));
    bool notAllPainted = true;
    bool firstPage = true;
    while(notAllPainted)
    {
        QString page, line;
        for (int i = 0; i<linesOnPage&&notAllPainted; i++)
        {
            notAllPainted = stream.readLineInto(&line);
            page += line+"\n";
        }     
        if (!firstPage)
            printer->newPage();
        else
            firstPage = false;
        painter.drawText(printer->pageRect(QPrinter::DevicePixel), page);
    }
}
NotepadTab::~NotepadTab()
{
    emit tabtextchange(this,  documentTitle(), false);
    if (findBar != nullptr) delete findBar;
}
QDataStream & operator<< (QDataStream &stream, const NotepadTab &notepadTab)
{
    return stream << notepadTab.documentTitle() << notepadTab.Url() << notepadTab.isEdited() << notepadTab.textedit->toPlainText()<<((notepadTab.findBar!=nullptr)?true:false)<< (notepadTab.findBar != nullptr?notepadTab.findBar->text():notepadTab.findText);
}
QDataStream & operator>> (QDataStream &stream, NotepadTab &notepadTab)
{
    QString text, findText;
    bool wasEdited,isFindBar;
    stream >> notepadTab.title >> notepadTab.url>> wasEdited>>text>>isFindBar>>findText;
    qDebug() << notepadTab.title << notepadTab.url<< wasEdited<<text<<isFindBar<<findText;
    qDebug()<<notepadTab.documentTitle();
    notepadTab.textedit->setPlainText(text);
    notepadTab.edited=wasEdited;
    notepadTab.findText = findText;
    if (isFindBar) notepadTab.openFindBar();
    return stream;
}
