#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
class helpDialog;
}

class helpDialog : public QDialog
{
    Q_OBJECT

public:

    // default constructer: setting up the help button for the costumer
    explicit helpDialog(QWidget *parent = nullptr);
    
    // default destructor
    ~helpDialog();

private:
    Ui::helpDialog *ui;
};

#endif // HELPDIALOG_H
