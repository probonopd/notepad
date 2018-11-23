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
#include "textedit.hpp"

Textedit::Textedit(QWidget *parent)
  : QMainWindow::QMainWindow(parent)
{
    textedit = new QPlainTextEdit(this);
    connect(textedit, &QPlainTextEdit::textChanged, this, &Textedit::onchange);
    connect(textedit, &QPlainTextEdit::undoAvailable, this, &Textedit::setUndo);
    connect(textedit, &QPlainTextEdit::redoAvailable, this, &Textedit::setRedo);
    connect(textedit, &QPlainTextEdit::copyAvailable, this, &Textedit::setCopy);
    connect(textedit, &QPlainTextEdit::undoAvailable, this, &Textedit::undoAvailable);
    connect(textedit, &QPlainTextEdit::redoAvailable, this, &Textedit::redoAvailable);
    connect(textedit, &QPlainTextEdit::copyAvailable, this, &Textedit::copyAvailable);
    textedit->setDocumentTitle(tr("new file"));
    setCentralWidget(textedit);
    QTimer::singleShot(0, textedit, SLOT(setFocus()));
}
bool Textedit::openfile(QString fileurl)
{
    url = fileurl;
    QFile file(url);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
        QTextStream stream(&file);
        textedit->setPlainText(stream.readAll());
        file.close();
        textedit->setDocumentTitle(url.mid(url.lastIndexOf('/')+1));
        edited = false;
        return true;
     }
     else 
     {
         qDebug() << tr("Failed to open file ") << url;
         return false;
     }
}
QString Textedit::documentTitle()
{
    return textedit->documentTitle();
}
void Textedit::saveclick()
{
    if(url.isEmpty()) saveas();
    else save();
}
void Textedit::saveas()
{
    QString a = tr("Save file ")+documentTitle();
    url=QFileDialog::getSaveFileName(this, a, QString(), tr("All files(*);;Text file(*.txt)"));
    save();
}
void Textedit::save()
{
    QFile file(url);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            QTextStream stream(&file);
            stream<<textedit->toPlainText();
            file.close();
            edited = false;
            textedit->setDocumentTitle(url.mid(url.lastIndexOf('/')+1));
            emit tabtextchange(this,  documentTitle(), false);
            if (button != nullptr) 
            {
                disconnect(button, &QPushButton::clicked, this, &Textedit::saveclick);
                delete button;
                button = nullptr;
            }
    }
    else qDebug() << tr("Failed to save file ") << url;
}
void Textedit::printClick()
{
    QPrinter printer;
    printer.setDocName(documentTitle());
    QPrintPreviewDialog printDialog(&printer);
    connect(&printDialog, &QPrintPreviewDialog::paintRequested, this, &Textedit::paintOnPrinter);
    printDialog.exec();
}
void Textedit::openFindBar()
{
    if (findBar == nullptr)
    {
        findBar = new FindBar();
        setStatusBar(findBar);
        connect(findBar, &FindBar::find, this, &Textedit::find);
        connect(findBar, &FindBar::closeClicked, this, &Textedit::closeFindBar);
        findBar->setText(findText);
    }
    else QTimer::singleShot(0, findBar, SLOT(setFocus()));
}
void Textedit::closeFindBar()
{
    findText = findBar->text();
    find("");
    QTimer::singleShot(0, [this]{delete findBar, findBar = nullptr;});
}
void Textedit::find(QString string)
{
    int pos = 0;
    QList<QTextEdit::ExtraSelection> list;
    for(QTextCursor cursor = textedit->document()->find(string, pos);cursor.hasSelection();cursor = textedit->document()->find(string, pos))
    {
        QTextEdit::ExtraSelection selection;
        selection.cursor = cursor;
        QTextCharFormat format;
        format.setBackground(QBrush(QColor(0xff7e8f48)));
        selection.format = format;
        list.append(selection);
        pos = cursor.position();
    }
    textedit->setExtraSelections(list);
}
void Textedit::onchange()
{
        edited = true;
        emit tabtextchange(this,  documentTitle(), true);
}
void Textedit::setUndo(bool available)
{
    canUndo=available;
}
void Textedit::setRedo(bool available)
{
    canRedo=available;
}
void Textedit::setCopy(bool available)
{
    canCopy=available;
}
void Textedit::paintOnPrinter(QPrinter *printer)
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
Textedit::~Textedit()
{
    if (button != nullptr) delete button;
    delete textedit;
}
