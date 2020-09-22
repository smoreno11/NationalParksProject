#include "adminlogin.h"
#include "ui_adminlogin.h"

AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_loginButton_clicked()
{
    // Program reads in person's username and password
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    // If username and password match Admin login
    if (username == "Admin" && password == "CPlusUs") {
      this->hide();
      AdminScreen go;
      go.setModal(true);
      go.exec();
//      customerpage.setModal(true);
//      customerpage.exec();
    }
    // If username and password do not match Admin login
    else {
      // Warning message
      QMessageBox::warning(this, "Login", "Username and Password are incorrect");
    }
}
