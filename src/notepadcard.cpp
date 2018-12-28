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

#include "notepadcard.hpp"

NotepadCard::NotepadCard(QWidget *parent)
  : QMainWindow::QMainWindow(parent)
{
    textedit = new QPlainTextEdit(this);
    connect(textedit, &QPlainTextEdit::textChanged, this, &NotepadCard::onchange);
    connect(textedit, &QPlainTextEdit::undoAvailable, this, &NotepadCard::setUndo);
    connect(textedit, &QPlainTextEdit::redoAvailable, this, &NotepadCard::setRedo);
    connect(textedit, &QPlainTextEdit::copyAvailable, this, &NotepadCard::setCopy);
    connect(textedit, &QPlainTextEdit::undoAvailable, this, &NotepadCard::undoAvailable);
    connect(textedit, &QPlainTextEdit::redoAvailable, this, &NotepadCard::redoAvailable);
    connect(textedit, &QPlainTextEdit::copyAvailable, this, &NotepadCard::copyAvailable);
    title=tr("new file");
    setCentralWidget(textedit);
    QTimer::singleShot(0, textedit, SLOT(setFocus()));
}
NotepadCard::NotepadCard(const NotepadCard &notepadCard)
  : NotepadCard::NotepadCard((QWidget*)notepadCard.parent())
{
    textedit->setDocumentTitle(notepadCard.documentTitle());
    url=notepadCard.url;
    edited=notepadCard.edited;
    textedit->setPlainText(notepadCard.textedit->toPlainText());
    findText=notepadCard.findText;
    if(notepadCard.findBar != nullptr) openFindBar();
}
bool NotepadCard::openfile(QString fileurl)
{
    url = fileurl;
    QFile file(url);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
        QTextStream stream(&file);
        textedit->setPlainText(stream.readAll());
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
QString NotepadCard::documentTitle() const
{
    return title;
}
void NotepadCard::saveclick()
{
    if(url.isEmpty()) saveas();
    else save();
}
void NotepadCard::saveas()
{
    QString a = tr("Save file ")+documentTitle();
    url=QFileDialog::getSaveFileName(this, a, QString(), tr("All files(*);;Text file(*.txt)"));
    save();
}
void NotepadCard::save()
{
    QFile file(url);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            QTextStream stream(&file);
            stream<<textedit->toPlainText();
            file.close();
            edited = false;
            title=url.mid(url.lastIndexOf('/')+1);
            emit tabtextchange(this,  documentTitle(), false);
            if (button != nullptr) 
            {
                disconnect(button, &QPushButton::clicked, this, &NotepadCard::saveclick);
                delete button;
                button = nullptr;
            }
    }
    else qDebug() << tr("Failed to save file ") << url;
}
void NotepadCard::printClick()
{
    QPrinter printer;
    printer.setDocName(documentTitle());
    QPrintPreviewDialog printDialog(&printer);
    connect(&printDialog, &QPrintPreviewDialog::paintRequested, this, &NotepadCard::paintOnPrinter);
    printDialog.exec();
}
void NotepadCard::openFindBar()
{
    if (findBar == nullptr)
    {
        findBar = new FindBar();
        setStatusBar(findBar);
        connect(findBar, &FindBar::find, this, &NotepadCard::find);
        connect(findBar, &FindBar::closeClicked, this, &NotepadCard::closeFindBar);
        findBar->setText(findText);
    }
    else QTimer::singleShot(0, findBar, SLOT(setFocus()));
}
void NotepadCard::closeFindBar()
{
    findText = findBar->text();
    find("");
    QTimer::singleShot(0, [this]{delete findBar, findBar = nullptr;});
}
void NotepadCard::find(QString string)
{
    int pos = 0;
    QList<QTextEdit::ExtraSelection> list;
    for(QTextCursor cursor = textedit->document()->find(string, pos);cursor.hasSelection();cursor = textedit->document()->find(string, pos))
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
    textedit->setExtraSelections(list);
}
void NotepadCard::onchange()
{
        edited = true;
        emit tabtextchange(this,  documentTitle(), true);
}
void NotepadCard::setUndo(bool available)
{
    canUndo=available;
}
void NotepadCard::setRedo(bool available)
{
    canRedo=available;
}
void NotepadCard::setCopy(bool available)
{
    canCopy=available;
}
void NotepadCard::paintOnPrinter(QPrinter *printer)
{
    QPainter painter(printer);
    painter.setPen(Qt::black);
    painter.setFont(font());
    QString text = textedit->toPlainText();
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
NotepadCard::~NotepadCard()
{
    if (button != nullptr) delete button;
    if (findBar != nullptr) delete findBar;
    delete textedit;
}
QDataStream & operator<< (QDataStream &stream, const NotepadCard &notepadCard)
{
    return stream << notepadCard.documentTitle() << notepadCard.Url() << notepadCard.isEdited() << notepadCard.textedit->toPlainText()<<((notepadCard.findBar!=nullptr)?true:false)<< (notepadCard.findBar != nullptr?notepadCard.findBar->text():notepadCard.findText);
}
QDataStream & operator>> (QDataStream &stream, NotepadCard &notepadCard)
{
    QString text, findText;
    bool wasEdited,isFindBar;
    stream >> notepadCard.title >> notepadCard.url>> notepadCard.edited>>text>>isFindBar>>findText;
    qDebug() << notepadCard.title << notepadCard.url<< wasEdited<<text<<isFindBar<<findText;
    qDebug()<<notepadCard.documentTitle();
    notepadCard.textedit->setPlainText(text);
    notepadCard.edited=wasEdited;
    notepadCard.findText = findText;
    if (isFindBar) notepadCard.openFindBar();
    return stream;
}
