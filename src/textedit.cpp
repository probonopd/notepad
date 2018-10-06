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

Textedit::Textedit()
{
    editor = KTextEditor::Editor::instance();
    // create a new document
    doc = editor->createDocument(this);
    // create a widget to display the document
    QWidget *widget = new QWidget();
    view = doc->createView(widget);
    
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(view);
    
    setLayout(mainLayout);
    connect(doc, &KTextEditor::Document::textChanged, this, &Textedit::onchange);
//     connect(this, &QPlainTextEdit::undoAvailable, this, &Textedit::setUndo);
//     connect(this, &QPlainTextEdit::redoAvailable, this, &Textedit::setRedo);
//     connect(this, &QPlainTextEdit::copyAvailable, this, &Textedit::setCopy);
}
QString Textedit::documentTitle()
{
    return doc->documentName();
}
bool Textedit::openfile(QUrl fileurl)
{
    return doc->openUrl(fileurl);
}
void Textedit::save()
{
    if (doc->documentSave()) emit tabtextchange(this,  documentTitle(), false);
}
void Textedit::saveas()
{
    if(doc->documentSaveAs())emit tabtextchange(this,  documentTitle(), false);
}
void Textedit::find()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Find"),
                                         tr("Find:"), QLineEdit::Normal,
                                         "Find", &ok);
    if (ok && !text.isEmpty())
    {
        
    }
}
void Textedit::undo()
{
    
}

void Textedit::redo()
{
}

void Textedit::copy()
{
}

void Textedit::paste()
{
}

void Textedit::cut()
{
}

void Textedit::onchange()
{
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
Textedit::~Textedit()
{
    if (button != nullptr) delete button;
}
