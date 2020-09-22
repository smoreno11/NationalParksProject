#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "adminscreen.h"
#include "mainwindow.h"
#include "customer.h"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

private slots:
    void on_loginButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AdminLogin *ui;
};

#endif // ADMINLOGIN_H
