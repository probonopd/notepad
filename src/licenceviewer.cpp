#include "licenceviewer.hpp"

LicenceViewer::LicenceViewer(QWidget *parent)
:QDialog::QDialog(parent),
buttons(QDialogButtonBox::Close, this)
{
    #ifdef DEBUG
    QFile file(qApp.applicationDirPath()+"/../../LICENSE")
    #else
    QFile file(QStandardPaths::locate(QStandardPaths::AppDataLocation, "LICENSE",QStandardPaths::LocateFile));
    #endif
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        textView.setPlainText(stream.readAll());
        file.close();
    }
    else 
    {
        qDebug() << tr("Failed to open licence");
        textView.setPlainText(tr("Failed to open licence"));
    }
    layout.addWidget(&textView);
    connect(&buttons, &QDialogButtonBox::rejected,this, &QDialog::reject);
    layout.addWidget(&buttons);
    setLayout(&layout);
}
LicenceViewer::~LicenceViewer()
{
    
}
