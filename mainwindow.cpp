#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nationalparks.h"
#include "customer.h"
#include "adminlogin.h"
#include "parksdisplay.h"

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


//      NationalParks customer(query);
//      QListWidgetItem *item = new QListWidgetItem;
//     QListWidgetItem *items = new QListWidgetItem;
//      item->setText(customer.getNationalPark());
//      item->setData(Qt::UserRole, customer.getId());

//      ui->CustomerListWidget->addItem(item);
//      ui->CustomerListWidget->addItem(items);

void MainWindow::on_pushButton_clicked()
{
    AdminLogin go;

    go.setModal(true);
    go.exec();
}
