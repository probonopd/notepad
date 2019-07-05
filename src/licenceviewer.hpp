#pragma once
#include <QDialog>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QStandardPaths>
#include <QApplication>
#include <QTextStream>
#include <QDebug>
#include <QDialogButtonBox>

class LicenceViewer
:public QDialog
{
Q_OBJECT
public:
    LicenceViewer(QWidget *parent = nullptr);
    ~LicenceViewer();
private:
    QPlainTextEdit textView;
    QVBoxLayout layout;
    QDialogButtonBox buttons;
};
