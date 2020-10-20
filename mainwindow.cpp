#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer.h"
#include "adminlogin.h"
#include "parksdisplay.h"
#include "helpdialog.h"
#include "contactus.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_parkDisplay_clicked()
{
    ParksDisplay go;

    go.setModal(true);
    go.exec();

}

void MainWindow::on_pushButton_clicked()
{
    AdminLogin go;

    go.setModal(true);
    go.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    helpDialog hDialog;

    hDialog.setModal(true);
    hDialog.exec();
}



void MainWindow::on_pushButton_3_clicked()
{
    ContactUs go;
    go.setModal(true);
    go.exec();
}
