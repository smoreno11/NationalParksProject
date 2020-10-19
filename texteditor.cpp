#include "texteditor.h"
#include "ui_texteditor.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

texteditor::texteditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::texteditor)
{
    ui->setupUi(this);
}

texteditor::~texteditor()
{
    delete ui;
}

void texteditor::on_actionNew_triggered()
{
    mFileName = "";
    ui->editContactInfo->setPlainText("");
}

void texteditor::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a file.");

    if(!file.isEmpty())
    {
        QFile sFile(file);

        if(sFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFileName = file;

            QTextStream in(&sFile);
            QString text = in.readAll();

            ui->editContactInfo->setPlainText(text);

            sFile.close();
        }
    }
}

void texteditor::on_actionSave_triggered()
{
    QFile sFile(mFileName);

    if(!sFile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Save Failed", "Please specify a file name before saving.");
    }

    else
    {
        QTextStream out(&sFile);

        out << ui->editContactInfo->toPlainText();

        sFile.flush();
        sFile.close();
    }
}

void texteditor::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Save a file.");

    if(!file.isEmpty())
    {
        mFileName = file;

        on_actionSave_triggered();
    }
}

void texteditor::on_actionCut_triggered()
{
    ui->editContactInfo->cut();
}

void texteditor::on_actionCopy_triggered()
{
    ui->editContactInfo->copy();
}

void texteditor::on_actionPaste_triggered()
{
    ui->editContactInfo->paste();
}

void texteditor::on_actionUndo_triggered()
{
    ui->editContactInfo->undo();
}

void texteditor::on_actionRedo_triggered()
{
    ui->editContactInfo->redo();
}
